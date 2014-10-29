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
	
	event void setTestServer(uint8_t listenPort);
	event void setTestClient(uint16_t targetAddress, uint8_t sendPort, uint8_t destPort, uint16_t transfer);
	event void setAppServer();
	event void setAppClient();
}
