#include "../../packet.h"

interface CommandHandler
{
	command error_t receive(pack* Packet);
	command error_t processCommand(pack *Packet);
	
	// Events
	// event void forward(pack *msg, uint16_t address);
	// event void ping(uint8_t *payload, uint16_t destination);
	event void broadCast(uint8_t *payload, uint16_t destination);
	
	event void printNeighbors();
	event void printRouteTable();
	event void printLinkState();
	event void printDistanceVector();
	
	event void setTestServer();
	event void setTestClient();
	event void setAppServer();
	event void setAppClient();
}
