#include "../../Headers/packet.h"

interface CommandHandler
{
	command void initialize();
	command error_t receive(pack* Packet);
	
	command void ping(uint8_t *payload, uint16_t destination);
	command void printNeighbors();
	command void printRouteTable();
	command void printLinkState();
	command void printDistanceVector();
	
	command void setTestServer(uint8_t listenPort);
	command void setTestClient(uint16_t targetAddress, uint8_t sendPort, uint8_t destPort, uint8_t* transfer);
	command void clientClose(uint16_t targetAddress, uint8_t sendPort, uint8_t destPort);
	command void setAppServer();
	command void setAppClient();
	
	command void sendHello(uint16_t targetAddress, uint8_t sendPort, uint8_t destPort, uint8_t*msg);
	command void sendMsg(uint16_t targetAddress, uint8_t sendPort, uint8_t destPort, uint8_t*msg);
	command void sendWhisper(uint16_t targetAddress, uint8_t sendPort, uint8_t nameLen, uint8_t*user, uint8_t*msg);
	command void listUsers();
	
} // End interface
