#include "../../packet.h"

interface NeighborDiscovery
{
	command error_t receive(pack* Packet);
	command void initialize();
	command void timeOutCheck();
	command void printNeighbors();
	
	event void discoverNeighbors();
	event uint32_t* getNeighborKeys();
	event uint16_t getNeighborConnection(uint32_t src);
	event void insertNeighbor(uint32_t src, uint16_t connection);
	event bool containsNeighbor(uint32_t src);
	event void neighborChanged();
}
