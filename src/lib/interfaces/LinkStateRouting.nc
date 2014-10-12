#include "../../packet.h"

interface LinkStateRouting
{
	command void initialize(uint16_t* neighborIDsPointer, uint16_t* neighborTablePointer,
		uint16_t* forwardTableDestPointer, uint16_t* forwardTableCostPointer, uint16_t* forwardTableHopPointer);
	command error_t receive(pack* Packet);
	command void shareLinkState();
	command void calculateRoute();
	
	command void printLinkState();
	command void printRoutingTable();
	
	event void sendLinkState(uint8_t *payload);
}
