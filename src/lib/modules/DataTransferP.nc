#include "../../Headers/packet.h"
#include "../../Headers/command.h"
#include "../../Headers/socket.h"

module DataTransferP
{
	provides interface DataTransfer;
	uses interface PacketHandler;
	uses interface Transport;
	
	uses interface Random;
	//uses interface Timer<TMilli> as ProcessTimer;
	uses interface Hashmap<socket_storage_t*> as TCPTablePTR;
	uses interface List<uint8_t> as slidingWindow;

} // End module
	
implementation
{
	transfer_packet* TCPPacket;
	uint32_t lastKeyInd;
	
	command void DataTransfer.initialize(transfer_packet* TCPPacketPtr)
	{
		TCPPacket = TCPPacketPtr;
	} // End initialize
	
	command void DataTransfer.fillWriteBuffer(socket_storage_t* connectionData)
	{
		uint32_t popCount;
		uint32_t count;
		uint16_t byteNum;
		
		// Set these equal because we will be using both of these in (ListC) slidingWindow
		connectionData->ackedBuffSize = connectionData->sendBuffSize;
		
		// Count number of leading ack'd bytes that need to be removed
		for (popCount = 0; popCount < connectionData->ackedBuffSize; popCount++)
		{
			if (connectionData->acked[popCount] == FALSE)
				break;
		}
		
		//if (popCount > 0)
		//	dbg("Project3", "Removing %d bytes of ACK'd data!\n", popCount);
		
		// Pop ack'd data from our list
		call slidingWindow.pointTo(connectionData->acked, &connectionData->ackedBuffSize);
		for (count = 0; count < popCount; count++)
		{
			call slidingWindow.popfront();
		}
		
		// Point the sliding window to the data portion and pop that information too
		call slidingWindow.pointTo(connectionData->sendBuff, &connectionData->sendBuffSize);
		for (count = 0; count < popCount; count++)
		{
			call slidingWindow.popfront();
			connectionData->transfer_Amount--;
			connectionData->inBuffer--;
			connectionData->baseSeqNum++;
		}
		
		
		while (connectionData->inBuffer < connectionData->transfer_Amount &&	// Cant buffer more than we are transferring
			call slidingWindow.size() < SOCKET_SEND_BUFFER_SIZE)				// Cant add more than we can buffer
		{
			
			byteNum = connectionData->transfer_Amount_Original - (connectionData->transfer_Amount - connectionData->inBuffer);
			
			//dbg("Project3", "Writing to index %d\n", byteNum);
			
			call slidingWindow.pointTo(connectionData->sendBuff, &connectionData->sendBuffSize);
			
			// Push data onto sliding window
			call slidingWindow.pushback((uint8_t)connectionData->transferMessage[byteNum]);
			
			// Push false onto ack'd buffer
			call slidingWindow.pointTo(connectionData->acked, &connectionData->ackedBuffSize);
			call slidingWindow.pushback((uint8_t)(FALSE));
			
			connectionData->inBuffer++;
			
			//dbg("Project3", "inBuffer: %d\n", connectionData->inBuffer);
		}
	}
	
	command void DataTransfer.write()
	{
		uint32_t* keys;
		uint32_t keyInd;
		socket_storage_t* connectionData;
		uint32_t Ind;
		
		keys = call TCPTablePTR.getKeys();
		
		for (keyInd = lastKeyInd; keyInd < TOTAL_PORTS; keyInd++)
		{
			// Ignore empty entries
			if (keys[keyInd] == 0)
				continue;
			
			connectionData = call Transport.getConnectionState(keys[keyInd]);
			
			if (connectionData->state != SOCK_ESTABLISHED)
				continue;
			
			if (connectionData->transfer_Amount <= 0)
				continue;
				
			//dbg("Project3", "Last key index: %d\n", lastKeyInd);
			
			// Fill the buffer we are writing from
			call DataTransfer.fillWriteBuffer(connectionData);
			
			// dbg("Project3", "I think window size is: %d\n", connectionData->advWindow);
			for (Ind = 0; Ind < connectionData->inBuffer / DATA_SIZE; Ind++)
			{
				//memset(TCPPacket->data, 0, DATA_SIZE);
				memcpy(TCPPacket->data, (void*)&connectionData->sendBuff[Ind * DATA_SIZE], DATA_SIZE);
				TCPPacket->packet_size = DATA_SIZE;
				if ((connectionData-> inTransit + TCPPacket->packet_size) <= connectionData->advWindow)
				{
					call Transport.createAndSend(connectionData, ACK, (uint8_t)(Ind));
					connectionData-> inTransit += TCPPacket->packet_size;
					//connectionData->timeInState = 0;
				}
			}
			
			if (connectionData->inBuffer % DATA_SIZE > 0)
			{
				//memset(TCPPacket->data, 0, DATA_SIZE);
				memcpy(TCPPacket->data, (void*)&connectionData->sendBuff[Ind * DATA_SIZE], connectionData->inBuffer % DATA_SIZE);
				TCPPacket->packet_size = (uint8_t)(connectionData->sendBuffSize % DATA_SIZE);
				if ((connectionData-> inTransit + TCPPacket->packet_size) <= connectionData->advWindow)
				{
					call Transport.createAndSend(connectionData, ACK, (uint8_t)(Ind));
					connectionData-> inTransit += TCPPacket->packet_size;
					//connectionData->timeInState = 0;
				}
			}
			
			keyInd++;
			break;
		}
		
		lastKeyInd = keyInd;
		if (lastKeyInd >= TOTAL_PORTS)
			lastKeyInd = 0;
	} // End write
	
	command void DataTransfer.read()
	{
		uint32_t* keys;
		uint32_t* resendKeys;
		uint32_t keyInd;
		uint32_t resendKeyInd;
		socket_storage_t* connectionData;
		socket_storage_t* resendConnectionData;
		uint32_t popCount;
		uint32_t count;
		uint32_t minLen;
		bool foundRet;
		
		foundRet = FALSE;
		
		resendKeys = keys = call TCPTablePTR.getKeys();
		
		for (keyInd = 0; keyInd < TOTAL_PORTS; keyInd++)
		{
			// Ignore empty entries
			if (keys[keyInd] == 0)
				continue;
			
			connectionData = call Transport.getConnectionState(keys[keyInd]);
			
			if (connectionData->state != SOCK_ESTABLISHED)
				continue;
			
			// Sync sizes since popping takes size as reference and will need a copy for each array
			connectionData->hasRecBuffSize = connectionData->recBuffSize = SOCKET_RECEIVE_BUFFER_SIZE;
			
			// Count number of leading ack'd bytes that need to be removed
			for (popCount = 0; popCount < SOCKET_RECEIVE_BUFFER_SIZE; popCount++)
			{
				//dbg("Project3", "God damn it %d\n", popCount);
				if (connectionData->hasRecvd[popCount] && foundRet && (uint8_t)connectionData->recBuff[popCount] == '\n')
					break;
				
				if (connectionData->hasRecvd[popCount] && (uint8_t)connectionData->recBuff[popCount] == '\r')
				{
					//dbg("Project3", "Good news\n");
					foundRet = TRUE;
				}
				else
				{
					foundRet = FALSE;
				}
					
				if (connectionData->hasRecvd[popCount] == FALSE)
					return;
			}
			
			if (popCount <= 0)
				return;
			
			//dbg("Project3", "Reading %d bytes data from buffer!\n", popCount);
			
			// Print data
			for (count = 0; count < popCount; count += popCount)
			{
				minLen = popCount;
				if (minLen > MAX_USER_LEN)
					minLen = MAX_USER_LEN;
				
				// God this is such an awful way of doing things
				// If we dont have a name we assume the first time we are reading is to parse a name.
				if (connectionData->userName[0] == 0)
				{
					memcpy(connectionData->userName, connectionData->recBuff, minLen);
					dbg("Project4", "Initialized name for node %d port %d to %s\n",
						connectionData->sockAddr.destAddr,connectionData->sockAddr.destPort, connectionData->userName);
				}
				// it wasnt a name, great. That means its just a message or whisper
				else
				{
					dbg("Project4", "Message received -- node %d port %d: %s\n",
						connectionData->sockAddr.destAddr,connectionData->sockAddr.destPort, connectionData->recBuff);
					
					// Forward this message to other people if we are the server
					if (keys[keyInd] == 41)
					{
						for (resendKeyInd = 0; resendKeyInd < TOTAL_PORTS; resendKeyInd++)
						{
							// Ignore empty entries
							if (resendKeys[resendKeyInd] == 0)
								continue;
							
							resendConnectionData = call Transport.getConnectionState(resendKeys[resendKeyInd]);
			
							if (resendConnectionData->state != SOCK_ESTABLISHED)
								continue;
							
							call updateTransferAmount(resendConnectionData, connectionData->recBuff);
						}
					}
				}
				
			}
			
			// Pop ack'd flags from our list
			call slidingWindow.pointTo(connectionData->hasRecvd, &connectionData->hasRecBuffSize);
			for (count = 0; count < popCount; count++)
			{
				call slidingWindow.popfront();
			}
			
			// Point the sliding window to the data portion and pop that information too
			call slidingWindow.pointTo(connectionData->recBuff, &connectionData->recBuffSize);
			for (count = 0; count < popCount; count++)
			{
				call slidingWindow.popfront();
				connectionData->baseAckNum++;
			}
			
			// Zero the memory that just entered the window (easier debugging)
			memset(&connectionData->hasRecvd[SOCKET_RECEIVE_BUFFER_SIZE - popCount], FALSE, popCount);
			memset(&connectionData->recBuff[SOCKET_RECEIVE_BUFFER_SIZE - popCount], 0, popCount);
		}
		
	} // End read
	
	command void DataTransfer.updateTransferAmount(socket_storage_t* connectionData, uint8_t* transfer)
	{
		uint16_t transferAmt;
		uint16_t ind;
		bool foundRet;
		
		transferAmt = 0;
		foundRet = FALSE;
		
		for (ind = 0; ind < MAX_MSG_LEN; ind++)
		{
			
			// Copy message to a buffer, and set the total length
			transferAmt++;
			connectionData->transferMessage[ind] = (uint8_t)transfer[ind];
			
			if (foundRet == TRUE && transfer[ind] == '\n')
				break;
			if (transfer[ind] == '\r')
				foundRet = TRUE;
			else
				foundRet = FALSE;
		}
		
		
		//dbg("Project4", "Preparing to send %d\n", transferAmt);
		
		connectionData->transfer_Amount_Original = transferAmt;
		connectionData->transfer_Amount = transferAmt;
		
	} // End beginTransfer
	
	command void DataTransfer.processReply(socket_storage_t* connectionData, transfer_packet* TCPPayload)
	{
		uint8_t base;
		uint8_t offset;
		uint8_t difference;
		//uint8_t Val;
		//uint8_t Ind;
		
		base = connectionData->baseSeqNum;
		offset = TCPPacket->ackNum;
		difference = (uint8_t)(offset - base);
		
		//dbg("Project3", "REP: base off diff %d, %d, %d -- %d\n", base, offset, difference, TOS_NODE_ID);
		
		if (difference < 0 || difference > SOCKET_SEND_BUFFER_SIZE)
		{
			//dbg("Project3", "INVALID ACK RESPONSE!\n");
			return;
		}
		
		if (difference == 0)
			return;
		
		// Mark each of these bytes in window acknowledged
		memset(&connectionData->acked, TRUE, difference);
		
		/*for (Ind = 0; Ind < TCPPayload->packet_size; Ind++)
		{
			Val = (uint8_t)(offset - base + Ind - TCPPayload->packet_size);
			//dbg("Project3", "Acked byte %d\n", Val);
			connectionData->acked[Val] = TRUE;
		}*/
		
	}
		
	command void DataTransfer.processACK(socket_storage_t* connectionData, transfer_packet* TCPPayload)
	{
		uint8_t base;
		uint8_t offset;
		uint8_t difference;
		uint8_t Ind;
		uint8_t Val;
		
		base = connectionData->baseAckNum;
		offset = TCPPayload->seqNum;
		
		difference = (uint8_t)(offset - base);
		
		//dbg("Project3", "ACK: base off diff %d, %d, %d -- %d\n", base, offset, difference, TOS_NODE_ID);
		// Copy data to buffer and mark as received
		
		
		if (difference < 0 || difference > SOCKET_SEND_BUFFER_SIZE)
		{
			//dbg("Project3", "INVALID ACK REPLY! Stop trying to send me shit while my window is full\n");
			return;
		}
		
		Val = (uint8_t)(offset - base - TCPPayload->packet_size);
		memcpy(&connectionData->recBuff[Val], TCPPayload->data, TCPPayload->packet_size);
		memset(&connectionData->hasRecvd[Val], TRUE, TCPPayload->packet_size);
		
		// Respond with an ACK up to the amount we have buffered without gaps
		for (Ind = 0; Ind < SOCKET_RECEIVE_BUFFER_SIZE; Ind++)
		{
			if (connectionData->hasRecvd[Ind] == FALSE)
				break;
		}
		
		TCPPacket->advWindow = (uint8_t)((uint8_t)SOCKET_RECEIVE_BUFFER_SIZE - (uint8_t)Ind);
		//dbg("Project3", "Window size: %d\n", TCPPacket->advWindow);
		TCPPacket->seqNum = (uint8_t)((uint8_t)connectionData->baseAckNum + (uint8_t)Ind);
		call Transport.createAndSend(connectionData, ACK_NODATA, NO_OFFSET);
		
		
	}
	
	command error_t DataTransfer.receive(pack* Packet)
	{
		socket_storage_t *connectionData;	// Current connection state with the sender
		transfer_packet *TCPPayload;
		TCPPayload = (void*)Packet->payload;
		
		connectionData = call Transport.getConnectionState(TCPPayload->destPort);	// Grab table entry
		
		// All data sent in established phase should simply be ack packets
		if (TCPPayload->protocol != ACK && TCPPayload->protocol != ACK_NODATA)
			return FAIL;
			
		// Only process for data transport stage if we are in the established state
		if (connectionData->state != SOCK_ESTABLISHED)
			return FAIL;
		
		// Just copy the TCP payload into the packet we will send later. This simplifies some stuff
		// When we need to reply with a lot of the same information
		TCPPacket->protocol = TCPPayload->protocol;
		TCPPacket->srcPort = TCPPayload->srcPort;
		TCPPacket->destPort = TCPPayload->destPort;
		TCPPacket->seqNum = TCPPayload->seqNum;
		TCPPacket->ackNum = TCPPayload->ackNum;
		TCPPacket->advWindow = TCPPayload->advWindow;
		TCPPacket->packet_size = TCPPayload->packet_size;
		memcpy(TCPPacket->data, TCPPayload->data, DATA_SIZE);
		
		// Respond to received bytes
		if (TCPPayload->protocol == ACK)
		{
			call DataTransfer.processACK(connectionData, TCPPacket);
		}
		
		// Process payload
		else if (TCPPayload->protocol == ACK_NODATA)
		{
			call DataTransfer.processReply(connectionData, TCPPacket);
		}
		
		
		return SUCCESS;
		
	} // End receive
	
} // End implementation
