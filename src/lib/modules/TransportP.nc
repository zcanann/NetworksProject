#include "../../Headers/packet.h"
#include "../../Headers/command.h"
#include "../../Headers/socket.h"

module TransportP
{
	provides interface Transport;
	uses interface PacketHandler;
	
	uses interface Random;
	uses interface Timer<TMilli> as AttemptConnection;
	uses interface Hashmap<socket_storage_t*> as TCPTablePTR;

} // End module
	
implementation
{
	socket_storage_t TCPTable[TOTAL_PORTS];
	uint8_t TCPPacket[PACKET_MAX_PAYLOAD_SIZE8];
	
	uint32_t Attempt_Connection_Time;
	
	command void Transport.initialize()
	{
		memset(TCPTable, 0, sizeof(TCPTable));
		Attempt_Connection_Time = (call Random.rand32() % 200) + 3999;
	}
	
	//////////////////////////////////////////////////
	// SOCKET TABLE STUFF
	//////////////////////////////////////////////////
	
	command socket_storage_t* Transport.getConnectionState(uint32_t connectionKey)
	{
		uint32_t tableIndex = call TCPTablePTR.getIndex(connectionKey);
		dbg("Project3", "\tFetching ptr for %d, %d with index %d\n", TOS_NODE_ID, connectionKey, tableIndex);
		return &TCPTable[tableIndex];
		
	} // End getConnectionState
	
	command void Transport.updateHeader(uint32_t connectionKey, uint16_t src, uint8_t srcPort, uint16_t dest, uint8_t destPort)
	{
		uint32_t tableIndex;
		tableIndex = call TCPTablePTR.getIndex(connectionKey);
		
		TCPTable[tableIndex].sockAddr.srcAddr = src;
		TCPTable[tableIndex].sockAddr.srcPort = srcPort;
		TCPTable[tableIndex].sockAddr.destAddr = dest;
		TCPTable[tableIndex].sockAddr.destPort = destPort;
		
		dbg("Project3", "\tHeader saved for entry %d with key %d: %d, %d and %d, %d\n", TOS_NODE_ID, connectionKey, src, srcPort, dest, destPort);
	
	} // End updateHeader
	
	command void Transport.setConnectionState(uint32_t connectionKey, uint8_t state)
	{
		uint32_t tableIndex;
		tableIndex = call TCPTablePTR.getIndex(connectionKey);
		
		TCPTable[tableIndex].state = state;
	
	} // End setConnectionState
	
	command void Transport.setConnectionPTR(uint32_t connectionKey, uint8_t initialState)
	{
		uint32_t insertionIndex;
		
		// Insert a meaningless value for now (null pointer)
		call TCPTablePTR.insert(connectionKey, (void *)POINTER_NULL);
		insertionIndex = call TCPTablePTR.getIndex(connectionKey);
		
		// Now that we know where key is, replace null pointer with a pointer to the connection struct
		call TCPTablePTR.insert(connectionKey, &TCPTable[insertionIndex]);
		
		// Initialize with our initial state
		call Transport.setConnectionState(connectionKey, initialState);
		
		dbg("Project3", "\tTable entry made for %d with key %d\n", TOS_NODE_ID, connectionKey);
		
	} // End setConnectionPTR
	
	command void Transport.createAndSend(socket_storage_t *TCPHeader, uint16_t destination)
	{
		dbg("Project3", "\tSending with header %d, %d to %d, %d\n",
			TCPHeader->sockAddr.srcAddr, TCPHeader->sockAddr.srcPort, TCPHeader->sockAddr.destAddr, TCPHeader->sockAddr.destPort);
		call PacketHandler.makePack(destination, PROTOCOL_TCP, (uint8_t*)TCPHeader);
		call PacketHandler.send(AM_BROADCAST_ADDR, FALSE);
		
	} // End createAndSend
	
	// DEPRECATED // Combines the 3 identifiers of a TCP connection into one single value (4th identifier is NODE_ID)
	command uint32_t Transport.getKeyFromHeaderData(uint16_t dest, uint8_t srcPort, uint8_t destPort)
	{
		uint32_t destMask;
		uint32_t srcPortMask;
		uint32_t destPortMask;
		
		destMask = (uint32_t)dest << 24;
		srcPortMask = (uint32_t)srcPort << 8;
		destPortMask = (uint32_t)destPort;
		
		return (destMask | srcPortMask | destPortMask);
		
	} // End getKeyFromHeaderData
	
	//////////////////////////////////////////////////
	// SOCKET INITIALIZATION FUNCTIONS
	//////////////////////////////////////////////////
	
	command void Transport.setTestClient(uint16_t targetAddress, uint8_t sendPort, uint8_t targetPort, uint16_t transfer)
	{
		// uint32_t keyVal = call TCP.getKeyFromHeaderData(targetAddress, sendPort, targetPort);
		socket_storage_t* connectionData;
		
		if (!call TCPTablePTR.contains(sendPort))
		{
			// Begin listening
			dbg("Project3", "\tTrying to connect from %d, %d to %d, %d with transfer %d\n", TOS_NODE_ID, sendPort, targetAddress, targetPort, transfer);
			call Transport.setConnectionPTR(sendPort, SOCK_SYN_SENT);
			connectionData =  call Transport.getConnectionState(sendPort);
			call Transport.updateHeader(sendPort, TOS_NODE_ID, sendPort, targetAddress, targetPort);
			call Transport.createAndSend(connectionData, targetAddress); //socket_addr_t
		}
		else
		{
			dbg("Project3", "\tConnection exists from %d, %d to %d, %d\n", TOS_NODE_ID, sendPort, targetAddress, targetPort);
		}
	
	} // End setTestClient
	
	command void Transport.setTestServer(uint8_t listenPort)
	{
		socket_t fd;
		socket_addr_t address;
		
		//fd = call Transport.socket();
		fd = listenPort;
		address.srcAddr = TOS_NODE_ID;
		address.srcPort = listenPort;
		
		call Transport.bind(fd, &address);
		
		call AttemptConnection.startOneShot(Attempt_Connection_Time);
		
	} // End setTestServer
	
	//////////////////////////////////////////////////
	// RECEIVE PACKET / MISC
	//////////////////////////////////////////////////
	
	// Time out on connection attempt
	event void AttemptConnection.fired()
	{
		socket_t newFd = call Transport.accept(0); // TODO fix
		if (newFd != NULL_SOCKET)
		{
			// Add to list of accepted sockets
		}
		else
		{
			// print all sockets
		}
		
	} // End AttemptConnection
	
	command error_t Transport.receive(pack* Packet)
	{
		socket_storage_t *TCPHeader;
		
		// Neighbors are determined exclusively through ping and ping replies
		if (Packet->protocol != PROTOCOL_TCP || Packet->dest != TOS_NODE_ID)
			return FAIL;
		
		TCPHeader = (socket_storage_t*)Packet->payload;
		
		switch (TCPHeader->state)
		{
			case SOCK_ESTABLISHED:
			
				break;
			case SOCK_LISTEN:
				
				break;
			case SOCK_CLOSED:
			
				break;
			case SOCK_SYN_SENT:
				dbg("Project3", "Recieved sync packet from from %d, %d to %d, %d\n",
					TCPHeader->sockAddr.srcAddr, TCPHeader->sockAddr.srcPort, TCPHeader->sockAddr.destAddr, TCPHeader->sockAddr.destPort);
				break;
			case SOCK_CLOSE_WAIT:
			
				break;
			case SOCK_FIN_WAIT:
			
				break;
		}
		
		//connectionKey = call TCP.getKeyFromHeaderData(dest, srcPort, destPort);
		
		//if (!signal TCP.containsConnection(connectionKey))
		{
			
		}
		
		return SUCCESS;
		
	} // End receive
	
	command socket_t Transport.socket()
	{
		return LISTEN_PORT;
		
	} // End socket
	
	command error_t Transport.bind(socket_t fd, socket_addr_t *addr)
	{
		if (fd == NULL_SOCKET)
		{
			dbg("Project3", "\fd unable to allocate resources\n", addr->srcPort);
			return FAIL;
		}
		
		if (call TCPTablePTR.contains(addr->srcPort))
		{
			dbg("Project3", "\tSocket %d already open\n", addr->srcPort);
			return FAIL;
		}
		
		call Transport.listen(addr->srcPort);
		
		return SUCCESS;
		
	} // End bind
	
	command socket_t Transport.accept(socket_t fd)
	{
		return FAIL;
		
	} // End accept

	command uint16_t Transport.write(socket_t fd, uint8_t *buff, uint16_t bufflen)
	{
		return FAIL;
		
	} // End write
	
	command uint16_t Transport.read(socket_t fd, uint8_t *buff, uint16_t bufflen)
	{
		return FAIL;
		
	} // End read
	
	command error_t Transport.connect(socket_t fd, socket_addr_t * addr)
	{
		return FAIL;
		
	} // End connect
	
	command error_t Transport.close(socket_t fd)
	{
		return FAIL;
		
	} // End close
	
	command error_t Transport.release(socket_t fd)
	{
		return FAIL;
		
	} // End release
	
	command error_t Transport.listen(socket_t fd)
	{
		call Transport.setConnectionPTR(fd, SOCK_LISTEN);
		dbg("Project3", "\tOpened socket %d for listening\n", fd);
		return SUCCESS;
		
	} // End listen

} // End implementation
