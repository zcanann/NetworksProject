#include "../../packet.h"

interface PacketHandler
{
	command void initialize(uint16_t* sequenceTableSrcPtr, uint16_t* sequenceTableSeqPtr, uint16_t* sequenceTableAgePtr);
	command error_t receive(pack* Packet);
	
	command bool isPacketLooping(pack *Packet);
	
	command void ageSequenceTable();
	command error_t processSequence(pack* Packet);
	
	// Events
	
	
	event void send(pack *msg, uint16_t address, bool updateTTL);
	event void createAndSend(uint8_t *payload, uint16_t destination);
	event void reply(uint16_t destination);
}
