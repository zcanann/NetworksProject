#include "../../packet.h"

interface LinkStateRouting
{
	// COMMANDS
	command void initialize();
	command error_t receive(pack* Packet);
	command void shareLinkState();
	command void calculateRoute();
	
	command void printLinkState();
	command void printRoutingTable();
	
	// EVENTS
	event void sendLinkState(uint8_t *payload);
	
	// Neighbor table functions
	/*event uint32_t* getNeighborKeys();
	event uint16_t getNeighborConnection(uint32_t src);
	event void insertNeighbor(uint32_t src, uint16_t connection);
	event bool containsNeighbor(uint32_t src);*/
	
	// Routing table functions
	/*event uint32_t* getRoutingKeys();
	event uint16_t getRoutingCost(uint32_t src);
	event uint16_t getRoutingHop(uint32_t src);
	event void clearRoutingTable();
	event void insertCostHop(uint32_t src, uint16_t cost, uint16_t hop);
	event void insertCost(uint32_t src, uint16_t cost);
	event void insertHop(uint32_t src, uint16_t hop);
	event bool containsNode(uint32_t src);*/
}
