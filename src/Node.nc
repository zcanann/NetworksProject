#include <Timer.h>
#include "command.h"
#include "packet.h"
#include "neighbor.h"
#include "sendInfo.h"
#include "linkedstate.h"

module Node
{
	uses interface Boot;						// Interface for booting
	uses interface SplitControl as AMControl;	// Interface for radio
	uses interface Receive;						// Interface for receiving packets
	uses interface SimpleSend as Sender;		// Interface for sending packets
	
	uses interface CommandHandler;		// Interface for processing commands
	uses interface PacketHandler;		// Interface for handling packets
	uses interface NeighborDiscovery;	// Interface for discovering neighbors
	uses interface LinkStateRouting;	// Interface for link state routing
	
	uses interface Random;
	uses interface Timer<TMilli> as FrequentUpdate;	// Timer events that happen frequently
	uses interface Timer<TMilli> as ModerateUpdate;	// Timer events that happen moderately
	uses interface Timer<TMilli> as SparseUpdate;	// Timer events that happen sparsely
}

implementation
{
	pack sendPackage;
	uint8_t pingPacket[PACKET_MAX_PAYLOAD_SIZE8];
	
	// Table of all immediate neighbors
	uint16_t neighborIDs[NEIGHBOR_TABLE_SIZE];
	uint16_t neighborTable[NEIGHBOR_TABLE_SIZE];
	
	// Forwarding table stuff
	uint16_t forwardTableDest[FORWARD_TABLE_SIZE];
	uint16_t forwardTableCost[FORWARD_TABLE_SIZE];
	uint16_t forwardTableHop[FORWARD_TABLE_SIZE];
	
	// Sequence table stuff
	uint16_t sequenceTableSrc[SEQUENCE_TABLE_SIZE];
	uint16_t sequenceTableSeq[SEQUENCE_TABLE_SIZE];
	uint16_t sequenceTableAge[SEQUENCE_TABLE_SIZE];
	
	uint16_t SEQUENCE_NUMBER = 0;
	
	// Prototypes
	void makePack(pack *Package, uint16_t src, uint16_t dest, uint8_t TTL, uint8_t Protocol, uint16_t seq, uint8_t *payload, uint8_t length);
	
	event void Boot.booted()
	{
		//uint32_t Period;
		
		call AMControl.start();
		
		// Zero memory for all of the arrays that belong to this class
		memset(pingPacket, 0, sizeof(pingPacket));
		memset(neighborIDs, 0, sizeof(neighborIDs));
		memset(neighborTable, 0, sizeof(neighborTable));
		memset(forwardTableDest, 0, sizeof(forwardTableDest));
		memset(forwardTableCost, 0, sizeof(forwardTableCost));
		memset(forwardTableHop, 0, sizeof(forwardTableHop));
		memset(sequenceTableSrc, 0, sizeof(sequenceTableSrc));
		memset(sequenceTableSeq, 0, sizeof(sequenceTableSeq));
		memset(sequenceTableAge, 0, sizeof(sequenceTableAge));
		
		// Initialize all components
		call LinkStateRouting.initialize(neighborIDs, neighborTable, forwardTableDest, forwardTableCost, forwardTableHop);
		call PacketHandler.initialize(sequenceTableSrc, sequenceTableSeq, sequenceTableAge);
		call NeighborDiscovery.initialize(neighborIDs, neighborTable);
		
		// Initialize all update timers
		//Period = (call Random.rand32() % 200) + 1999; // Set pseudo random timer value
		call FrequentUpdate.startPeriodic((call Random.rand32() % 196) + 1999);
		call ModerateUpdate.startPeriodic((call Random.rand32() % 512) + 19991);
		call SparseUpdate.startPeriodic((call Random.rand32() % 4096) + 189999);
		
		dbg("genDebug", "Booted\n");
	}
	
	// Events that need to fire frequently
	event void FrequentUpdate.fired()
	{
		signal NeighborDiscovery.discoverNeighbors();
	}
	
	// Events that need to fire frequently (~x10 of frequent)
	event void ModerateUpdate.fired()
	{
		call NeighborDiscovery.timeOutCheck();
		call LinkStateRouting.shareLinkState();
	}
	
	// Events that need to fire sparsely (~x30 of frequent)
	event void SparseUpdate.fired()
	{
		call PacketHandler.ageSequenceTable();
		call LinkStateRouting.calculateRoute();
		dbg("Project2", "\tSwag\n");
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

	event void AMControl.stopDone(error_t err)
	{
		
	}

	event message_t* Receive.receive(message_t* msg, void* payload, uint8_t len)
	{
		pack* Packet;
		
		if(len == sizeof(pack))
		{
			Packet = (pack*)payload;
			
			// Always check for commands
			call CommandHandler.receive(Packet);
			
			// Check for looping packet
			if (call PacketHandler.isPacketLooping(Packet))
				return msg;
			
			// Process packet if we haven't seen it yet
			call NeighborDiscovery.receive(Packet);		// Neighbor discovery processing
			call LinkStateRouting.receive(Packet);		// Link state routing processing
			call PacketHandler.receive(Packet);			// General packet processing
			
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
	event void PacketHandler.send(pack *Package, uint16_t address, bool updateTTL)
	{
		// Link state packets need to go over the entire network, so no TTL reduction for them
		if (updateTTL) // && Package->protocol != PROTOCOL_LINKSTATE)
			Package->TTL--;
		
		// TTL Check
		if (Package->TTL <= 0)
			return;
		
		// Replace broadcast address with next hop if applicable
		if (Package->dest != UNSPECIFIED) // ie neighbor broadcasts
		{
			if (forwardTableHop[Package->dest] != EMPTY)
				address = forwardTableHop[Package->dest];
		}
		
		if (address != AM_BROADCAST_ADDR && Package->protocol == PROTOCOL_PING)
			dbg("Project2", "Delivering to %d through %d\n", Package->dest, address);
		
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
		
	}

	event void CommandHandler.setTestServer()
	{
		
	}

	event void CommandHandler.setTestClient()
	{
		
	}

	event void CommandHandler.setAppServer()
	{
		
	}

	event void CommandHandler.setAppClient()
	{
		
	}
}
