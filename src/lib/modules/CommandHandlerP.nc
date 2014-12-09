#include "../../Headers/packet.h"
#include "../../Headers/command.h"

module CommandHandlerP
{
	provides interface CommandHandler;
	uses interface PacketHandler;
	uses interface NeighborDiscovery;
	uses interface LinkStateRouting;
	uses interface Transport;

} // End module

implementation
{
	command void CommandHandler.initialize()
	{
		
	} // End initialize
	
	// Receives a packet and figures out what to do with it
	command error_t CommandHandler.receive(pack* Packet)
	{
		uint8_t commandID;
		uint8_t* buff;
		
		// Check if this packet was given via command
		if(Packet->protocol != PROTOCOL_CMD)
			return FAIL;
			
		dbg("cmdDebug", "A Command has been Issued.\n");
		
		buff = (uint8_t*) Packet->payload;
		commandID = buff[0];
		
		// Find out which command was called and call related command
		if(commandID == CMD_PING)
		{
			dbg("cmdDebug", "Command Type: Ping\n");
			dbg("Project1F", "Sending packet %d->%d\n", TOS_NODE_ID, buff[1]);
			call CommandHandler.ping(&buff[2], buff[1]);
		}
		else if(commandID == CMD_NEIGHBOR_DUMP)
		{
			dbg("cmdDebug", "Command Type: Neighbor Dump\n");
			call CommandHandler.printNeighbors();
		}
		else if(commandID == CMD_LINKSTATE_DUMP)
		{
			dbg("cmdDebug", "Command Type: Link State Dump\n");
			call CommandHandler.printLinkState();
		}
		else if(commandID == CMD_ROUTETABLE_DUMP)
		{
			dbg("cmdDebug", "Command Type: Route Table Dump\n");
			call CommandHandler.printRouteTable();
		}
		else if(commandID == CMD_TEST_CLIENT)
		{
			dbg("cmdDebug", "Command Type: Client (Preparing for %d, %d connecting with %d, %d)\n", TOS_NODE_ID, buff[3], buff[2], buff[1]);
			call CommandHandler.setTestClient(buff[2], buff[3], buff[1], (uint8_t*)&buff[4]);
		}
		else if(commandID == CMD_TEST_SERVER)
		{
			dbg("cmdDebug", "Command Type: Server (Opening socket %d for Listening)\n", buff[1]);
			call CommandHandler.setTestServer(buff[1]);
		}
		else if (commandID == CMD_KILL)
		{
			dbg("cmdDebug", "Command Type: Client (Closing %d, %d connection with %d, %d)\n", TOS_NODE_ID, buff[3], buff[2], buff[1]);
			call CommandHandler.clientClose(buff[2], buff[3], buff[1]);
		}
		else if (commandID == CMD_HELLO)
		{
			dbg("cmdDebug", "Sending Hello: %d, %d to %d, %d\n", TOS_NODE_ID, buff[3], buff[2], buff[1]);
			call CommandHandler.sendHello(buff[2], buff[3], buff[1], (uint8_t*)&buff[4]);
		}
		else if (commandID == CMD_MSG)
		{
			dbg("cmdDebug", "Sending Message: %d, %d to %d, %d\n", TOS_NODE_ID, buff[3], buff[2], buff[1]);
			call CommandHandler.sendMsg(buff[2], buff[3], buff[1], (uint8_t*)&buff[4]);
		}
		else if (commandID == CMD_WHISPER)
		{
			dbg("cmdDebug", "Sending Message: %d, %d to %d, %d\n", TOS_NODE_ID, buff[3], buff[2], buff[1]);
			//call CommandHandler.sendWhisper(buff[1], buff[2], (uint8_t*)&buff[4]);
		}
		else if (commandID == CMD_LIST_USR)
		{
			
		}
		else
		{
			dbg("cmdDebug", "CMD_ERROR: \"%s\" does not match any known commands.\n", commandID);
			return FAIL;
		}
		
		return SUCCESS;
		
	} // End receive
	
	command void CommandHandler.ping(uint8_t *payload, uint16_t destination)
	{
		call PacketHandler.createAndSend(payload, destination);
		
	} // End broadCast

	command void CommandHandler.printNeighbors()
	{
		call NeighborDiscovery.printNeighbors();
		
	} // End printNeighbors
	
	command void CommandHandler.printRouteTable()
	{
		call CommandHandler.printLinkState();
		call LinkStateRouting.printRoutingTable();
		
	} // End printRouteTable

	command void CommandHandler.printLinkState() 
	{
		call LinkStateRouting.printLinkState();
		
	} // End printLinkState

	command void CommandHandler.printDistanceVector()
	{
		dbg("genDebug", "Distance Vector not relevent to this project!\n");
		
	} // End printLinkState

	command void CommandHandler.setTestServer(uint8_t listenPort)
	{
		call Transport.listen(listenPort);
		
	} // End setTestServer

	command void CommandHandler.setTestClient(uint16_t targetAddress, uint8_t sendPort, uint8_t destPort, uint8_t* transfer)
	{
		socket_addr_t address;
		address.srcAddr = TOS_NODE_ID;
		address.srcPort = sendPort;
		address.destAddr = targetAddress;
		address.destPort = destPort;
		
		call Transport.connect(&address, transfer);
	
	} // End setTestClient
	
	command void CommandHandler.clientClose(uint16_t targetAddress, uint8_t sendPort, uint8_t destPort)
	{
		socket_addr_t address;
		address.srcAddr = TOS_NODE_ID;
		address.srcPort = sendPort;
		address.destAddr = targetAddress;
		address.destPort = destPort;
		
		call Transport.release(&address);
	}
	
	command void CommandHandler.sendHello(uint16_t targetAddress, uint8_t sendPort, uint8_t destPort, uint8_t*msg)
	{
		call CommandHandler.setTestClient(targetAddress, sendPort, destPort, msg);
		
	} // End sendHello
	
	command void CommandHandler.sendMsg(uint16_t targetAddress, uint8_t sendPort, uint8_t destPort, uint8_t*msg)
	{
		call CommandHandler.setTestClient(targetAddress, sendPort, destPort, msg);
		
	} // End sendMsg
	
	command void CommandHandler.sendWhisper(uint16_t targetAddress, uint8_t sendPort, uint8_t nameLen, uint8_t*user, uint8_t*msg)
	{
		
	} // End sendWhisper
	
	command void CommandHandler.listUsers()
	{
		
	} // End listUsers

	command void CommandHandler.setAppServer()
	{
		
	} // End setAppServer

	command void CommandHandler.setAppClient()
	{
		
	} // End setAppClient
   
} // End implementation