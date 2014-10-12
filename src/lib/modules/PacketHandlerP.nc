#include "../../packet.h"
#include "../../neighbor.h"
#include "../../command.h"

module PacketHandlerP
{
	provides interface PacketHandler;
}

implementation
{
	// Sequence tables
	uint16_t* sequenceTableSeq;
	uint16_t* sequenceTableSrc;
	uint16_t* sequenceTableAge;
	
	command void PacketHandler.initialize(uint16_t* sequenceTableSrcPtr, uint16_t* sequenceTableSeqPtr, uint16_t* sequenceTableAgePtr)
	{
		// Get pointers to our sequence table data
		sequenceTableSrc = sequenceTableSrcPtr;
		sequenceTableSeq = sequenceTableSeqPtr;
		sequenceTableAge = sequenceTableAgePtr;
		
	}
	
	// Receives a packet and figures out what to do with it
	command error_t PacketHandler.receive(pack* Packet)
	{
		// Repeat packet check called externally from Node.nc
		
		// Handle packet based on protocol
		if(Packet->protocol == PROTOCOL_PING)
		{
			// Do not process single-ping broadcast packets (important)
			if (Packet->dest != UNSPECIFIED)
			{
				call PacketHandler.processSequence(Packet);
				
				// Received packet addressed to this node!
				if (Packet->dest == TOS_NODE_ID)
				{
					dbg ("Project1F", "Received packet %d->%d. Payload: %s\n", Packet->src, TOS_NODE_ID, Packet->payload);
				}
				
				if (Packet->dest != TOS_NODE_ID)
				{
					// Received packet addressed to another node; forward it
					signal PacketHandler.send(Packet, AM_BROADCAST_ADDR, TRUE);
					
					return SUCCESS;
				}
			}
			
			signal PacketHandler.reply(Packet->src);
				
			return SUCCESS;
		}
		else if (Packet->protocol == PROTOCOL_PINGREPLY)
		{
			//if (Packet->dest == TOS_NODE_ID)
			{
				//dbg ("Project1F", "Received ping reply %d->%d. Payload: %s\n", Packet->src, TOS_NODE_ID, Packet->payload);
			}
		}
		else if (Packet->protocol == PROTOCOL_LINKSTATE)
		{
			call PacketHandler.processSequence(Packet);
			signal PacketHandler.send(Packet, AM_BROADCAST_ADDR, TRUE);
		}
		
		return FAIL;
		
	}
	
	command error_t PacketHandler.processSequence(pack* Packet)
	{
		uint32_t ind;
		
		// Insert our entry in the first empty spot
		for (ind = 0; ind < SEQUENCE_TABLE_SIZE; ind++)
		{
			if (sequenceTableAge[ind] == 0)
			{
				//dbg ("Project1F", "Saving src/sequence keys %d/%d\n", Packet->src, Packet->seq);
				sequenceTableSrc[ind] = Packet->src;
				sequenceTableSeq[ind] = Packet->seq;
				sequenceTableAge[ind] = SEQUENCE_TABLE_SIZE - 1;
				break;
			}
		}
		
		return SUCCESS;
	}
	
	// Ages each entry in the sequence table
	command void PacketHandler.ageSequenceTable()
	{
		uint32_t ind;
		for (ind = 0; ind < SEQUENCE_TABLE_SIZE; ind++)
		{
			// Age all entries
			if (sequenceTableAge[ind] > 0)
				sequenceTableAge[ind]--;
			
			// Clear data once it has aged out
			if (sequenceTableAge[ind] == 0)
			{
				sequenceTableSrc[ind] = 0;
				sequenceTableSeq[ind] = 0;
			}
		}
	}
	
	command bool PacketHandler.isPacketLooping(pack *Packet)
	{
		uint32_t ind;
		
		// Check SRC/SEQ pair to see if we have received this packet already
		for (ind = 0; ind < SEQUENCE_TABLE_SIZE; ind++)
		{
				if (sequenceTableSrc[ind] == Packet->src && sequenceTableSeq[ind] == Packet->seq)
				{
					// dbg("Project1F", "Denied duplicate packet\n");
					return TRUE;
				}
		}
		
		// Packet is not a looping packet
		return FALSE;	
	}
}
