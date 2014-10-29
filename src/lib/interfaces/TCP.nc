#include "../../packet.h"
#include "socket.h"

interface TCP
{
	command error_t receive(pack* Packet);
	command void initialize();
	command uint32_t getKeyFromHeaderData(uint16_t dest, uint8_t srcPort, uint8_t destPort);
	
	event void createAndSend(socket_storage_t *TCPHeader, uint16_t destination);
	
	// TCP connection table functions
	event uint32_t* getConnectionKeys();
	event socket_storage_t* getConnectionStatePTR(uint32_t connectionKey);
	event void setConnectionPTR(uint32_t connectionKey, uint8_t initialState);
	
	event socket_storage_t* getConnectionState(uint32_t connectionKey);
	event bool containsConnection(uint32_t connectionKey);
	
	event void updateHeader(uint32_t connectionKey, uint16_t src, uint8_t srcPort, uint16_t dest, uint8_t destPort);
	event void setConnectionState(uint32_t connectionKey, uint8_t state);
	
}
