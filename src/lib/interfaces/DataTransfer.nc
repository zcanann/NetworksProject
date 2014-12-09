#include "../../Headers/packet.h"
#include "../../Headers/socket.h"

interface DataTransfer
{
	command void initialize(transfer_packet* TCPPacketPtr);
	command void updateTransferAmount(socket_storage_t* connectionData, uint8_t* transfer);
	command void processReply(socket_storage_t* connectionData, transfer_packet* TCPPayload);
	command void processACK(socket_storage_t* connectionData, transfer_packet* TCPPayload);
	command void fillWriteBuffer(socket_storage_t* connectionData);
	
	command void write();
	command void read();
	
	command error_t receive(pack* package);
	
} // End interface
