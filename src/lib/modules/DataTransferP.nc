#include "../../Headers/packet.h"
#include "../../Headers/command.h"
#include "../../Headers/socket.h"

module DataTransferP
{
	provides interface DataTransfer;
	uses interface PacketHandler;
	uses interface Transport;
	
	uses interface Random;
	uses interface Timer<TMilli> as WriteTimer;
	uses interface Hashmap<socket_storage_t*> as TCPTablePTR;
	uses interface List<uint8_t> as slidingWindow;

} // End module
	
implementation
{
	transfer_packet* TCPPacket;
	uint32_t Attempt_Connection_Time;
	uint32_t Client_Write_Time;
	
	command void DataTransfer.initialize(transfer_packet* TCPPacketPtr)
	{
		TCPPacket = TCPPacketPtr;
		Client_Write_Time = (call Random.rand32() % 2000) + 123999; // This is the timeout period
		
		call WriteTimer.startOneShot(Client_Write_Time);
		
	} // End initialize
	
	command void DataTransfer.fillWriteBuffer(socket_storage_t* connectionData)
	{
		uint32_t popCount;
		uint32_t count;
		
		// Set these equal because we will be using both of these in (ListC) slidingWindow
		connectionData->ackedBuffSize = connectionData->sendBuffSize;
		
		// Count number of leading ack'd bytes that need to be removed
		for (popCount = 0; popCount < SOCKET_SEND_BUFFER_SIZE; popCount++)
		{
			if (connectionData->acked[popCount] == FALSE)
				break;
		}
		
		dbg("Project3", "Removing %d bytes of ACK'd data!\n", popCount);
		
		// Pop ack'd data from our list
		call slidingWindow.pointTo(connectionData->acked, &connectionData->ackedBuffSize);
		for (count = 0; count < popCount; count++)
		{
			call slidingWindow.popback();
		}
		
		// Point the sliding window to the data portion and pop that information too
		call slidingWindow.pointTo(connectionData->sendBuff, &connectionData->sendBuffSize);
		for (count = 0; count < popCount; count++)
		{
			call slidingWindow.popback();
			connectionData->transfer_Amount--;
			connectionData->maxTransmit--;
		}
		
		count = 'Z' - 'A' + 5; // Arbitrary starting point so that it loops starting with 'A'
		
		// Just insert the alphabet repeating for now I guess until the buffer is full or we are done
		while (connectionData->maxTransmit < connectionData->transfer_Amount &&	// Cant send more than we are transferring
			call slidingWindow.size() < SOCKET_SEND_BUFFER_SIZE)				// Cant add more than we can buffer
		{
			dbg("Project3", "MaxTransmit: %d\n", connectionData->maxTransmit);
			
			// Push alphabet letter onto sliding window
			call slidingWindow.pointTo(connectionData->sendBuff, &connectionData->sendBuffSize);
			call slidingWindow.pushfront((uint8_t)((uint8_t)('Z' - (count++) % 26)));
			
			// Push false onto ack'd buffer
			call slidingWindow.pointTo(connectionData->acked, &connectionData->ackedBuffSize);
			call slidingWindow.pushfront((uint8_t)(FALSE));
			
			connectionData->maxTransmit++;
		}
	}
	
	command void DataTransfer.processACK(socket_storage_t* connectionData, transfer_packet* TCPPayload)
	{
		uint8_t swag;
	}
	
	task void sendData()
	{
		uint32_t* keys;
		uint32_t keyInd;
		socket_storage_t* connectionData;
		uint32_t Ind;
		
		keys = call TCPTablePTR.getKeys();
		
		for (keyInd = 0; keyInd < TOTAL_PORTS; keyInd++)
		{
			// Ignore empty entries
			if (keys[keyInd] == 0)
				continue;
			
			connectionData = call Transport.getConnectionState(keys[keyInd]);
			
			if (connectionData->state != SOCK_ESTABLISHED)
				continue;
			
			if (connectionData->transfer_Amount <= 0)
				continue;
			
			// Fill the buffer we are writing from
			call DataTransfer.fillWriteBuffer(connectionData);
			
			// TODO TESTING -- Marking them as ack'd immediately
			for (Ind = 0; Ind < connectionData->sendBuffSize - (connectionData->sendBuffSize % DATA_SIZE); Ind ++)
			{
				//connectionData->acked[Ind] = TRUE;
			}
			
			for (Ind = 0; Ind < connectionData->sendBuffSize / DATA_SIZE; Ind++)
			{
				memcpy(TCPPacket->data, (void*)&connectionData->sendBuff[Ind * DATA_SIZE], DATA_SIZE);
				call Transport.createAndSend(connectionData, ACK, (uint8_t)(Ind + 1));
			}
		}
		
		// Reset timer
		call WriteTimer.startOneShot(Client_Write_Time);
		
	} // End sendData
	
	// Timer to send data
	event void WriteTimer.fired()
	{
		post sendData();
		
	} // End WriteTimer
	
	command void DataTransfer.updateTransferAmount(socket_storage_t* connectionData, uint16_t transfer)
	{
		connectionData->transfer_Amount = transfer;
		
	} // End beginTransfer
	
	command error_t DataTransfer.receive(pack* Packet)
	{
		socket_storage_t *connectionData;	// Current connection state with the sender
		transfer_packet *TCPPayload;
		
		TCPPayload = (transfer_packet*)Packet->payload;
		connectionData = call Transport.getConnectionState(TCPPayload->destPort);	// Grab table entry
		
		// All data sent in established phase should simply be ack packets
		if (TCPPayload->protocol != ACK && TCPPayload->protocol != ACK_NODATA)
			return FAIL;
			
		// Only process for data transport stage if we are in the established state
		if (connectionData->state != SOCK_ESTABLISHED)
			return FAIL;
		
		// Respond to received bytes
		if (TCPPayload->protocol == ACK)
		{
			call Transport.createAndSend(connectionData, ACK_NODATA, NO_OFFSET);
		}
		
		// Process payload
		if (TCPPayload->protocol == ACK_NODATA)
		{
			call DataTransfer.processACK(connectionData, TCPPayload);
		}
		
		
		return SUCCESS;
		
	} // End receive
	
} // End implementation
