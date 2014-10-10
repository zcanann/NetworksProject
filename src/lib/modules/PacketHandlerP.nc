#include "../../packet.h"
#include "../../neighbor.h"
#include "../../command.h"

module PacketHandlerP
{
	provides interface PacketHandler;
}

implementation
{
	// Sequence tables!
	uint16_t* sequenceTableSeq;
	uint16_t* sequenceTableSrc;
	uint16_t* sequenceTableAge;
	
	command void PacketHandler.initialize(uint16_t* sequenceTableSrcPtr, uint16_t* sequenceTableSeqPtr, uint16_t* sequenceTableAgePtr)
	{
		// Initialize our sequence table
		sequenceTableSrc = sequenceTableSrcPtr;
		sequenceTableSeq = sequenceTableSeqPtr;
		sequenceTableAge = sequenceTableAgePtr;
		
		memset(sequenceTableSeq, 0, SEQUENCE_TABLE_SIZE);
		memset(sequenceTableSeq, 0, SEQUENCE_TABLE_SIZE);
		memset(sequenceTableSeq, 0, SEQUENCE_TABLE_SIZE);
		
	}
	
	// Receives a packet and figures out what to do with it
	command error_t PacketHandler.receive(pack* Packet)
	{
		uint32_t ecx;
		
		// Handle packet based on protocol
		if(Packet->protocol == PROTOCOL_PING)
		{
			// STEP 1: See if we already have a record from this source - DONE EXTERNALLY
			
			// STEP 2: Dont process stupid single-ping broadcast packets (important)
			if (Packet->dest != NO_DESTINATION)
			{
				// STEP 3: Not a duplicate, age all table entries
				for (ecx = 0; ecx < SEQUENCE_TABLE_SIZE; ecx++)
				{
					// Age all table entries
					if (sequenceTableAge[ecx] > 0)
						sequenceTableAge[ecx]--;
					
					// Clear data once it has aged out
					if (sequenceTableAge[ecx] == 0)
					{
						sequenceTableSrc[ecx] = 0;
						sequenceTableSeq[ecx] = 0;
					}
				}
				
				// Step 4: Insert our entry in the first empty spot
				for (ecx = 0; ecx < SEQUENCE_TABLE_SIZE; ecx++)
				{
					if (sequenceTableAge[ecx] == 0)
					{
						//dbg ("Project1F", "Saving src/sequence keys %d/%d\n", Packet->src, Packet->seq);
						sequenceTableSrc[ecx] = Packet->src;
						sequenceTableSeq[ecx] = Packet->seq;
						sequenceTableAge[ecx] = SEQUENCE_TABLE_SIZE - 1;
						break;
					}
				}
				
				// Received packet addressed to this node!
				if (Packet->dest == TOS_NODE_ID)
				{
					dbg ("Project1F", "Received packet %d->%d. Payload: %s\n", Packet->src, TOS_NODE_ID, Packet->payload);
				}
				
				if (Packet->dest != TOS_NODE_ID)
				{
					// Do not forward immediate neighbor discovery pings
					// Received packet addressed to another node; forward it
					dbg ("genDebug", "Received a packet not addressed to me'\n");
					signal PacketHandler.forward(Packet, AM_BROADCAST_ADDR);
					
					// return FAIL;
				}
			}
			
			dbg ("genDebug", "Replying to ping\n");
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
		
		dbg("genDebug", "Ooops.\n");
		dbg("genDebug", "PROTOCOL_ERROR: \"%s\" does not match any known protocols.\n", Packet->protocol);
		return FAIL;
		
	}
	
	command bool PacketHandler.isPacketLooping(pack *Packet)
	{
		uint32_t ecx;
		
		// Check SRC/SEQ pair to see if we have received this packet already
		for (ecx = 0; ecx < SEQUENCE_TABLE_SIZE; ecx++)
		{
				if (sequenceTableSrc[ecx] == Packet->src && sequenceTableSeq[ecx] == Packet->seq)
				{
					// dbg("Project1F", "Denied duplicate packet\n");
					return TRUE;
				}
		}
		
		// Packet is not a looping packet
		return FALSE;	
	}
}
