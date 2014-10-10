#include <Timer.h>
#include "command.h"
#include "packet.h"
#include "neighbor.h"
#include "sendInfo.h"

module Node
{
	uses interface Boot;
	
	uses interface SplitControl as AMControl;
	uses interface Receive;
	
	uses interface SimpleSend as Sender;
	
	// Interface for processing commands
	uses interface CommandHandler;
	
	// Interface for handling packets
	uses interface PacketHandler;
	
	// Interface for discovering neighbors
	uses interface NeighborDiscovery;
}

implementation
{
	pack sendPackage;
	uint8_t pingPacket[PACKET_MAX_PAYLOAD_SIZE];
	
	// Table of all immediate neighbors
	uint32_t neighborTable[NEIGHBOR_TABLE_SIZE];
	
	// Sequence table stuff
	uint16_t sequenceTableSrc[SEQUENCE_TABLE_SIZE];
	uint16_t sequenceTableSeq[SEQUENCE_TABLE_SIZE];
	uint16_t sequenceTableAge[SEQUENCE_TABLE_SIZE];
	
	uint16_t SEQUENCE_NUMBER = 0;
	
	// Prototypes
	void makePack(pack *Package, uint16_t src, uint16_t dest, uint8_t TTL, uint8_t Protocol, uint16_t seq, uint8_t *payload, uint8_t length);
	
	event void Boot.booted()
	{
		call AMControl.start();
		
		call PacketHandler.initialize(sequenceTableSrc, sequenceTableSeq, sequenceTableAge);
		call NeighborDiscovery.initialize(neighborTable);
		
		dbg("genDebug", "Booted\n");
	}
	
	event void AMControl.startDone(error_t err)
	{
		if(err == SUCCESS)
		{
			dbg("genDebug", "Radio On\n");
		}
		else
		{
			// Retry until successful
			call AMControl.start();
		}
	}

	event void AMControl.stopDone(error_t err) { }

	event message_t* Receive.receive(message_t* msg, void* payload, uint8_t len)
	{
		pack* Packet;
		
		dbg("genDebug", "Packet Received\n");
		
		if(len == sizeof(pack))
		{
			Packet = (pack*)payload;
			
			// Always check for commands
			call CommandHandler.receive(Packet);
			
			// Check for looping packet
			if (call PacketHandler.isPacketLooping(Packet))
				return msg;
			
			// Process packet if we haven't seen it yet
			call NeighborDiscovery.receive(Packet);
			call PacketHandler.receive(Packet);
			
			return msg;
		}
		
		dbg("genDebug", "Unknown Packet Type %d\n", len);
      
		return msg;
	}
	
	// Updates seq and TLL, ensures the packet should still exist and sends it
	event void PacketHandler.forward(pack *Package, uint16_t address)
	{
		Package->TTL--;
		if (Package->TTL > 0)
			call Sender.send(*Package, address);
	}
	
	// Initial packet send. Does not update TTL val
	event void PacketHandler.sendInitial(pack *Package, uint16_t address)
	{
		if (Package->TTL > 0)
			call Sender.send(*Package, address);
	}
	
	// Sends a ping to the given address
	event void PacketHandler.ping(uint8_t *payload, uint16_t destination)
	{
		makePack(&sendPackage, TOS_NODE_ID, destination, MAX_TTL, PROTOCOL_PING, SEQUENCE_START, payload, PACKET_MAX_PAYLOAD_SIZE);
		signal PacketHandler.sendInitial(&sendPackage, destination);
	}
	
	// Sends ping reply
	event void PacketHandler.reply(uint16_t destination)
	{
		makePack(&sendPackage, TOS_NODE_ID, destination, MAX_TTL, PROTOCOL_PINGREPLY, SEQUENCE_START, pingPacket, PACKET_MAX_PAYLOAD_SIZE);
		signal PacketHandler.sendInitial(&sendPackage, destination);
	}
	
	// Broadcasts packet to all neighbors
	event void PacketHandler.broadCast(uint8_t *payload, uint16_t destination)
	{
		makePack(&sendPackage, TOS_NODE_ID, destination, MAX_TTL, PROTOCOL_PING, SEQUENCE_START, payload, PACKET_MAX_PAYLOAD_SIZE);
		signal PacketHandler.sendInitial(&sendPackage, AM_BROADCAST_ADDR);
	}

	event void CommandHandler.broadCast(uint8_t *payload, uint16_t destination)
	{
		signal PacketHandler.broadCast(payload, destination);
	}

	event void CommandHandler.printNeighbors()
	{
		uint32_t ecx;
		
		dbg("Project1N", "Neighbors (%d):\n", TOS_NODE_ID);
		for (ecx = 0; ecx < NEIGHBOR_TABLE_SIZE; ecx++)
		{
			if (neighborTable[ecx] == CONNECTION_NONE)
				continue;
			
			if (neighborTable[ecx] & CONNECTION_TIMED_OUT)
				dbg("Project1N", "\tNeighbor %d -/- %d\n", ecx, TOS_NODE_ID);
			else if (neighborTable[ecx] & CONNECTION_SEND) // Assuming two way connection since we only know we can send if they told us
				dbg("Project1N", "\tNeighbor %d <-> %d\n", ecx, TOS_NODE_ID);
			else if (neighborTable[ecx] & CONNECTION_RECEIVE)
				dbg("Project1N", "\tNeighbor %d ->  %d\n", ecx, TOS_NODE_ID);
		}
	}
	
	event void NeighborDiscovery.discoverNeighbors()
	{
		makePack(&sendPackage, TOS_NODE_ID, NO_DESTINATION, MAX_TTL, PROTOCOL_PING, SEQUENCE_START, pingPacket, PACKET_MAX_PAYLOAD_SIZE);
		signal PacketHandler.sendInitial(&sendPackage, AM_BROADCAST_ADDR);
	}

	void makePack(pack *Package, uint16_t src, uint16_t dest, uint8_t TTL, uint8_t protocol, uint16_t seq, uint8_t* payload, uint8_t length)
	{
		// Loop sequence number
		if (++SEQUENCE_NUMBER > 34000)
			SEQUENCE_NUMBER = 0;
		
		Package->src = src;
		Package->dest = dest;
		Package->TTL = TTL;
		Package->seq = SEQUENCE_NUMBER;
		Package->protocol = protocol;
		memcpy(Package->payload, payload, length);
	}
	
	event void CommandHandler.printRouteTable() { }

	event void CommandHandler.printLinkState() { }

	event void CommandHandler.printDistanceVector() { }

	event void CommandHandler.setTestServer() { }

	event void CommandHandler.setTestClient() { }

	event void CommandHandler.setAppServer() { }

	event void CommandHandler.setAppClient() { }
}
