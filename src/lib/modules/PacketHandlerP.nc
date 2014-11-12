#include "../../Headers/packet.h"
#include "../../Headers/sendInfo.h"
#include "../../Headers/neighbor.h"
#include "../../Headers/command.h"

module PacketHandlerP
{
	provides interface PacketHandler;
	uses interface AMPacket;
	uses interface AMSend;
	uses interface Packet;
	uses interface Random;
	
	uses interface Hashmap<uint16_t> as sequenceTable;
	uses interface Hashmap<uint32_t> as routingTable;
	
	uses interface Timer<TMilli> as sendTimer;
	uses interface Queue<sendInfo*>;
	uses interface Pool<sendInfo>;

} // End module

implementation
{
	pack sendPackage;
	uint8_t pingPacket[PACKET_MAX_PAYLOAD_SIZE8];
	
	uint16_t SEQUENCE_NUM = 0;
	bool busy = FALSE;
	message_t pkt;
	
	command void PacketHandler.initialize()
	{
		
	}
	
	//////////////////////////////////////////////////
	// SEQUENCE TABLE STUFF
	//////////////////////////////////////////////////
	
	command uint16_t PacketHandler.getAge(uint32_t src, uint16_t seq)
	{
		uint32_t key = (src << 16) | seq;		// Combine src and seq to get key
		return (call sequenceTable.get(key));	// Return value from table
		
	} // End getAge
	
	command void PacketHandler.insertAge(uint32_t src, uint16_t seq, uint16_t age)
	{
		uint32_t key = (src << 16) | seq;		// Combine src and seq to get key
		call sequenceTable.insert(key, age);	// Insert value into table
		
	} // End insertAge
	
	command void PacketHandler.decreaseAge(uint32_t key)
	{
		uint16_t age = call sequenceTable.get(key) - 1;	// Age entry
		
		if (age > 0)
		{
			call sequenceTable.insert(key, age);	// Still alive, update value
		}
		else
		{
			call sequenceTable.remove(key);	// Out of time, remove entry
		}
		
	} // End decreaseAge
	
	command bool PacketHandler.containsSrcSeqPair(uint32_t src, uint16_t seq)
	{
		uint32_t key = (src << 16) | seq;			// Combine src and seq to get key
		return (call sequenceTable.contains(key));	// Test to see if it exists
		
	} // End containsSrcSeqPair
	
	command void PacketHandler.processSequence(pack* Package)
	{
		call PacketHandler.ageSequenceTable();	// Age everything as a precaution (aging also done via sparse timer)
		call PacketHandler.insertAge(Package->src, Package->seq, SEQUENCE_TABLE_MAX_AGE);	// Insert the sequence and age
		
	} // End processSequence
	
	// Ages each entry in the sequence table
	command void PacketHandler.ageSequenceTable()
	{
		uint32_t *keys;	//Pointer to seq/src key
		uint32_t keyInd;
		
		// Fetch all keys
		keys = call sequenceTable.getKeys();
		
		// Age all entries
		for (keyInd = 0; keyInd < SEQUENCE_TABLE_SIZE; keyInd++)
		{
			if (keys[keyInd] == EMPTY)
				continue;
			
			call PacketHandler.decreaseAge(keys[keyInd]);
		}
		
	} // End ageSequenceTable
	
	//////////////////////////////////////////////////
	// PACKET RECEIVING / MISC
	//////////////////////////////////////////////////
	
	// Receives a packet and figures out what to do with it
	command error_t PacketHandler.receive(pack* Package)
	{
		// Repeat packet check called externally from Node.nc
		
		// Handle packet based on protocol
		if(Package->protocol == PROTOCOL_PING)
		{
			// Reply to packet
			call PacketHandler.reply(Package->src);
			
			// Do not process single-ping broadcast packets (lots of speed gained here)
			if (Package->dest == UNSPECIFIED)
				return FAIL;
			
			// Update sequence table
			call PacketHandler.processSequence(Package);
			
			if (Package->dest == TOS_NODE_ID)
			{
				// Received packet addressed to this node!
				dbg ("Project2", "\tReceived packet %d->%d. Payload: %s\n", Package->src, TOS_NODE_ID, Package->payload);
			}
			else
			{
				// Received packet addressed to another node; forward it
				sendPackage = *Package;
				call PacketHandler.send(AM_BROADCAST_ADDR, TRUE);
			}
			
			return SUCCESS;
		}
		else if (Package->protocol == PROTOCOL_PINGREPLY)
		{
			
		}
		else if (Package->protocol == PROTOCOL_LINKSTATE)
		{
			call PacketHandler.processSequence(Package);
			sendPackage = *Package;
			call PacketHandler.send(AM_BROADCAST_ADDR, TRUE);
			return SUCCESS;
		}
		
		return FAIL;
		
	} // End receive
	
	command bool PacketHandler.isPacketDuplicate(pack *Package)
	{
		
		if (call PacketHandler.containsSrcSeqPair(Package->src, Package->seq))
		{
			return TRUE;	// Have received this packet already
		}
		
		return FALSE;		// Packet is not a looping packet
		
	} // End isPacketDuplicate
	
	command void PacketHandler.makePack(uint16_t dest, uint8_t protocol, uint8_t* payload)
	{
		// Wrap sequence number
		if (++SEQUENCE_NUM > 65000)
			SEQUENCE_NUM = 0;
		
		sendPackage.src = TOS_NODE_ID;
		sendPackage.dest = dest;
		sendPackage.TTL = MAX_TTL;
		sendPackage.seq = SEQUENCE_NUM;
		sendPackage.protocol = protocol;
		memcpy(sendPackage.payload, payload, PACKET_MAX_PAYLOAD_SIZE8);
		
	} // End makePack
	
	//////////////////////////////////////////////////
	// PACKET SENDING
	//////////////////////////////////////////////////
	
	// Creates a packet to send, default to broadcast -- this will be replaced if we have a routing table entry.
	command void PacketHandler.createAndSend(uint8_t *payload, uint16_t destination)
	{
		call PacketHandler.makePack(destination, PROTOCOL_PING, payload);
		call PacketHandler.send(AM_BROADCAST_ADDR, FALSE);
		
	} // End createAndSend
	
	// Sends ping reply
	command void PacketHandler.reply(uint16_t destination)
	{
		call PacketHandler.makePack(destination, PROTOCOL_PINGREPLY, pingPacket);
		call PacketHandler.send(destination, FALSE);
		
	} // End reply
	
	// A random element of delay is included to prevent congestion.
	command void PacketHandler.postSendTask()
	{
		if(!call sendTimer.isRunning())
		{
			call sendTimer.startOneShot((call Random.rand16() % 200) + 500);
		}
	
	} // End postSendTask

	command error_t PacketHandler.send(uint16_t dest, bool updateTTL)
	{
		sendInfo *input;
		
		if(call Pool.empty())
			return FAIL;
		
		// Link state packets need to go over the entire network, so no TTL reduction for them
		if (updateTTL) // && Package->protocol != PROTOCOL_LINKSTATE)
			sendPackage.TTL--;
		
		// TTL Check
		if (sendPackage.TTL <= 0)
			return SUCCESS;
		
		// Replace broadcast address with next hop if applicable
		if (sendPackage.dest != UNSPECIFIED && dest == AM_BROADCAST_ADDR && sendPackage.protocol == PROTOCOL_PING) // ie not neighbor discovery pings
		{
			if (call routingTable.contains(sendPackage.dest))
			{
				dest = (uint16_t)(call routingTable.get(sendPackage.dest));
				//dbg("Project2", "Replaced broadcast with destination: %d\n", address);
			}
			else
			{
				dbg("Project2", "\tEntry for %d not found in routing table. Aborting.\n", sendPackage.dest);
				return SUCCESS;
			}
		}
		
		if (dest != AM_BROADCAST_ADDR && sendPackage.protocol == PROTOCOL_PING)
			dbg("Project2", "\tDelivering to hopping through %d to reach %d\n", dest, sendPackage.dest);
		
		input = call Pool.get();
		input->packet = sendPackage;
		input->dest = dest;
		
		if (call Queue.enqueue(input) == FAIL)
			return FAIL;
		
		call PacketHandler.postSendTask();
		
		return SUCCESS;
		
	} // End send
	
	task void sendBufferTask()
	{
		sendInfo *info;
		
		if(!call Queue.empty() && !busy)
		{
			info = call Queue.head(); // Peak
			
			if(SUCCESS == call PacketHandler.actuallySend(info->src,info->dest, &(info->packet)))
			{
				// Release resources used
	            call Queue.dequeue();
	            call Pool.put(info);
			}
		}
		
		if(!call Queue.empty())
		{
			call PacketHandler.postSendTask();
		}
		
	} // End sendBufferTask

	event void sendTimer.fired()
	{
		post sendBufferTask();
		
	} // End sendTimer
	
	command error_t PacketHandler.actuallySend(uint16_t src, uint16_t dest, pack *message)
	{
		pack* msg;
		
		if(busy)
		{
			dbg("genDebug", "The radio is busy");
			return EBUSY;
		}
		
		msg = (pack*)(call Packet.getPayload(&pkt, sizeof(pack)));			
		*msg = *message;
		
		if(call AMSend.send(dest, &pkt, sizeof(pack)) == SUCCESS)
		{
			busy = TRUE;
			return SUCCESS;
		}
		
		dbg("genDebug","The radio is busy, or something\n");
		return FAIL;
		
	} // End actuallySend

	event void AMSend.sendDone(message_t* msg, error_t error)
	{
		// Clear Flag, we can send again.
		if(&pkt == msg)
		{
			busy = FALSE;
			call PacketHandler.postSendTask();
		}
		
	} // End sendDone

} // End implementation
