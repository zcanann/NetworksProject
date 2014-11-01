#include "../../Headers/packet.h"

interface LinkStateRouting
{
	command void initialize();
	command error_t receive(pack* Packet);
	command void shareLinkState();
	command void calculateRoute();
	
	command void insertCostHop(uint32_t src, uint16_t cost, uint16_t hop);
	command void insertCost(uint32_t src, uint16_t cost);
	command void insertHop(uint32_t src, uint16_t hop);
	command uint16_t getRoutingCost(uint32_t src);
	command uint16_t getRoutingHop(uint32_t src);
	
	command void printLinkState();
	command void printRoutingTable();

} // End interface
