
#include <Timer.h>
#include "../../packet.h"
#include "../../command.h"
#include "../../neighbor.h"

module NeighborDiscoveryP
{
	provides interface NeighborDiscovery;
	
	uses interface Hashmap<uint16_t> as Neighbors;
	uses interface Timer<TMilli> as DiscoveryTimer;
	uses interface Timer<TMilli> as TimeOutTimer;
	
	uses interface Random;
}
	
implementation
{
	uint32_t* neighborTable;	// Pointer to neighbor table in Node
	bool TimeOutState = TRUE;	// Alternates state of waiting for a response and declaring a time-out
	
	command void NeighborDiscovery.initialize(uint32_t* neighborTablePointer)
	{
		uint32_t Period;
		
		// Set pseudo random timer value
		Period = (call Random.rand16() % 200) + 1999;
		
		// Set pointer to neighbor table
		neighborTable = neighborTablePointer;
		memset(neighborTable, 0, NEIGHBOR_TABLE_SIZE);
		
		// Start timers
		call DiscoveryTimer.startPeriodic(Period);
		call TimeOutTimer.startPeriodic(Period * 8);
	}
	
	// Discovers nearby neighbors
	event void DiscoveryTimer.fired()
	{
		// Discover nearby neighbors
 		// dbg("Project1N", "Discovery timer event fired\n");
 		
 		signal NeighborDiscovery.discoverNeighbors();
	}
	
	// Determines if a neighbor has been dropped based on lack of responses
	event void TimeOutTimer.fired()
	{
		uint32_t ecx;
		
		for (ecx = 0; ecx < NEIGHBOR_TABLE_SIZE; ecx++)
		{
			// Ignore empty entries
			if (neighborTable[ecx] == CONNECTION_NONE)
				continue;
			
			// STATE 1: Mark neighbors as waiting for a response
			if (TimeOutState)
			{
				// Mark as waiting for a response
				neighborTable[ecx] |= CONNECTION_WAITING_RESPONSE;
			}
			// STATE 2: Mark neighbors who still havent pinged us as timed-out
			else
			{
				if ((neighborTable[ecx] & CONNECTION_WAITING_RESPONSE) != 0)
				{
					
					if ((neighborTable[ecx] & CONNECTION_TIMED_OUT) == 0)
						dbg ("Project1N", "Connection timed out:\t %d -> %d\n", TOS_NODE_ID, ecx);
					
					neighborTable[ecx] |= CONNECTION_TIMED_OUT;
				}
			}
		}
		
		TimeOutState = !TimeOutState;
	}
	
	command error_t NeighborDiscovery.receive(pack* Packet)
	{
		// Ignore packets that are not from immediate neighbors
		if (Packet->TTL != MAX_TTL)
			return FAIL;
		
		// Clear waiting/time out flags
		if (Packet->protocol == PROTOCOL_PING || Packet->protocol == PROTOCOL_PINGREPLY)
		{
			neighborTable[Packet->src] &= ~CONNECTION_WAITING_RESPONSE;
			neighborTable[Packet->src] &= ~CONNECTION_TIMED_OUT;
		}
			
		if(Packet->protocol == PROTOCOL_PING)
		{
			// We are getting pinged by a neighbor. They can connect to us. PacketHandler will reply.
			if (neighborTable[Packet->src] == CONNECTION_NONE)
				dbg ("Project1N", "Connection discovered:\t %d -> %d\n", Packet->src, TOS_NODE_ID);
				
			neighborTable[Packet->src] |= CONNECTION_RECEIVE;
		}
		else if(Packet->protocol == PROTOCOL_PINGREPLY)
		{
			// The neighbor pinged us back. We have a 2 way connection.
			if ((neighborTable[Packet->src] & CONNECTION_SEND) == 0)
				dbg("Project1N", "Conection discovered:\t %d <-> %d\n", Packet->src, TOS_NODE_ID);
			
			neighborTable[Packet->src] |= CONNECTION_SEND;
		}
		
		return SUCCESS;
	}
	
}
