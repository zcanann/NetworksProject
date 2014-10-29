#include <Timer.h>
#include "command.h"
#include "packet.h"
#include "neighbor.h"
#include "sendInfo.h"
#include "linkedstate.h"
#include "socket.h"

module Node
{
	uses interface Boot;						// Interface for booting
	uses interface SplitControl as AMControl;	// Interface for radio
	uses interface Receive;						// Interface for receiving packets
	uses interface SimpleSend as Sender;		// Interface for sending packets
	
	uses interface CommandHandler;		// Interface for processing commands
	uses interface PacketHandler;		// Interface for general packet processing
	uses interface NeighborDiscovery;	// Interface for discovering neighbors
	uses interface LinkStateRouting;	// Interface for link state routing
	uses interface TCP;					// Interface for TCP
	
	uses interface Random;
	uses interface Timer<TMilli> as FrequentUpdate;	// Timer events that happen frequently
	uses interface Timer<TMilli> as ModerateUpdate;	// Timer events that happen moderately
	uses interface Timer<TMilli> as SparseUpdate;	// Timer events that happen sparsely
	uses interface Timer<TMilli> as RareUpdate;		// Timer events that happen rarely
	
	uses interface Hashmap<uint16_t> as neighborTable;			// Stores immediate neighbors
	uses interface Hashmap<uint16_t> as sequenceTable;			// Stores sequence table data
	uses interface Hashmap<uint32_t> as routingTable;			// Stores routing table data
	uses interface Hashmap<socket_storage_t*> as TCPTablePTR;	// Stores [pointer to] TCP connection state struct
}

