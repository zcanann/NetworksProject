#include "../../Headers/packet.h"

interface CommandHandler
{
	command error_t receive(pack* Packet);
	command error_t processCommand(pack *Packet);
	
	command void broadCast(uint8_t *payload, uint16_t destination);
	
	command void printNeighbors();
	command void printRouteTable();
	command void printLinkState();
	command void printDistanceVector();
	
	command void setTestServer(uint8_t listenPort);
	command void setTestClient(uint16_t targetAddress, uint8_t sendPort, uint8_t destPort, uint16_t transfer);
	command void setAppServer();
	command void setAppClient();
	
} // End interface
