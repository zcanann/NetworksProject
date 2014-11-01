#include "../../Headers/packet.h"

interface PacketHandler
{
	command void initialize();
	
	command error_t receive(pack* Packet);
	command bool isPacketDuplicate(pack *Packet);
	command void makePack(uint16_t dest, uint8_t protocol, uint8_t* payload);
	
	command error_t send(uint16_t dest, bool updateTTL);
	command error_t actuallySend(uint16_t src, uint16_t dest, pack *message);
	command void postSendTask();
	command void createAndSend(uint8_t *payload, uint16_t destination);
	command void reply(uint16_t destination);
	
	command void ageSequenceTable();
	command uint16_t getAge(uint32_t src, uint16_t seq);
	command void insertAge(uint32_t src, uint16_t seq, uint16_t age);
	command void decreaseAge(uint32_t key);
	command bool containsSrcSeqPair(uint32_t src, uint16_t seq);
	command void processSequence(pack* Package);

} // End interface
