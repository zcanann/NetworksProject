
#include <Timer.h>
#include "../../packet.h"
#include "../../command.h"
#include "../../neighbor.h"

module NeighborDiscoveryP
{
	provides interface NeighborDiscovery;
}
	
implementation
{
	bool TimeOutState = TRUE;	// Alternates state of waiting for a response and declaring a time-out
	
	command void NeighborDiscovery.initialize()
	{
		
	}
	
	command error_t NeighborDiscovery.receive(pack* Packet)
	{
		uint16_t connectionStateOriginal;
		uint16_t connectionState;
		
		// Ignore packets that are not from immediate neighbors
		if (Packet->TTL != MAX_TTL)
			return FAIL;
		
		// Neighbors are determined exclusively through ping and ping replies
		if (Packet->protocol != PROTOCOL_PING && Packet->protocol != PROTOCOL_PINGREPLY)
			return FAIL;
			
		// Initialize to an unspecified connection type
		if (!signal NeighborDiscovery.containsNeighbor(Packet->src))
				signal NeighborDiscovery.insertNeighbor(Packet->src, CONNECTION_NONE);
		
		// Clear waiting/time out flags
		connectionStateOriginal =  connectionState = signal NeighborDiscovery.getNeighborConnection(Packet->src);
		connectionState &= ~CONNECTION_WAITING_RESPONSE;
		connectionState &= ~CONNECTION_TIMED_OUT;
		signal NeighborDiscovery.insertNeighbor(Packet->src, connectionState);
			
		if(Packet->protocol == PROTOCOL_PING)
		{
			// We are getting pinged by a neighbor and they can connect to us -- packetHandler will reply
			if (connectionState == CONNECTION_NONE || (connectionStateOriginal & CONNECTION_TIMED_OUT))
			{
				signal NeighborDiscovery.neighborChanged();
				dbg ("Project1N", "Connection discovered:\t %d -> %d\n", Packet->src, TOS_NODE_ID);
			}
			
			connectionState |= CONNECTION_RECEIVE;
			signal NeighborDiscovery.insertNeighbor(Packet->src, connectionState);
		}
		else if(Packet->protocol == PROTOCOL_PINGREPLY)
		{
			// The neighbor replied -- we have a 2 way connection
			if ((connectionState & CONNECTION_SEND) == 0 || (connectionStateOriginal & CONNECTION_TIMED_OUT))
			{
				signal NeighborDiscovery.neighborChanged();
				dbg("Project1N", "Conection discovered:\t %d <-> %d\n", Packet->src, TOS_NODE_ID);
			}
			connectionState |= CONNECTION_SEND;
			signal NeighborDiscovery.insertNeighbor(Packet->src, connectionState);
			
		}
		
		return SUCCESS;
	}
	
	// Determines if a neighbor has been dropped based on lack of responses
	command void NeighborDiscovery.timeOutCheck()
	{
		uint32_t *keys;
		uint32_t keyInd;
		uint16_t connectionState;
		
		keys = signal NeighborDiscovery.getNeighborKeys();
		
		// Check if neighbor should be marked as waiting for response or timed out
		for (keyInd = 0; keyInd < NEIGHBOR_TABLE_SIZE; keyInd++)
		{
			// Ignore empty entries
			if (keys[keyInd] == EMPTY)
				continue;
			
			// Retrieve connection state
			connectionState = signal NeighborDiscovery.getNeighborConnection(keys[keyInd]);
			
			// Ignore connectionless neighbors
			if (connectionState == CONNECTION_NONE)
				continue;
			
			
			// STATE 1: Mark neighbors as waiting for a response
			if (TimeOutState)
			{
				// Mark as waiting for a response
				connectionState |= CONNECTION_WAITING_RESPONSE;
			}
			// STATE 2: Mark neighbors who still have not sent a ping as timed-out
			else
			{
				if ((connectionState & CONNECTION_WAITING_RESPONSE) != 0)
				{
					
					if ((connectionState & CONNECTION_TIMED_OUT) == 0)
					{
						signal NeighborDiscovery.neighborChanged();
						dbg ("Project1N", "Connection timed out:\t %d -> %d\n", TOS_NODE_ID, keys[keyInd]);
					}
					
					connectionState |= CONNECTION_TIMED_OUT;
				}
			}
			
			// Update with new value
			signal NeighborDiscovery.insertNeighbor(keys[keyInd], connectionState);
		}
		
		// Flip the state for the next timer call
		TimeOutState = !TimeOutState;
	}
	
	command void NeighborDiscovery.printNeighbors()
	{
		uint32_t *keys;
		uint32_t keyInd;
		uint16_t connectionState;
		
		keys = signal NeighborDiscovery.getNeighborKeys();
		
		dbg("Project1N", "Neighbors (%d):\n", TOS_NODE_ID);
		for (keyInd = 0; keyInd < NEIGHBOR_TABLE_SIZE; keyInd++)
		{
			// Ignore empty entries
			if (keys[keyInd] == EMPTY)
				continue;
			
			// Retrieve connection state
			connectionState = signal NeighborDiscovery.getNeighborConnection(keys[keyInd]);
			
			if (connectionState & CONNECTION_TIMED_OUT)
				dbg("Project1N", "\tNeighbor %d -/- %d\n", keys[keyInd], TOS_NODE_ID);
			else if (connectionState & CONNECTION_SEND) // Assuming two way connection since we only know we can send if they told us
				dbg("Project1N", "\tNeighbor %d <-> %d\n", keys[keyInd], TOS_NODE_ID);
			else if (connectionState & CONNECTION_RECEIVE)
				dbg("Project1N", "\tNeighbor %d ->  %d\n", keys[keyInd], TOS_NODE_ID);
		}
	}
}
