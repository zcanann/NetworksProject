#include "../../packet.h"

interface NeighborDiscovery
{
	command error_t receive(pack* Packet);
	command void initialize(uint16_t* neighborIDsPointer, uint16_t* neighborTablePointer);
	command void timeOutCheck();
	command void printNeighbors();
	
	event void discoverNeighbors();
}
