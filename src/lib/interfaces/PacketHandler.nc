#include "../../packet.h"

interface PacketHandler
{
	command void initialize();
	command error_t receive(pack* Packet);
	
	command bool isPacketDuplicate(pack *Packet);
	
	command void ageSequenceTable();
	command error_t processSequence(pack* Packet);
	
	// Events
	event void send(pack *msg, uint16_t address, bool updateTTL);
	event void createAndSend(uint8_t *payload, uint16_t destination);
	event void reply(uint16_t destination);
	
	event uint32_t* getSeqSrcKeys();
	event uint16_t getAge(uint32_t src, uint16_t seq);
	event void insertAge(uint32_t src, uint16_t seq, uint16_t age);
	event void decreaseAge(uint32_t key);
	event bool containsSrcSeqPair(uint32_t src, uint16_t seq);
	event bool containsSrcSeqKey(uint32_t key);
}
