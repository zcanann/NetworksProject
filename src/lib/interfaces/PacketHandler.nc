#include "../../packet.h"

interface PacketHandler
{
	command void initialize(uint16_t* sequenceTableSrcPtr, uint16_t* sequenceTableSeqPtr, uint16_t* sequenceTableAgePtr);
	command error_t receive(pack* Packet);
	command bool isPacketLooping(pack *Packet);
	
	// Events
	event void forward(pack *msg, uint16_t address);
	event void sendInitial(pack *msg, uint16_t address);
	event void reply(uint16_t destination);
	event void ping(uint8_t *payload, uint16_t destination);
	event void broadCast(uint8_t *payload, uint16_t destination);
}
