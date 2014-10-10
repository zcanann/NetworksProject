#include "../../packet.h"

interface NeighborDiscovery
{
	command error_t receive(pack* Packet);
	command void initialize(uint32_t* neighborTablePointer);
	
	event void discoverNeighbors();
}
