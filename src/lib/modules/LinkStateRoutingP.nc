
#include <Timer.h>
#include "../../packet.h"
#include "../../command.h"
#include "../../linkedstate.h"
#include "../../neighbor.h"

module LinkStateRoutingP
{
	provides interface LinkStateRouting;
}
	
implementation
{
	uint8_t linkStatePacket[PACKET_MAX_PAYLOAD_SIZE8]; // Packet to send LS info
	
	uint16_t linkStates[FORWARD_TABLE_SIZE][FORWARD_TABLE_SIZE]; // Link state table
	bool existing[FORWARD_TABLE_SIZE];		// Nodes I know exist
	bool unconsidered[FORWARD_TABLE_SIZE];	// Nodes I have not considered
	
	uint16_t* neighborIDs;		// Pointer to neighbor IDs table in Node
	uint16_t* neighborTable;	// Pointer to neighbor table in Node
	
	// Resulting tables from Dijkstras algorithm
	uint16_t* forwardTableDest;	// Pointer to destination table in Node
	uint16_t* forwardTableCost;	// Pointer to cost table in Node
	uint16_t* forwardTableHop;	// Pointer to next hop table in Node
	
	
	command void LinkStateRouting.initialize(uint16_t* neighborIDsPointer, uint16_t* neighborTablePointer,
		uint16_t* forwardTableDestPointer, uint16_t* forwardTableCostPointer, uint16_t* forwardTableHopPointer)
	{
		
		neighborIDs = neighborIDsPointer;			// Set pointer to neighbor IDs table
		neighborTable = neighborTablePointer;		// Set pointer to neighbor table
		forwardTableDest = forwardTableDestPointer; // Set pointer to destination table
		forwardTableCost = forwardTableCostPointer; // Set pointer to cost table
		forwardTableHop = forwardTableHopPointer;	// Set pointer to hop table
		
		// Zero our array memory
		memset(linkStatePacket, 0, sizeof(linkStatePacket));
		memset(existing, 0, sizeof(existing));
		memset(unconsidered, 0, sizeof(unconsidered));
		memset(linkStates, 0, sizeof(linkStates));
		
	}
	
	command void LinkStateRouting.calculateRoute()
	{
		uint32_t considering;	// Node being considered
		uint32_t lowestValue;	// Determines where to consider in Dijkstra
		uint32_t hop;			// The next hop to route to
		uint32_t ind;			// Indexing variable
		
		// Clear our routing tables, we're going to recompute them from scratch
		memset(forwardTableDest, 0, sizeof(uint16_t) * FORWARD_TABLE_SIZE);
		memset(forwardTableCost, 0, sizeof(uint16_t) * FORWARD_TABLE_SIZE);
		memset(forwardTableHop, 0, sizeof(uint16_t) * FORWARD_TABLE_SIZE);
		
		// Copy all nodes we have received link states from into unconsidered
		memcpy(unconsidered, existing, sizeof(existing));
		unconsidered[TOS_NODE_ID] = FALSE;
		hop = 0;
		
		// PHASE I DIJKSTRA - Set the initial cost to each of our neighbors
		for (ind = 0; ind < NEIGHBOR_TABLE_SIZE; ind++)
		{
			// Ignore empty entries and disconnected neighbors
			if (neighborIDs[ind] == EMPTY || neighborTable[ind] == CONNECTION_NONE)
				continue;
			
			// Update routing tables
			forwardTableDest[neighborIDs[ind]] = neighborIDs[ind];
			forwardTableCost[neighborIDs[ind]] = NEIGHBOR_COST;
			forwardTableHop[neighborIDs[ind]] = neighborIDs[ind];
			
			//dbg ("Project2", "Neighbor cost initialized: %d\n", neighborIDs[ind]);
		}
		
		// PHASE II DIJKSTRA - Create routing tables
		while (TRUE)
		{
			lowestValue = 0;
			considering = NONE;
			
			// Check if Unconsidered is empty
			for (ind = 0; ind < FORWARD_TABLE_SIZE; ind++)
			{
				if (unconsidered[ind] == TRUE)
				{
					// dbg ("Project2", "Found: %d\n", ind);
					goto notEmpty;
				}
			}
			break;
			notEmpty:
			
			// Find lowest cost node. This is the one we will be considering
			for (ind = 0; ind < FORWARD_TABLE_SIZE; ind++)
			{
				// Ignore considered nodes, ignore cost infinity nodes
				if (!unconsidered[ind] || forwardTableCost[ind] == INF)
					continue;
				
				if (forwardTableCost[ind] < lowestValue || lowestValue == 0)
					considering = ind;
			}
			
			// Update the neighbor we are hopping through if that has changed
			for (ind = 0; ind < NEIGHBOR_TABLE_SIZE; ind++)
			{
				// Ignore empty entries and null connections
				if (neighborIDs[ind] == EMPTY || neighborTable[ind] == CONNECTION_NONE)
					continue;
				
				if (neighborIDs[ind] == considering)
				{
					hop = neighborIDs[ind];
				}
			}
			
			// Propagate costs from this node to linked neighbors
			for (ind = 0; ind < FORWARD_TABLE_SIZE; ind++)
			{
				if (linkStates[considering][ind] == EMPTY)
					continue;
				
				// Neighbor found, See if it is cheaper to go through this node to get there
				if (forwardTableCost[ind] == INF ||
					forwardTableCost[ind] > forwardTableCost[considering] + NEIGHBOR_COST)
				{
					// Yep its cheaper -- we should go through this node
					forwardTableDest[ind] = ind;
					forwardTableCost[ind] = forwardTableCost[considering] + NEIGHBOR_COST;
					forwardTableHop[ind] = hop;
				}
			}
			
			// Mark this node as considered
			unconsidered[considering] = FALSE;
		}
		
		//dbg ("Project2", "End Dijkstra\n");
		
		// Clear what we know exists, we will find out again later
		memset(existing, 0, sizeof(existing));
	}
	
	task void SendNeighbors()
	{
		// Send our link link state to our neighbors
		signal LinkStateRouting.sendLinkState(linkStatePacket);
		
		// Reset memory after sending
		memset(linkStatePacket, 0, sizeof(linkStatePacket));
	}
	
	// Shares neighbor info with nearby neighbors
	command void LinkStateRouting.shareLinkState()
	{
		uint16_t *destinations;
		uint32_t ind;
		uint32_t copyInd;
		bool sent = FALSE;
		
		// Zero our packet memory, as zeros will indicate lack of information
		memset(linkStatePacket, 0, sizeof(linkStatePacket));
		
		// Grab uint16 pointer to our payload since neighbors have up to 16 bits rather than 8
		destinations = (uint16_t*)&linkStatePacket[0];
		
		// Create the packet data
		for (ind = 0, copyInd = 0; ind < NEIGHBOR_TABLE_SIZE; ind++)
		{
			// Ignore empty entries and disconnected neighbors
			if (neighborIDs[ind] == EMPTY || neighborTable[ind] == CONNECTION_NONE)
				continue;
			
			// Only consider paths that are a two way connection
			if (!(neighborTable[ind] & CONNECTION_SEND) || !(neighborTable[ind] & CONNECTION_RECEIVE))
				continue;
			
			// Add the cost and dest to the payload and increment our copy index
			destinations[copyInd++ % (PACKET_MAX_PAYLOAD_SIZE16)] = neighborIDs[ind];
			
			// Mark this information as not sent yet
			sent = FALSE;
			
			// Send when we have filled up an entire packet
			if (copyInd % (PACKET_MAX_PAYLOAD_SIZE16) == 0)
			{
				// dbg ("Project2", "SendCompl: %d\n", *linkStatePacket);
				post SendNeighbors();
				sent = TRUE;
			}
		}
		
		// If we have leftover info send that too
		if (!sent)
		{
			// dbg ("Project2", "SendPartial: %d\n",*linkStatePacket);
			post SendNeighbors();
		}
	}
	
	command error_t LinkStateRouting.receive(pack* Packet)
	{
		uint16_t *destinations;
		uint16_t destID;
		uint8_t payloadIndex;
		
		// Clear waiting/time out flags
		if (Packet->protocol != PROTOCOL_LINKSTATE)
			return FAIL;
			
		// TODO: Sequence # must be > previous in the case of out of order packets
		// TODO: Memset linkstate[Packet->src][] to 0? Only if 1 packet for all info.
		
		// Grab 16 bit pointer since destinations are a 16 bit value
		destinations = (uint16_t*)&Packet->payload[0];
		
		// Insert all source/dest connected pairs that were sent in this payload
		for (payloadIndex = 0; payloadIndex < PACKET_MAX_PAYLOAD_SIZE16; payloadIndex++)
		{
			// Grab the destination
			destID = destinations[payloadIndex];
			
			// Ignore zeros in payload TODO maybe set the length of the packet instead like a normal person
			if (destID == NONE)
				continue;
			// Add source/dest pair to our array
			linkStates[Packet->src][destID] = 1;
			existing[destID] = TRUE;
		}
		
		return SUCCESS;
	}
	
	command void LinkStateRouting.printLinkState()
	{
		uint32_t nodeIndex;
		uint32_t neighborIndex;
		
		dbg ("Project2", "Link State:\n");
		for (nodeIndex = 0; nodeIndex < FORWARD_TABLE_SIZE; nodeIndex++)
		{
			for (neighborIndex = 0; neighborIndex < FORWARD_TABLE_SIZE; neighborIndex++)
			{
				if (linkStates[nodeIndex][neighborIndex] == EMPTY)
					continue;
				dbg ("Project2", "\t%d Connected to: %d\n", nodeIndex, neighborIndex);
			}
		}
	}
	
	command void LinkStateRouting.printRoutingTable()
	{
		uint32_t ind;
		
		dbg("Project2", "Route Table (%d):\n", TOS_NODE_ID);
		for (ind = 0; ind < FORWARD_TABLE_SIZE; ind++)
		{
			if (forwardTableCost[ind] == INF)
				continue;
			
			dbg ("Project2", "Cost to %d\t is %d\t through %d\n", ind, forwardTableCost[ind], forwardTableHop[ind]);
		}
	}

}