implementation
{
	
	uint8_t pingPacket[PACKET_MAX_PAYLOAD_SIZE8];
	uint8_t TCPPacket[PACKET_MAX_PAYLOAD_SIZE8];
	pack sendPackage;
	
	uint16_t SEQUENCE_NUMBER = 0;
	bool NeighborsChanged = FALSE;
	socket_storage_t TCPTable[TOTAL_PORTS];
	
	uint32_t PeriodFrequent;
	uint32_t PeriodModerate;
	uint32_t PeriodSparse;
	uint32_t PeriodRare;
	
	// Prototypes
	void makePack(pack *Package, uint16_t src, uint16_t dest, uint8_t TTL, uint8_t Protocol, uint16_t seq, uint8_t *payload, uint8_t length);
	
	//////////////////////////////////////////////////
	// INITIALIZATION
	//////////////////////////////////////////////////
	
	event void Boot.booted()
	{
		call AMControl.start();
		
		// Zero memory for all of the arrays that belong to this class
		memset(pingPacket, 0, sizeof(pingPacket));
		
		// Initialize all components
		call LinkStateRouting.initialize();
		call PacketHandler.initialize();
		call NeighborDiscovery.initialize();
		call TCP.initialize();
		
		// Initialize all update timer periods
		PeriodFrequent = (call Random.rand32() % 200) + 3999;
		PeriodModerate = (call Random.rand32() % 2000) + 19991;
		PeriodSparse = (call Random.rand32() % 20000) + 189999;
		PeriodRare = (call Random.rand32() % 40000) + 889999;
		
		call FrequentUpdate.startOneShot(PeriodFrequent);
		call ModerateUpdate.startOneShot(PeriodModerate);
		call SparseUpdate.startOneShot(PeriodSparse);
		call RareUpdate.startOneShot(PeriodRare);
		
		dbg("genDebug", "Booted\n");
	}
	
	event void AMControl.startDone(error_t err)
	{
		if(err == SUCCESS)
		{
			dbg("genDebug", "Radio On\n");
		}
		else
		{
			// Retry until successful
			call AMControl.start();
		}
	}

	event void AMControl.stopDone(error_t err) { }
	
	//////////////////////////////////////////////////
	// TIMER EVENTS
	//////////////////////////////////////////////////
	
	task void doFrequentEvents()
	{
		signal NeighborDiscovery.discoverNeighbors();
		
		// Restart timer
		call FrequentUpdate.startOneShot(PeriodFrequent);
	}
	
	task void doModerateEvents()
	{
		// Time out neighbors that have died
		call NeighborDiscovery.timeOutCheck();
		
		// Indicate changed link state faster if we know something is different
		if (NeighborsChanged)
		{
			NeighborsChanged = ! NeighborsChanged;
			call LinkStateRouting.shareLinkState();
		}
			
		// Restart timer
		call ModerateUpdate.startOneShot(PeriodModerate);
	}
	
	task void doSparseEvents()
	{
		// Calculate route to all nodes we have link states for
		call LinkStateRouting.calculateRoute();
		
		// Restart timer
		call SparseUpdate.startOneShot(PeriodSparse);
	}
	
	task void doRareEvents()
	{
		// Share link state regardless of detected neighbor changes to handle edge cases
		call LinkStateRouting.shareLinkState();
		
		// Age sequence table on occasion to handle a super rare edge case
		call PacketHandler.ageSequenceTable();
		
		// Restart timer
		call RareUpdate.startOneShot(PeriodRare);
	}
	
	// Events that need to fire frequently
	event void FrequentUpdate.fired()
	{
		post doFrequentEvents();
	}
	
	// Events that need to fire moderately
	event void ModerateUpdate.fired()
	{
		post doModerateEvents();
	}
	
	// Events that need to fire sparsely
	event void SparseUpdate.fired()
	{
		post doSparseEvents();
	}
	
	// Events that need to fire rarely
	event void RareUpdate.fired()
	{
		post doRareEvents();
	}
	
	//////////////////////////////////////////////////
	// CODE
	//////////////////////////////////////////////////
	
	event message_t* Receive.receive(message_t* msg, void* payload, uint8_t len)
	{
		pack* Packet;
		
		if(len == sizeof(pack))
		{
			Packet = (pack*)payload;
			
			// Always check for commands
			call CommandHandler.receive(Packet);
			
			// Check for duplicate packet
			if (call PacketHandler.isPacketDuplicate(Packet))
				return msg;
			
			// Process packet if we haven't seen it yet
			call NeighborDiscovery.receive(Packet);		// Neighbor discovery processing
			call LinkStateRouting.receive(Packet);		// Link state routing processing
			call PacketHandler.receive(Packet);			// General packet processing
			call TCP.receive(Packet);					// TCP processing
			
			return msg;
		}
		
		dbg("genDebug", "Unknown Packet Type %d\n", len);
      
		return msg;
	}
	
	void makePack(pack *Package, uint16_t src, uint16_t dest, uint8_t TTL, uint8_t protocol, uint16_t seq, uint8_t* payload, uint8_t length)
	{
		// Wrap sequence number
		if (++SEQUENCE_NUMBER > 65000)
			SEQUENCE_NUMBER = 0;
		
		Package->src = src;
		Package->dest = dest;
		Package->TTL = TTL;
		Package->seq = SEQUENCE_NUMBER;
		Package->protocol = protocol;
		memcpy(Package->payload, payload, length);
	}
	
	//////////////////////////////////////////////////
	// PACKET HANDLER
	//////////////////////////////////////////////////
	
	// Updates seq and TLL, ensures the packet should still exist and sends it
	event void PacketHandler.send(pack *Package, uint16_t address, bool updateTTL) //TODO technically queueing barring broadcasts now
	{
		// Link state packets need to go over the entire network, so no TTL reduction for them
		if (updateTTL) // && Package->protocol != PROTOCOL_LINKSTATE)
			Package->TTL--;
		
		// TTL Check
		if (Package->TTL <= 0)
			return;
		
		// Replace broadcast address with next hop if applicable
		if (Package->dest != UNSPECIFIED && address == AM_BROADCAST_ADDR && Package->protocol == PROTOCOL_PING) // ie not neighbor discovery pings
		{
			if (call routingTable.contains(Package->dest))
			{
				address = (uint16_t)(call routingTable.get(Package->dest));
				//dbg("Project2", "Replaced broadcast with destination: %d\n", address);
			}
			else
			{
				dbg("Project2", "\tEntry for %d not found in routing table. Aborting.\n", Package->dest);
				return;
			}
		}
		
		if (address != AM_BROADCAST_ADDR && Package->protocol == PROTOCOL_PING)
			dbg("Project2", "\tDelivering to hopping through %d to reach %d\n", address, Package->dest);
		
		call Sender.send(*Package, address);
	}
	
	// Creates a packet to send, default to broadcast -- this will be replaced if we have a routing table entry.
	event void PacketHandler.createAndSend(uint8_t *payload, uint16_t destination)
	{
		makePack(&sendPackage, TOS_NODE_ID, destination, MAX_TTL, PROTOCOL_PING, SEQUENCE_START, payload, PACKET_MAX_PAYLOAD_SIZE8);
		signal PacketHandler.send(&sendPackage, AM_BROADCAST_ADDR, FALSE);
	}
	
	// Sends ping reply
	event void PacketHandler.reply(uint16_t destination)
	{
		makePack(&sendPackage, TOS_NODE_ID, destination, MAX_TTL, PROTOCOL_PINGREPLY, SEQUENCE_START, pingPacket, PACKET_MAX_PAYLOAD_SIZE8);
		signal PacketHandler.send(&sendPackage, destination, FALSE);
	}
	
	//////////////////////////////////////////////////
	// TCP
	//////////////////////////////////////////////////
	
	event void TCP.createAndSend(socket_storage_t *TCPHeader, uint16_t destination)
	{
		dbg("Project3", "\tSending with header %d, %d to %d, %d\n",
			TCPHeader->sockAddr.srcAddr, TCPHeader->sockAddr.srcPort, TCPHeader->sockAddr.destAddr, TCPHeader->sockAddr.destPort);
		makePack(&sendPackage, TOS_NODE_ID, destination, MAX_TTL, PROTOCOL_TCP, SEQUENCE_START, (uint8_t*)TCPHeader, PACKET_MAX_PAYLOAD_SIZE8);
		signal PacketHandler.send(&sendPackage, AM_BROADCAST_ADDR, FALSE);
	}
	
	//////////////////////////////////////////////////
	// LINK STATE
	//////////////////////////////////////////////////
	
	event void LinkStateRouting.sendLinkState(uint8_t *payload)
	{
		makePack(&sendPackage, TOS_NODE_ID, UNSPECIFIED, MAX_TTL, PROTOCOL_LINKSTATE, SEQUENCE_START, payload, PACKET_MAX_PAYLOAD_SIZE8);
		signal PacketHandler.send(&sendPackage, AM_BROADCAST_ADDR, FALSE);
	}
	
	//////////////////////////////////////////////////
	// NEIGHBOR DISCOVERY
	//////////////////////////////////////////////////
	
	event void NeighborDiscovery.discoverNeighbors()
	{
		makePack(&sendPackage, TOS_NODE_ID, UNSPECIFIED, MAX_TTL, PROTOCOL_PING, SEQUENCE_START, pingPacket, PACKET_MAX_PAYLOAD_SIZE8);
		signal PacketHandler.send(&sendPackage, AM_BROADCAST_ADDR, FALSE);
	}
	
	event void NeighborDiscovery.neighborChanged()
	{
		// Indicate that a neighbor has changed
		NeighborsChanged = TRUE;
	}
	
	//////////////////////////////////////////////////
	// COMMAND HANDLER
	//////////////////////////////////////////////////
	
	event void CommandHandler.broadCast(uint8_t *payload, uint16_t destination)
	{
		signal PacketHandler.createAndSend(payload, destination);
	}

	event void CommandHandler.printNeighbors()
	{
		call NeighborDiscovery.printNeighbors();
	}
	
	event void CommandHandler.printRouteTable()
	{
		signal CommandHandler.printLinkState();
		call LinkStateRouting.printRoutingTable();
	}

	event void CommandHandler.printLinkState() 
	{
		call LinkStateRouting.printLinkState();
	}

	event void CommandHandler.printDistanceVector()
	{
		dbg("genDebug", "Distance Vector not relevent to this project!\n");
	}

	event void CommandHandler.setTestServer(uint8_t listenPort)
	{
		if (!call TCPTablePTR.contains(listenPort))
		{
			// Begin listening //TODO: Time out on this!
			signal TCP.setConnectionPTR(listenPort, SOCK_LISTEN);
			dbg("Project3", "\tOpened socket %d\n", listenPort);
		}
		else
		{
			dbg("Project3", "\tSocket %d already open\n", listenPort);
		}
	}

	event void CommandHandler.setTestClient(uint16_t targetAddress, uint8_t sendPort, uint8_t targetPort, uint16_t transfer)
	{
		// uint32_t keyVal = call TCP.getKeyFromHeaderData(targetAddress, sendPort, targetPort);
		socket_storage_t* connectionData;
		
		if (!call TCPTablePTR.contains(sendPort))
		{
			// Begin listening
			dbg("Project3", "\tTrying to connect from %d, %d to %d, %d\n", TOS_NODE_ID, sendPort, targetAddress, targetPort);
			signal TCP.setConnectionPTR(sendPort, SOCK_SYN_SENT);
			connectionData =  signal TCP.getConnectionState(sendPort);
			signal TCP.updateHeader(sendPort, TOS_NODE_ID, sendPort, targetAddress, targetPort);
			signal TCP.createAndSend( connectionData, targetAddress); //socket_addr_t
		}
		else
		{
			dbg("Project3", "\tConnection exists from %d, %d to %d, %d\n", TOS_NODE_ID, sendPort, targetAddress, targetPort);
		}
	}

	event void CommandHandler.setAppServer()
	{
		
	}

	event void CommandHandler.setAppClient()
	{
		
	}
	
	//////////////////////////////////////////////////
	//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$//
	// TABLE ACCESSING FUNCTIONS
	//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$//
	//////////////////////////////////////////////////
	
	//#####################
	//TCP
	//#####################
	
	event uint32_t* TCP.getConnectionKeys()
	{
		return (call TCPTablePTR.getKeys());
	}
	
	event socket_storage_t* TCP.getConnectionStatePTR(uint32_t connectionKey)
	{
		return (call TCPTablePTR.get(connectionKey));
	}
	
	event socket_storage_t* TCP.getConnectionState(uint32_t connectionKey)
	{
		uint32_t tableIndex = call TCPTablePTR.getIndex(connectionKey);
		dbg("Project3", "\tFetching ptr for %d, %d with index %d\n", TOS_NODE_ID, connectionKey, tableIndex);
		return &TCPTable[tableIndex];
	}
	
	event void TCP.setConnectionPTR(uint32_t connectionKey, uint8_t initialState)
	{
		uint32_t insertionIndex;
		
		// Insert a meaningless value for now (null pointer)
		call TCPTablePTR.insert(connectionKey, (void *)POINTER_NULL);
		insertionIndex = call TCPTablePTR.getIndex(connectionKey);
		
		// Now that we know where key is, replace null pointer with a pointer to the connection struct
		call TCPTablePTR.insert(connectionKey, &TCPTable[insertionIndex]);
		
		// Initialize with our initial state
		signal TCP.setConnectionState(connectionKey, initialState);
		
		dbg("Project3", "\tTable entry made for %d with key %d\n", TOS_NODE_ID, connectionKey);
	}
	
	event void TCP.updateHeader(uint32_t connectionKey, uint16_t src, uint8_t srcPort, uint16_t dest, uint8_t destPort)
	{
		uint32_t tableIndex;
		tableIndex = call TCPTablePTR.getIndex(connectionKey);
		
		TCPTable[tableIndex].sockAddr.srcAddr = src;
		TCPTable[tableIndex].sockAddr.srcPort = srcPort;
		TCPTable[tableIndex].sockAddr.destAddr = dest;
		TCPTable[tableIndex].sockAddr.destPort = destPort;
		
		dbg("Project3", "\tHeader saved for entry %d with key %d: %d, %d and %d, %d\n", TOS_NODE_ID, connectionKey, src, srcPort, dest, destPort);
	}
	
	event void TCP.setConnectionState(uint32_t connectionKey, uint8_t state)
	{
		uint32_t tableIndex;
		tableIndex = call TCPTablePTR.getIndex(connectionKey);
		
		TCPTable[tableIndex].state = state;
	}
	
	event bool TCP.containsConnection(uint32_t connectionKey)
	{
		return call TCPTablePTR.contains(connectionKey);
	}
	
	//#####################
	//Neighbor Discovery
	//#####################
	event uint32_t* NeighborDiscovery.getNeighborKeys()
	{
		return (call neighborTable.getKeys());
	}
	
	event uint16_t NeighborDiscovery.getNeighborConnection(uint32_t src)
	{
		return call neighborTable.get(src);
	}
	
	event void NeighborDiscovery.insertNeighbor(uint32_t src, uint16_t connection)
	{
		call neighborTable.insert(src, connection);
	}
	
	event bool NeighborDiscovery.containsNeighbor(uint32_t src)
	{
		return call neighborTable.contains(src);
	}
	
	//#####################
	//Link State
	//#####################
	
	event uint32_t* LinkStateRouting.getNeighborKeys()
	{
		return (call neighborTable.getKeys());
	}
	
	event uint16_t LinkStateRouting.getNeighborConnection(uint32_t src)
	{
		return call neighborTable.get(src);
	}
	
	event void LinkStateRouting.insertNeighbor(uint32_t src, uint16_t connection)
	{
		call neighborTable.insert(src, connection);
	}
	
	event bool LinkStateRouting.containsNeighbor(uint32_t src)
	{
		return call neighborTable.contains(src);
	}
	
	event uint32_t* LinkStateRouting.getRoutingKeys()
	{
		return (call routingTable.getKeys());
	}
	
	event uint16_t LinkStateRouting.getRoutingCost(uint32_t src)
	{
		return (call routingTable.get(src) >> 16);
	}
	
	event uint16_t LinkStateRouting.getRoutingHop(uint32_t src)
	{
		return (uint16_t)(call routingTable.get(src));
	}
	
	event void LinkStateRouting.clearRoutingTable()
	{
		call routingTable.clear();
	}
	
	event void LinkStateRouting.insertCostHop(uint32_t src, uint16_t cost, uint16_t hop)
	{
		uint32_t val = ((uint32_t)cost << 16) | hop;
		
		//if (TOS_NODE_ID == 2)
		//	dbg ("Project2", "Inserting cost/hop: %d, %d, combined:%d\n", cost, hop, val);
		
		call routingTable.insert(src, val);
	}
	
	event void LinkStateRouting.insertCost(uint32_t src, uint16_t cost)
	{
		// Get hop portion
		uint32_t val = (call routingTable.get(src));
		// combine cost + hop portion
		val = (cost << 16) | ((uint16_t)val);
		
		// Insert new value
		call routingTable.insert(src, val);
	}
	
	event void LinkStateRouting.insertHop(uint32_t src, uint16_t hop)
	{
		// Get current val (cost + hops)
		uint32_t val = (call routingTable.get(src));
		// Clear hop portion
		val = val ^ (uint16_t)val;
		// Insert new hop portion
		val = val | hop;
		
		// Insert new value
		call routingTable.insert(src, val);
	}
	
	event bool LinkStateRouting.containsNode(uint32_t src)
	{
		return call routingTable.contains(src);
	}
	
	//#####################
	//Packet Handler
	//#####################
	
	event uint32_t* PacketHandler.getSeqSrcKeys()
	{
		return (call sequenceTable.getKeys());
	}
	
	event uint16_t PacketHandler.getAge(uint32_t src, uint16_t seq)
	{
		uint32_t key = (src << 16) | seq;
		return (call sequenceTable.get(key));
	}
	
	event void PacketHandler.insertAge(uint32_t src, uint16_t seq, uint16_t age)
	{
		uint32_t key = (src << 16) | seq;
		call sequenceTable.insert(key, age);
	}
	
	event void PacketHandler.decreaseAge(uint32_t key)
	{
		uint16_t age = call sequenceTable.get(key) - 1;
		
		if (age > 0)
		{
			call sequenceTable.insert(key, age);
		}
		else
		{
			call sequenceTable.remove(key);
		}
	}
	
	event bool PacketHandler.containsSrcSeqPair(uint32_t src, uint16_t seq)
	{
		uint32_t key = (src << 16) | seq;
		return (call sequenceTable.contains(key));
	}
	
	event bool PacketHandler.containsSrcSeqKey(uint32_t key)
	{
		return (call sequenceTable.contains(key));
	}
	
}
