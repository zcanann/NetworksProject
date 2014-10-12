
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
	uint16_t* neighborIDs;	// Pointer to neighbor table in Node
	uint16_t* neighborTable;	// Pointer to neighbor table in Node
	bool TimeOutState = TRUE;	// Alternates state of waiting for a response and declaring a time-out
	
	command void NeighborDiscovery.initialize(uint16_t* neighborIDsPointer, uint16_t* neighborTablePointer)
	{
		neighborIDs = neighborIDsPointer;		// Set pointer to neighbor IDs table
		neighborTable = neighborTablePointer;	// Set pointer to neighbor table
	}
	
	command error_t NeighborDiscovery.receive(pack* Packet)
	{
		uint32_t ind = -1;
		uint32_t emptyIndex = -1;
		
		// Ignore packets that are not from immediate neighbors
		if (Packet->TTL != MAX_TTL)
			return FAIL;
		
		// Find
		for (ind = 0; ind < NEIGHBOR_TABLE_SIZE; ind++)
		{
			// Save locations of empty indexes in case we dont have a neighbor yet
			if (emptyIndex == -1 && neighborIDs[ind] == EMPTY)
				emptyIndex = ind;
			
			if (neighborIDs[ind] == Packet->src)
				goto found;
		}
		
		// No neighbor found from this src, we have to create a place for it
		ind = emptyIndex;
		neighborIDs[ind] = Packet->src;
		
		found:
		
		// Clear waiting/time out flags
		if (Packet->protocol == PROTOCOL_PING || Packet->protocol == PROTOCOL_PINGREPLY)
		{
			neighborTable[ind] &= ~CONNECTION_WAITING_RESPONSE;
			neighborTable[ind] &= ~CONNECTION_TIMED_OUT;
		}
			
		if(Packet->protocol == PROTOCOL_PING)
		{
			// We are getting pinged by a neighbor. They can connect to us. PacketHandler will reply.
			if (neighborTable[ind] == CONNECTION_NONE)
				dbg ("Project1N", "Connection discovered:\t %d -> %d\n", Packet->src, TOS_NODE_ID);
				
			neighborTable[ind] |= CONNECTION_RECEIVE;
		}
		else if(Packet->protocol == PROTOCOL_PINGREPLY)
		{
			// The neighbor pinged us back. We have a 2 way connection.
			if ((neighborTable[ind] & CONNECTION_SEND) == 0)
				dbg("Project1N", "Conection discovered:\t %d <-> %d\n", Packet->src, TOS_NODE_ID);
			
			neighborTable[ind] |= CONNECTION_SEND;
		}
		
		return SUCCESS;
	}
	
	// Determines if a neighbor has been dropped based on lack of responses
	command void NeighborDiscovery.timeOutCheck()
	{
		uint32_t ind;
		
		for (ind = 0; ind < NEIGHBOR_TABLE_SIZE; ind++)
		{
			// Ignore empty entries
			if (neighborIDs[ind] == EMPTY)
				continue;
			
			// Ignore connectionless neighbors
			if (neighborTable[ind] == CONNECTION_NONE)
				continue;
			
			// STATE 1: Mark neighbors as waiting for a response
			if (TimeOutState)
			{
				// Mark as waiting for a response
				neighborTable[ind] |= CONNECTION_WAITING_RESPONSE;
			}
			// STATE 2: Mark neighbors who still havent pinged us as timed-out
			else
			{
				if ((neighborTable[ind] & CONNECTION_WAITING_RESPONSE) != 0)
				{
					
					if ((neighborTable[ind] & CONNECTION_TIMED_OUT) == 0)
						dbg ("Project1N", "Connection timed out:\t %d -> %d\n", TOS_NODE_ID, neighborIDs[ind]);
					
					neighborTable[ind] |= CONNECTION_TIMED_OUT;
				}
			}
		}
		
		TimeOutState = !TimeOutState;
	}
	
	command void NeighborDiscovery.printNeighbors()
	{
		uint32_t ind;
		
		dbg("Project1N", "Neighbors (%d):\n", TOS_NODE_ID);
		for (ind = 0; ind < NEIGHBOR_TABLE_SIZE; ind++)
		{
			if (neighborIDs[ind] == EMPTY)
				continue;
				
			if (neighborTable[ind] == CONNECTION_NONE)
				continue;
			
			if (neighborTable[ind] & CONNECTION_TIMED_OUT)
				dbg("Project1N", "\tNeighbor %d -/- %d\n", neighborIDs[ind], TOS_NODE_ID);
			else if (neighborTable[ind] & CONNECTION_SEND) // Assuming two way connection since we only know we can send if they told us
				dbg("Project1N", "\tNeighbor %d <-> %d\n", neighborIDs[ind], TOS_NODE_ID);
			else if (neighborTable[ind] & CONNECTION_RECEIVE)
				dbg("Project1N", "\tNeighbor %d ->  %d\n", neighborIDs[ind], TOS_NODE_ID);
		}
	}
		
}
