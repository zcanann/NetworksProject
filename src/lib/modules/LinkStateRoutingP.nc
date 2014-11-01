#include "../../Headers/packet.h"
#include "../../Headers/command.h"
#include "../../Headers/linkstate.h"
#include "../../Headers/neighbor.h"

module LinkStateRoutingP
{
	provides interface LinkStateRouting;
	uses interface PacketHandler;
	
	uses interface Hashmap<uint16_t> as neighborTable;
	uses interface Hashmap<uint32_t> as routingTable;

} // End module
	
implementation
{
	uint8_t linkStatePacket[PACKET_MAX_PAYLOAD_SIZE8]; // Packet to send LS info
	
	uint16_t linkStates[ROUTING_TABLE_SIZE][ROUTING_TABLE_SIZE]; // Link state table
	uint16_t compareBuffer[ROUTING_TABLE_SIZE];	// Used to compare differences in link states
	uint16_t hopThrough[ROUTING_TABLE_SIZE];	// Used to figure out next hop in Dijkstras
	bool unconsidered[ROUTING_TABLE_SIZE];		// Nodes I have not considered
	bool existing[ROUTING_TABLE_SIZE];			// Nodes I know exist
	
	bool NeighborsChanged = FALSE;
	bool LSChanged = FALSE;	// Indicates if Dijkstra needs to run again due to changed LS
	
	command void LinkStateRouting.initialize()
	{
		// Zero our array memory
		memset(linkStatePacket, 0, sizeof(linkStatePacket));
		memset(linkStates, 0, sizeof(linkStates));
		memset(compareBuffer, 0, sizeof(compareBuffer));
		memset(hopThrough, 0, sizeof(hopThrough));
		memset(existing, 0, sizeof(existing));
		memset(unconsidered, 0, sizeof(unconsidered));
		
	} // End initialize
	
	command void LinkStateRouting.neighborChanged()
	{
		NeighborsChanged = TRUE; // Indicate that a neighbor has changed
		
	} // End neighborChanged
	
	command void LinkStateRouting.insertCostHop(uint32_t src, uint16_t cost, uint16_t hop)
	{
		uint32_t val = ((uint32_t)cost << 16) | hop;	// Combine values into one 32 bit int
		call routingTable.insert(src, val);				// Store it
		
	} // End initialize
	
	command void LinkStateRouting.insertCost(uint32_t src, uint16_t cost)
	{
		uint32_t val = (call routingTable.get(src));	// Get hop portion
		val = (cost << 16) | ((uint16_t)val);			// combine cost + hop portion
		call routingTable.insert(src, val);				// Insert new value
		
	} // End insertCost
	
	command void LinkStateRouting.insertHop(uint32_t src, uint16_t hop)
	{
		uint32_t val = (call routingTable.get(src));	// Get current val (cost + hops)
		val = val ^ (uint16_t)val;						// Clear hop portion
		val = val | hop;								// Insert new hop portion
		call routingTable.insert(src, val);				// Insert new value
		
	} // End getRoutingCost
	
	command uint16_t LinkStateRouting.getRoutingCost(uint32_t src)
	{
		return (call routingTable.get(src) >> 16);		// Retrieve cost portion
		
	} // End getRoutingCost
	
	command uint16_t LinkStateRouting.getRoutingHop(uint32_t src)
	{
		return (uint16_t)(call routingTable.get(src));	// Retrieve hop portion
		
	} // End getRoutingHop
	
	command void LinkStateRouting.calculateRoute()
	{
		// Neighbor table stuff
		uint32_t *NeighborKeys;
		uint16_t keyInd;
		uint16_t connectionState;
		
		// Routing table stuff
		uint32_t *RoutingKeys;
		uint16_t routingCost;
		uint16_t consideringCost;
		
		uint16_t considering;	// Node being considered
		uint16_t lowestValue;	// Determines where to consider in Dijkstra
		uint16_t ind;			// Indexing variable
		
		// No need to do algorithm if our link states have not changed
		if (!LSChanged)
			return;
		
		NeighborKeys = call neighborTable.getKeys();
		RoutingKeys = call routingTable.getKeys();
		
		// Clear our routing tables, we're going to recompute them from scratch
		call routingTable.clear();
		memset(hopThrough, 0, sizeof(uint16_t) * ROUTING_TABLE_SIZE);
		
		// Copy all nodes we know exist into unconsidered
		memcpy(unconsidered, existing, sizeof(unconsidered));
		unconsidered[TOS_NODE_ID] = FALSE;
		
		if (TOS_NODE_ID == 2)
		{
			dbg("Project2", "Begin Dijkstra\n");
		}
		
		// PHASE I DIJKSTRA - Set the initial cost to each of our neighbors
		for (keyInd = 0; keyInd < NEIGHBOR_TABLE_SIZE; keyInd++)
		{
			// Ignore empty entries
			if (NeighborKeys[keyInd] == EMPTY)
				continue;
			
			// Retrieve connection state
			connectionState = call neighborTable.get(NeighborKeys[keyInd]);
			
			// Ignore bad neighbors
			if (connectionState == CONNECTION_NONE || !(connectionState & CONNECTION_SEND) ||
				!(connectionState & CONNECTION_RECEIVE) || (connectionState & CONNECTION_TIMED_OUT))
				continue;
			
			// Update routing table
			call LinkStateRouting.insertCostHop(NeighborKeys[keyInd], NEIGHBOR_COST, NeighborKeys[keyInd]);
			
			//dbg ("Project2", "Neighbor cost initialized for: %d\n", NeighborKeys[keyInd]);
		}
		
		// PHASE II DIJKSTRA - Create routing tables
		while (TRUE)
		{
			lowestValue = 0;
			considering = NONE;
			
			// Check if Unconsidered is empty
			for (ind = 0; ind < ROUTING_TABLE_SIZE; ind++)
			{
				if (unconsidered[ind] == TRUE)
				{
					//dbg ("Project2", "Found: %d\n", ind);
					goto notEmpty;
				}
			}
			break;
			notEmpty:
			
			// Find lowest cost node. This is the one we will be considering
			for (keyInd = 0; keyInd < ROUTING_TABLE_SIZE; keyInd++)
			{
				if (RoutingKeys[keyInd] == EMPTY)
					continue;
				
				// If we have an entry, grab the cost. Otherwise cost is infinity
				if (call routingTable.contains(RoutingKeys[keyInd]))
					routingCost = call LinkStateRouting.getRoutingCost(RoutingKeys[keyInd]);
				else
					routingCost = INF;
				
				// Ignore considered nodes, ignore cost infinity nodes
				if (!unconsidered[RoutingKeys[keyInd]] || routingCost == INF)
					continue;
				
				if (routingCost < lowestValue || lowestValue == 0)
				{
					considering = RoutingKeys[keyInd];
					lowestValue = routingCost;
				}
				
			}
			
			if (considering == NONE)
				break;
			
			//dbg ("Project2", "CONSIDERING: %d\n", considering);
			
			// Update the neighbor we are hopping through if that has changed
			if (call routingTable.contains(considering))
			{
				// Retrieve connection state
				connectionState = call neighborTable.get(considering);
				
				// Ignore bad neighbors
				if (connectionState == CONNECTION_NONE || !(connectionState & CONNECTION_SEND) ||
				!(connectionState & CONNECTION_RECEIVE) || (connectionState & CONNECTION_TIMED_OUT))
				{
					// Im too lazy to reverse the logic above.
				}
				else
				{
					hopThrough[considering] = considering;
				}
			}
			
			// Propagate costs and neighbor hop from this node to other nodes
			for (ind = 0; ind < ROUTING_TABLE_SIZE; ind++)
			{
				
				if (linkStates[considering][ind] == EMPTY)
					continue;
				
				// If we have an entry, grab the cost. Otherwise cost is infinity
				if (call routingTable.contains(ind))
				{
					routingCost = call LinkStateRouting.getRoutingCost(ind);
				}
				else
				{
					routingCost = INF;
				}
				
				// If we have an entry, grab the cost. Otherwise cost is infinity
				if (call routingTable.contains(considering)) //TODO: Changed from ind to considering, if issues that is why
				{
					consideringCost = call LinkStateRouting.getRoutingCost(considering) + NEIGHBOR_COST;
				}
				else
				{
					consideringCost = NEIGHBOR_COST;
				}
				
				// Neighbor found, See if it is cheaper to go through this node to get there
				if (routingCost == INF || consideringCost < routingCost)
				{
					// Propagate neighbor hop as well
					hopThrough[ind] = hopThrough[considering];
					
					// Yep its cheaper -- we should go through this node
					call LinkStateRouting.insertCostHop(ind, consideringCost, hopThrough[ind]);
					//dbg ("Project2", "\tINSERTED NODE: %d to COST: %d HOP:%d:\n", ind, consideringCost, nextHop);
				}
			}
			
			call LinkStateRouting.insertCostHop(TOS_NODE_ID, NONE, TOS_NODE_ID);	// Update value for self as being free
			unconsidered[considering] = FALSE;				// Mark this node as considered
			
		}
		
		//dbg ("Project2", "End Dijkstra\n");
		LSChanged = FALSE;
		
	} // End calculateRoute
	
	task void SendNeighbors()
	{
		// Send our link link state to our neighbors
		call PacketHandler.makePack(UNSPECIFIED, PROTOCOL_LINKSTATE, linkStatePacket);
		call PacketHandler.send(AM_BROADCAST_ADDR, FALSE);
		
		// Reset memory after sending
		memset(linkStatePacket, 0, sizeof(linkStatePacket));
		
	} // End SendNeighbors
	
	// Shares neighbor info with nearby neighbors
	command void LinkStateRouting.shareLinkState(bool forcedShare)
	{
		uint16_t *destinations;
		uint32_t *keys;
		uint32_t keyInd;
		uint32_t copyInd;
		uint16_t connectionState;
		bool unsentData = FALSE;
		
		if (!forcedShare)
		{
			if (!NeighborsChanged)
				return;
			
			NeighborsChanged = ! NeighborsChanged;
		}
		
		// Zero our packet memory, as zeros will indicate lack of information
		memset(linkStatePacket, 0, sizeof(linkStatePacket));
		
		// Grab uint16 pointer to our payload since neighbors have up to 16 bits rather than 8
		destinations = (uint16_t*)&linkStatePacket[0];
		
		keys = call neighborTable.getKeys();
		
		// Create the packet data
		for (keyInd = 0, copyInd = 0; keyInd < NEIGHBOR_TABLE_SIZE; keyInd++)
		{
			// Ignore empty entries
			if (keys[keyInd] == EMPTY)
				continue;
			
			// Retrieve connection state
			connectionState = call neighborTable.get(keys[keyInd]);
			
			// Ignore conectionless neighbors
			if (connectionState == CONNECTION_NONE)
				continue;
			
			// Only consider paths that are a two way connection (both send and recv)
			if (!(connectionState & CONNECTION_SEND) || !(connectionState & CONNECTION_RECEIVE) || (connectionState & CONNECTION_TIMED_OUT))
				continue;
			
			// Add the cost and dest to the payload and increment our copy index
			destinations[copyInd++ % (PACKET_MAX_PAYLOAD_SIZE16)] = keys[keyInd];
			
			// Mark this information as not sent yet
			unsentData = TRUE;
			
			// Send when we have filled up an entire packet
			if (copyInd % (PACKET_MAX_PAYLOAD_SIZE16) == 0)
			{
				// dbg ("Project2", "SendCompl: %d\n", *linkStatePacket);
				post SendNeighbors();
				unsentData = FALSE;
			}
		}
		
		// If we have leftover info send that too
		if (unsentData)
		{
			// dbg ("Project2", "SendPartial: %d\n",*linkStatePacket);
			post SendNeighbors();
		}
		
	} // End shareLinkState
	
	command error_t LinkStateRouting.receive(pack* Packet)
	{
		uint16_t *destinations;
		uint16_t destID;
		uint8_t payloadIndex;
		uint16_t ind;
		
		// Only link state allowed
		if (Packet->protocol != PROTOCOL_LINKSTATE)
			return FAIL;
		
		// Copy the current link state for this node to check for differences later.
		memcpy(compareBuffer, linkStates[Packet->src], sizeof(uint16_t) * ROUTING_TABLE_SIZE);
		
		// TODO: Sequence # must be > previous in the case of out of order packets, though the program will figure this out fast anyways
		// Clear link state data and replace with the new data in the packet
		memset(linkStates[Packet->src], 0, sizeof(uint16_t) * ROUTING_TABLE_SIZE);
		
		// We know this src exists now
		existing[Packet->src] = TRUE;
		
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
		}
		
		// Look for changes so we know if we need to run Dijkstra's
		for (ind = 0; ind < ROUTING_TABLE_SIZE; ind++)
		{
			if (compareBuffer[ind] != linkStates[Packet->src][ind])
			{
				if (TOS_NODE_ID == 2)
					dbg ("Project2", "\tLS changed! %d to %d at %d, %d\n", compareBuffer[ind],linkStates[Packet->src][ind], Packet->src, ind);
				LSChanged = TRUE;
				return SUCCESS;
			}
		}
		
		//if (!memcmp(compareBuffer, linkStates[Packet->src], sizeof(uint16_t) * ROUTING_TABLE_SIZE))
		{
			
		}
		return SUCCESS;
		
	} // End receive
	
	command void LinkStateRouting.printLinkState()
	{
		uint32_t nodeIndex;
		uint32_t neighborIndex;
		
		dbg ("Project2", "Link State:\n");
		for (nodeIndex = 0; nodeIndex < ROUTING_TABLE_SIZE; nodeIndex++)
		{
			for (neighborIndex = 0; neighborIndex < ROUTING_TABLE_SIZE; neighborIndex++)
			{
				if (linkStates[nodeIndex][neighborIndex] == EMPTY)
					continue;
				dbg ("Project2", "\tLink State: %d <-> %d\n", nodeIndex, neighborIndex);
			}
		}
	} // End printLinkState
	
	command void LinkStateRouting.printRoutingTable()
	{
		uint32_t *routingKeys;
		uint32_t keyInd;
		
		uint16_t routingCost;
		uint16_t routingHop;
		
		routingKeys = call routingTable.getKeys();
		
		dbg("Project2", "Route Table (%d):\n", TOS_NODE_ID);
		for (keyInd = 0; keyInd < ROUTING_TABLE_SIZE; keyInd++)
		{
			if (routingKeys[keyInd] == EMPTY)
				continue;
			
			routingHop = call LinkStateRouting.getRoutingHop(routingKeys[keyInd]);
			routingCost = call LinkStateRouting.getRoutingCost(routingKeys[keyInd]);
			
			dbg ("Project2", "\tCost to %d\t is %d\t through %d\n", routingKeys[keyInd], routingCost, routingHop);
		}
		
	} // End printRoutingTable

} // End implementation
