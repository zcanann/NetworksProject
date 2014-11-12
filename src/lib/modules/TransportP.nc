#include "../../Headers/packet.h"
#include "../../Headers/command.h"
#include "../../Headers/socket.h"

module TransportP
{
	provides interface Transport;
	uses interface PacketHandler;
	uses interface DataTransfer;
	
	uses interface Random;
	uses interface Timer<TMilli> as WriteTimer;
	uses interface Hashmap<socket_storage_t*> as TCPTablePTR;

} // End module
	
implementation
{
	socket_storage_t TCPTable[TOTAL_PORTS];
	transfer_packet TCPPacket;
	
	command void Transport.initialize()
	{
		memset(TCPTable, 0, sizeof(TCPTable));
		
		call DataTransfer.initialize(&TCPPacket);
	}
	
	command void Transport.printConnectionStates()
	{
		uint32_t* keys;
		uint32_t keyInd;
		socket_storage_t* connectionState;
		
		keys = call TCPTablePTR.getKeys();
		
		dbg("Project3", "NODE %d STATES:\n", TOS_NODE_ID);
		
		for (keyInd = 0; keyInd < TOTAL_PORTS; keyInd++)
		{
			// Ignore empty entries
			if (keys[keyInd] == 0)
				continue;
			
			connectionState = call Transport.getConnectionState(keys[keyInd]);
			
			switch (connectionState->state)
			{
				case SOCK_CLOSED:
					dbg("Project3", "\tPORT %d CLOSED\n", keys[keyInd]);
					break;
				case SOCK_LISTEN:
					dbg("Project3", "\tPORT %d LISTEN\n", keys[keyInd]);
					break;
				case SOCK_SYN_SENT:
					dbg("Project3", "\tPORT %d SYN_SENT\n", keys[keyInd]);
					break;
				case SOCK_SYN_RECEIVED:
					dbg("Project3", "\tPORT %d SYN_RECEIVED\n", keys[keyInd]);
					break;
				case SOCK_ESTABLISHED:
					dbg("Project3", "\tPORT %d ESTABLISHED\n", keys[keyInd]);
					break;
				case SOCK_FIN_WAIT1:
					dbg("Project3", "\tPORT %d FIN_WAIT1\n", keys[keyInd]);
					break;
				case SOCK_FIN_WAIT2:
					dbg("Project3", "\tPORT %d FIN_WAIT2\n", keys[keyInd]);
					break;
				case SOCK_CLOSING:
					dbg("Project3", "\tPORT %d CLOSING\n", keys[keyInd]);
					break;
				case SOCK_TIME_WAIT:
					dbg("Project3", "\tPORT %d TIME_WAIT\n", keys[keyInd]);
					break;
				case SOCK_CLOSE_WAIT:
					dbg("Project3", "\tPORT %d CLOSE_WAIT\n", keys[keyInd]);
					break;
				case SOCK_LAST_ACK:
					dbg("Project3", "\tPORT %d LAST_ACK\n", keys[keyInd]);
					break;
			}
		}
	}
	
	//////////////////////////////////////////////////
	// SOCKET TABLE STUFF
	//////////////////////////////////////////////////
	
	command bool Transport.isPortInUse(socket_addr_t* addr)
	{
		return (call TCPTablePTR.contains(addr->srcPort));
	}
	
	command bool Transport.isConnectedTo(socket_addr_t* addr)
	{
		uint32_t* keys;
		uint32_t keyInd;
		socket_storage_t* connectionState;
		
		keys = call TCPTablePTR.getKeys();
		
		for (keyInd = 0; keyInd < TOTAL_PORTS; keyInd++)
		{
			// Ignore empty entries
			if (keys[keyInd] == 0)
				continue;
			
			connectionState = call Transport.getConnectionState(keys[keyInd]);
			
			// We are connected to this address/port already!
			if (addr->destAddr == connectionState->sockAddr.destAddr &&
				addr->destPort == connectionState->sockAddr.destPort)
				return TRUE;
		}
		return FALSE;
	}
	
	command socket_storage_t* Transport.getConnectionState(uint32_t connectionKey)
	{
		uint32_t tableIndex = call TCPTablePTR.getIndex(connectionKey);
		
		if (tableIndex > TOTAL_PORTS || tableIndex < 0)
			return NULL;
		
		//dbg("Project3", "\tFetching ptr for %d, %d with index %d\n", TOS_NODE_ID, connectionKey, tableIndex);
		return &TCPTable[tableIndex];
		
	} // End getConnectionState
	
	command void Transport.updateHeader(socket_addr_t* address)
	{
		uint32_t connectionKey;
		uint32_t tableIndex;
		connectionKey = address->srcPort;
		tableIndex = call TCPTablePTR.getIndex(connectionKey);
		TCPTable[tableIndex].sockAddr = *address;
		
	} // End updateHeader
	
	command void Transport.setConnectionState(uint32_t connectionKey, socketState state)
	{
		uint32_t tableIndex;
		tableIndex = call TCPTablePTR.getIndex(connectionKey);
		
		if (tableIndex > TOTAL_PORTS)
		{
			dbg("Project3", "ATTEMPTED TO ACCESS INVALID TABLE ENTRY\n", connectionKey);
			return;
		}
		TCPTable[tableIndex].state = state;
		
		call Transport.printConnectionStates();
	
	} // End setConnectionState
	
	command void Transport.setConnectionPTR(uint32_t connectionKey, socketState initialState)
	{
		uint32_t insertionIndex;
		
		// Insert a meaningless value for now (null pointer)
		call TCPTablePTR.insert(connectionKey, (void *)POINTER_NULL);
		insertionIndex = call TCPTablePTR.getIndex(connectionKey);
		
		// Now that we know where key is, replace null pointer with a pointer to the connection struct
		call TCPTablePTR.insert(connectionKey, &TCPTable[insertionIndex]);
		
		// Initialize with our initial state
		call Transport.setConnectionState(connectionKey, initialState);
		
		//dbg("Project3", "\tTable entry made for %d with key %d\n", TOS_NODE_ID, connectionKey);
		
	} // End setConnectionPTR
	
	//////////////////////////////////////////////////
	// SEND / RECEIVE / MISC
	//////////////////////////////////////////////////
	
	command void Transport.resendSynAck()
	{
		socket_t portID;
		socket_storage_t* connectionData;
		// TODO maybe instead of this keep track of # syns sent. if > k then mark as dead
		// TODO: this should be using keys, otherwise its O(n^2-k)
		for (portID = 1; portID < TOTAL_PORTS; portID++)
		{
			if (call TCPTablePTR.contains(portID))
			{
				connectionData =  call Transport.getConnectionState(portID);
				if (connectionData->state == SOCK_SYN_SENT)
				{
					dbg("Project3", "Resending SYN...\n");
					call Transport.createAndSend(connectionData, SYN, NO_OFFSET);
				}
				else if (connectionData->state == SOCK_SYN_RECEIVED)
				{
					dbg("Project3", "Resending SYNACK...\n");
					call Transport.createAndSend(connectionData, SYNACK, NO_OFFSET);
				}
			}
		}
	}
	
	command error_t Transport.createAndSend(socket_storage_t* connectionData, transferProtocol protocol, uint8_t offset)
	{
		uint8_t temp;
		
		// Prepare the TCP header
		TCPPacket.protocol = (uint8_t)protocol;
		TCPPacket.srcPort = connectionData->sockAddr.srcPort;
		TCPPacket.destPort = connectionData->sockAddr.destPort;
		
		// Initialize sequence numbers
		if (protocol == SYN)
		{
			// Initialize sequence number for client
			connectionData->baseSeqNum = (uint8_t)(call Random.rand16());
			TCPPacket.seqNum = connectionData->baseSeqNum;
			TCPPacket.ackNum = 0;
		}
		else if (protocol == SYNACK)
		{
			// Initialize sequence number for server
			connectionData->baseSeqNum = (uint8_t)(call Random.rand16());
			TCPPacket.seqNum = connectionData->baseSeqNum;
			
			// Increment client sequence number
			TCPPacket.ackNum = (uint8_t)(connectionData->baseAckNum + (uint8_t)DATA_SIZE * offset);
		}
		else if (protocol == ACK)
		{
			// Create acks with increasing sequence number (calculated as an offset from the current base)
			TCPPacket.seqNum = (uint8_t)(connectionData->baseSeqNum + (uint8_t)DATA_SIZE * offset);
			TCPPacket.ackNum = (uint8_t)(connectionData->baseAckNum + (uint8_t)DATA_SIZE * offset);
		}
		else if (protocol == ACK_NODATA)
		{
			// Respond to acks
			TCPPacket.seqNum = (uint8_t)(TCPPacket.seqNum + (uint8_t)DATA_SIZE);
			TCPPacket.ackNum = (uint8_t)(TCPPacket.ackNum + (uint8_t)DATA_SIZE);
			//dbg("Project3", "Got a packet acknowledged Seq %d Ack %d\n", TCPPacket.seqNum, TCPPacket.ackNum);
		}
		
		
		dbg("Project3", "SENDING: Protocol %d Seq %d\tAck %d\t>> Dest/Port %d/%d to Dest/Port %d/%d Payload:%s\n", protocol,
			TCPPacket.seqNum, TCPPacket.ackNum,
			TOS_NODE_ID, TCPPacket.srcPort, connectionData->sockAddr.destAddr, TCPPacket.destPort, TCPPacket.data);
		
		// Make and send packet
		call PacketHandler.makePack(connectionData->sockAddr.destAddr, PROTOCOL_TCP, (uint8_t*)&TCPPacket);
		
		return call PacketHandler.send(AM_BROADCAST_ADDR, FALSE);
		
	} // End createAndSend
	
	// Time out on writing data
	event void WriteTimer.fired()
	{
		
		
	} // End WriteTimer
	
	command error_t Transport.receive(pack* Packet)
	{
		transfer_packet *TCPPayload;
		
		// Neighbors are determined exclusively through ping and ping replies
		if (Packet->protocol != PROTOCOL_TCP || Packet->dest != TOS_NODE_ID)
			return FAIL;
		
		TCPPayload = (transfer_packet*)Packet->payload;
		
		switch (TCPPayload->protocol)
		{
			case SYN:
				call Transport.receiveSyn(Packet);
				break;
			case SYNACK:
				call Transport.receiveSynAck(Packet);
				break;
			case ACK:
				call Transport.receiveAck(Packet);
				break;
			case ACK_NODATA:
				// See DataTransfer for processing of these packets.
				break;
			case FIN:
				dbg("Project3", "Recieved FIN packet from from %d, %d to %d, %d\n",
					Packet->src, TCPPayload->srcPort, Packet->dest, TCPPayload->destPort);
				break;
		}
		
		call DataTransfer.receive(Packet);
		
		return SUCCESS;
		
	} // End receive
	
	//////////////////////////////////////////////////
	// FINITE STATE FUNCTIONS
	//////////////////////////////////////////////////
	
	command void Transport.receiveAck(pack* Packet)
	{
		transfer_packet *TCPPayload;		// TCP Payload of packet being sent
		socket_storage_t *connectionData;	// Current connection state with the sender
		
		TCPPayload = (transfer_packet*)Packet->payload;								// Grab payload
		connectionData = call Transport.getConnectionState(TCPPayload->destPort);	// Grab table entry
		
		dbg("Project3", "Recieved ACK packet from from %d, %d to %d, %d Payload: %s\n",
					Packet->src, TCPPayload->srcPort, Packet->dest, TCPPayload->destPort, TCPPayload->data);
		
		if (connectionData == NULL)
		{
			dbg("Project3", "\tRecieved ACK when not listening!\n");
			return;
		}
		
		switch (connectionData->state)
		{
			/*SOCK_CLOSED			= 0
				SOCK_LISTEN			= 1
				SOCK_SYN_SENT		= 2
				SOCK_SYN_RECEIVED	= 3
				SOCK_ESTABLISHED	= 4
				SOCK_FIN_WAIT1		= 5
				SOCK_FIN_WAIT2		= 6
				SOCK_CLOSING		= 7
				SOCK_TIME_WAIT		= 8
				SOCK_CLOSE_WAIT		= 9
				SOCK_LAST_ACK		= 10*/
			case SOCK_SYN_RECEIVED:
				//dbg("Project3", "\tChanging state to ESTABLISHED (ss)\n");
				call Transport.setConnectionState(connectionData->sockAddr.srcPort, SOCK_ESTABLISHED);
				break;
			default:
				//dbg("Project3", "\tRecieved ACK packet but was not expecting one! State: %d\n", connectionData->state);
				break;
				
			}
	}
	
	command void Transport.receiveSynAck(pack* Packet)
	{
		transfer_packet *TCPPayload;		// TCP Payload of packet being sent
		socket_storage_t *connectionData;	// Current connection state with the sender
		
		TCPPayload = (transfer_packet*)Packet->payload;								// Grab payload
		connectionData = call Transport.getConnectionState(TCPPayload->destPort);	// Grab table entry
		
		dbg("Project3", "Recieved SYNACK packet from from %d, %d to %d, %d\n",
					Packet->src, TCPPayload->srcPort, Packet->dest, TCPPayload->destPort);
		
		if (connectionData == NULL)
		{
			dbg("Project3", "\tRecieved SYNACK when not listening!\n");
			return;
		}
		
		switch (connectionData->state)
		{
			case SOCK_SYN_SENT:
				//dbg("Project3", "\tChanging state to ESTABLISHED (cs) and changing destination port to %d\n", TCPPayload->srcPort);
				if (TCPPayload->ackNum == (uint8_t)(connectionData->baseSeqNum + (uint8_t)DATA_SIZE))
				{
					// Adopt sequence numbers
					connectionData->baseSeqNum = TCPPayload->ackNum;
					connectionData->baseAckNum = TCPPayload->seqNum;
					
					// Update port we are connecting to
					connectionData->sockAddr.destPort = TCPPayload->srcPort;
					
					// Move state to established
					call Transport.setConnectionState(connectionData->sockAddr.srcPort, SOCK_ESTABLISHED);
				}
				else
				{
					dbg("Project3", "\tRecieved SYNACK with invalid sequence number!\n");
				}
				//call Transport.createAndSend(connectionData, ACK);
				break;
			default:
				//dbg("Project3", "\tRecieved SYNACK packet but was not expecting one! State: %d", connectionData->state);
				break;
				
			}
	}
	
	command void Transport.receiveSyn(pack* Packet)
	{
		transfer_packet *TCPPayload;		// TCP Payload of packet being sent
		socket_storage_t *connectionData;	// Current connection state with the sender
		socket_addr_t newAddress;			// Assignment to a new location to connect
		socket_t newPort;
		
		TCPPayload = (transfer_packet*)Packet->payload;								// Grab payload
		connectionData = call Transport.getConnectionState(TCPPayload->destPort);	// Grab table entry
		
		dbg("Project3", "Recieved SYN packet from from %d, %d to %d, %d\n",
			Packet->src, TCPPayload->srcPort, Packet->dest, TCPPayload->destPort);
		
		if (connectionData == NULL)
		{
			dbg("Project3", "\tRecieved SYN when not listening!\n");
			return;
		}
		
		switch (connectionData->state)
		{
			/*case SOCK_ESTABLISHED:
			case SOCK_CLOSED:
			case SOCK_SYN_SENT:
			case SOCK_CLOSE_WAIT:
			case SOCK_FIN_WAIT:*/
			case SOCK_LISTEN:
			
				// Find new entry to communicate on
				newPort = call Transport.getSocket(&connectionData->sockAddr);
					
				// Create new socketAddr data
				newAddress.srcAddr = TOS_NODE_ID;
				newAddress.srcPort = (nx_uint8_t)newPort;
				newAddress.destAddr = Packet->src;
				newAddress.destPort = TCPPayload->srcPort;
				
				if (call Transport.isConnectedTo(&newAddress))
				{
					//dbg("Project3", "\tRecieved duplicate SYN. Ignoring it.\n", newPort);
					break;
				}
				
				if (call Transport.bind(&newAddress, SOCK_SYN_RECEIVED) == FAIL)
					break;
				
				//dbg("Project3", "\tOpened socket %d with state SYN_RCVD (ss)\n", newPort);
				// call AttemptConnection.startOneShot(Attempt_Connection_Time);
				
				connectionData =  call Transport.getConnectionState(newPort);
				connectionData->baseAckNum = TCPPayload->seqNum;	// Always adopt ackNum from Syns
				call Transport.createAndSend(connectionData, SYNACK, NO_OFFSET);
				
				break;
			default:
				//dbg("Project3", "\tRecieved SYN packet but was not expecting one! State: %d\n", connectionData->state);
				break;
				
			}
	}
	
	//////////////////////////////////////////////////
	// CORE FUNCTIONS
	//////////////////////////////////////////////////
	
	command socket_t Transport.getSocket(socket_addr_t* addr)
	{
		int portInd;
		
		for (portInd = 1; portInd < TOTAL_PORTS; portInd++)
		{
			if (call TCPTablePTR.contains(portInd))
				continue;
			return portInd;
		}
		return NULL_SOCKET;
		
	} // End socket
	
	command error_t Transport.bind(socket_addr_t *addr, socketState initialState)
	{
		socket_t fd = addr->srcPort;
		
		if (call TCPTablePTR.contains(fd))
		{
			dbg("Project3", "\tSocket %d already open\n", fd);
			return FAIL;
		}
		
		if (fd == NULL_SOCKET)
		{
			dbg("Project3", "\tAttempting to use null socket\n", fd);
			return FAIL;
		}
		
		call Transport.setConnectionPTR(fd, initialState);
		call Transport.updateHeader(addr);
		
		return SUCCESS;
		
	} // End bind
	
	command socket_t Transport.accept(socket_addr_t *addr)
	{
		//socket_t fd;
		return NULL_SOCKET;
		
	} // End accept

	command uint16_t Transport.write(socket_t fd, uint8_t *buff, uint16_t bufflen)
	{
		return FAIL;
		
	} // End write
	
	command uint16_t Transport.read(socket_t fd, uint8_t *buff, uint16_t bufflen)
	{
		return FAIL;
		
	} // End read
	
	command error_t Transport.close(socket_addr_t *addr)
	{
		return FAIL;
		
	} // End close
	
	command error_t Transport.release(socket_addr_t *addr)
	{
		return FAIL;
		
	} // End release
	
	command error_t Transport.connect(socket_addr_t* addr, uint16_t transfer)
	{
		socket_storage_t* connectionData;
		socket_t fd = addr->srcPort; //fd = call Transport.socket();
		
		//call WriteTimer.startOneShot(Client_Write_Time);
		if (!call Transport.isPortInUse(addr))
		{
			// Begin listening
			dbg("Project3", "\tTrying to connect from %d, %d to %d, %d\n", TOS_NODE_ID, addr->srcPort, addr->destAddr, addr->destPort);
			call Transport.bind(addr, SOCK_SYN_SENT);
			
			connectionData =  call Transport.getConnectionState(fd);
			call DataTransfer.updateTransferAmount(connectionData, transfer);
			call Transport.createAndSend(connectionData, SYN, NO_OFFSET); //socket_addr_t
		}
		else
		{
			dbg("Project3", "Port already in use!\n");
		}
		
		return FAIL;
		
	} // End connect
	
	command error_t Transport.listen(socket_t socket)
	{
		socket_addr_t address;
		
		address.srcAddr = TOS_NODE_ID;
		address.srcPort = (uint8_t)socket;
		// other details are not yet determined until we connect to a client
		
		if (call Transport.bind(&address, SOCK_LISTEN) == SUCCESS)
		{
			dbg("Project3", "\tOpened socket %d for listening\n", socket);
			return SUCCESS;
		}
		
		dbg("Project3", "\tUnable to open socket %d for listening\n", socket);
		return FAIL;
		
	} // End listen

} // End implementation
