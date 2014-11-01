#include "../../Headers/packet.h"
#include "../../Headers/command.h"
#include "../../Headers/socket.h"

module TransportP
{
	provides interface Transport;
	uses interface PacketHandler;
	
	uses interface Hashmap<socket_storage_t*> as TCPTablePTR;

} // End module
	
implementation
{
	socket_storage_t TCPTable[TOTAL_PORTS];
	uint8_t TCPPacket[PACKET_MAX_PAYLOAD_SIZE8];
	
	command void Transport.initialize()
	{
		memset(TCPTable, 0, sizeof(TCPTable));
	}
	
	/*
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
	}*/
	
	command void Transport.createAndSend(socket_storage_t *TCPHeader, uint16_t destination)
	{
		dbg("Project3", "\tSending with header %d, %d to %d, %d\n",
			TCPHeader->sockAddr.srcAddr, TCPHeader->sockAddr.srcPort, TCPHeader->sockAddr.destAddr, TCPHeader->sockAddr.destPort);
		call PacketHandler.makePack(destination, PROTOCOL_TCP, (uint8_t*)TCPHeader);
		call PacketHandler.send(AM_BROADCAST_ADDR, FALSE);
	}
	
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
	}
	
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
	}
	
	command socket_t Transport.socket()
	{
		return 0;
	}
	
	command error_t Transport.bind(socket_t fd, socket_addr_t *addr)
	{
		return 0;
	}
	
	command socket_t Transport.accept(socket_t fd)
	{
		return 0;
	}

	command uint16_t Transport.write(socket_t fd, uint8_t *buff, uint16_t bufflen)
	{
		return 0;
	}
	
	command uint16_t Transport.read(socket_t fd, uint8_t *buff, uint16_t bufflen)
	{
		return 0;
	}
	
	command error_t Transport.connect(socket_t fd, socket_addr_t * addr)
	{
		return 0;
	}
	
	command error_t Transport.close(socket_t fd)
	{
		return 0;
	}
	
	command error_t Transport.release(socket_t fd)
	{
		return 0;
	}
	
	command error_t Transport.listen(socket_t fd)
	{
		return 0;
	}

} // End implementation
