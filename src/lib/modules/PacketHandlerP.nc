#include "../../packet.h"
#include "../../neighbor.h"
#include "../../command.h"

module PacketHandlerP
{
	provides interface PacketHandler;
}

implementation
{
	command void PacketHandler.initialize()
	{
		
	}
	
	// Receives a packet and figures out what to do with it
	command error_t PacketHandler.receive(pack* Packet)
	{
		// Repeat packet check called externally from Node.nc
		
		// Handle packet based on protocol
		if(Packet->protocol == PROTOCOL_PING)
		{
			// Reply to packet
			signal PacketHandler.reply(Packet->src);
			
			// Do not process single-ping broadcast packets (lots of speed gained here)
			if (Packet->dest == UNSPECIFIED)
				return FAIL;
			
			// Update sequence table
			call PacketHandler.processSequence(Packet);
			
			if (Packet->dest == TOS_NODE_ID)
			{
				// Received packet addressed to this node!
				dbg ("Project2", "\tReceived packet %d->%d. Payload: %s\n", Packet->src, TOS_NODE_ID, Packet->payload);
			}
			else
			{
				// Received packet addressed to another node; forward it
				signal PacketHandler.send(Packet, AM_BROADCAST_ADDR, TRUE);
			}
			
			return SUCCESS;
		}
		else if (Packet->protocol == PROTOCOL_PINGREPLY)
		{
			
		}
		else if (Packet->protocol == PROTOCOL_LINKSTATE)
		{
			call PacketHandler.processSequence(Packet);
			signal PacketHandler.send(Packet, AM_BROADCAST_ADDR, TRUE);
			return SUCCESS;
		}
		
		return FAIL;
		
	}
	
	command error_t PacketHandler.processSequence(pack* Packet)
	{
		// Age everything as a precaution (aging also done via sparse timer)
		call PacketHandler.ageSequenceTable();
		
		// Insert the sequence and age
		signal PacketHandler.insertAge(Packet->src, Packet->seq, SEQUENCE_TABLE_MAX_AGE);
		
		return SUCCESS;
	}
	
	// Ages each entry in the sequence table
	command void PacketHandler.ageSequenceTable()
	{
		uint32_t *keys;	//Pointer to seq/src key
		uint32_t keyInd;
		
		// Fetch all keys
		keys = signal PacketHandler.getSeqSrcKeys();
		
		// Age all entries
		for (keyInd = 0; keyInd < SEQUENCE_TABLE_SIZE; keyInd++)
		{
			if (keys[keyInd] == EMPTY)
				continue;
			
			signal PacketHandler.decreaseAge(keys[keyInd]);
		}
	}
	
	command bool PacketHandler.isPacketDuplicate(pack *Packet)
	{
		// Check SRC/SEQ pair to see if we have received this packet already
		if (signal PacketHandler.containsSrcSeqPair(Packet->src, Packet->seq))
		{
			//dbg ("Project1F", "\tDenied packet %d->%d. Payload: %s\n", Packet->src, TOS_NODE_ID, Packet->payload);
			return TRUE;
		}
		//dbg ("Project1F", "\tAccpted packet %d->%d. Payload: %s\n", Packet->src, TOS_NODE_ID, Packet->payload);
		// Packet is not a looping packet
		return FALSE;	
	}
}
