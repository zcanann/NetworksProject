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
			return SUCCESS;
		}
		else if(commandID == CMD_NEIGHBOR_DUMP)
		{
			dbg("cmdDebug", "Command Type: Neighbor Dump\n");
			call CommandHandler.printNeighbors();
			return SUCCESS;
		}
		else if(commandID == CMD_LINKSTATE_DUMP)
		{
			dbg("cmdDebug", "Command Type: Link State Dump\n");
			call CommandHandler.printLinkState();
			return SUCCESS;
		}
		else if(commandID == CMD_ROUTETABLE_DUMP)
		{
			dbg("cmdDebug", "Command Type: Route Table Dump\n");
			call CommandHandler.printRouteTable();
			return SUCCESS;
		}
		else if(commandID == CMD_TEST_CLIENT)
		{
			dbg("cmdDebug", "Command Type: Client (Preparing for %d, %d connecting with %d, %d)\n", TOS_NODE_ID, buff[3], buff[2], buff[1]);
			call CommandHandler.setTestClient(buff[2], buff[3], buff[1], (uint16_t*)&buff[4]);
			return SUCCESS;
		}
		else if(commandID == CMD_TEST_SERVER)
		{
			dbg("cmdDebug", "Command Type: Server (Opening socket %d for Listening)\n", buff[1]);
			call CommandHandler.setTestServer(buff[1]);
			return SUCCESS;
		}
		
		dbg("cmdDebug", "CMD_ERROR: \"%s\" does not match any known commands.\n", commandID);
		return FAIL;
		
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
		call Transport.setTestServer(listenPort);
		
	} // End setTestServer

	command void CommandHandler.setTestClient(uint16_t targetAddress, uint8_t sendPort, uint8_t targetPort, uint16_t* transfer)
	{
		call Transport.setTestClient(targetAddress, sendPort, targetPort, *transfer);
	
	} // End setTestClient

	command void CommandHandler.setAppServer()
	{
		
	} // End setAppServer

	command void CommandHandler.setAppClient()
	{
		
	} // End setAppClient
   
} // End implementation