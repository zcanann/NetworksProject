
#include <Timer.h>
#include "../../packet.h"
#include "../../command.h"
#include "../../socket.h"

module TCPP
{
	provides interface TCP;
}
	
implementation
{
	//TCPHeader TCP_Header;
	
	
	command void TCP.initialize()
	{
		
	}
	
	// DEPRECATED // Combines the 3 identifiers of a TCP connection into one single value (4th identifier is NODE_ID)
	command uint32_t TCP.getKeyFromHeaderData(uint16_t dest, uint8_t srcPort, uint8_t destPort)
	{
		uint32_t destMask;
		uint32_t srcPortMask;
		uint32_t destPortMask;
		
		destMask = (uint32_t)dest << 24;
		srcPortMask = (uint32_t)srcPort << 8;
		destPortMask = (uint32_t)destPort;
		
		return (destMask | srcPortMask | destPortMask);
	}
	
	command error_t TCP.receive(pack* Packet)
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
}
