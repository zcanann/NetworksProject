#include "../../Headers/packet.h"

interface NeighborDiscovery
{
	command error_t receive(pack* Packet);
	command void initialize();
	command void timeOutCheck();
	command void printNeighbors();
	command void discoverNeighbors();

} // End interface