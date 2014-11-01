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
	// Receives a packet and figures out what to do with it
	command error_t CommandHandler.receive(pack* Packet)
	{
		// dbg("Project1F", "Package Payload: %s\n", Packet->payload);
		
		// Check if this packet was given via command
		if(Packet->protocol == PROTOCOL_CMD)
		{
			call CommandHandler.processCommand(Packet);
			return SUCCESS;
		}
		
		return FAIL;
		
	} // End receive
	
	event void NeighborDiscovery.neighborChanged()
	{
		// TODO: this is horrible design and you know it
	} // End neighborChanged
	
	// Packet with command protocol
	command error_t CommandHandler.processCommand(pack *Packet)
	{
		uint8_t commandID;
		uint8_t* buff;
		
		buff = (uint8_t*) Packet->payload;
		commandID = buff[0];
		
		dbg("cmdDebug", "A Command has been Issued.\n");
		
		// Find out which command was called and call related command
		if(commandID == CMD_PING)
		{
			dbg("cmdDebug", "Command Type: Ping\n");
			dbg("Project1F", "Sending packet %d->%d\n", TOS_NODE_ID, buff[1]);
			call CommandHandler.broadCast(&buff[2], buff[1]);
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
			call CommandHandler.setTestClient(buff[2], buff[3], buff[1], buff[4]);
			return SUCCESS;
		}
		else if(commandID == CMD_TEST_SERVER)
		{
			dbg("cmdDebug", "Command Type: Server (Opening socket %d for Listening)\n", buff[1]);
			call CommandHandler.setTestServer(buff[1]);
			return SUCCESS;
		}
		dbg("cmdDebug", "Ooops.\n");
		dbg("cmdDebug", "CMD_ERROR: \"%s\" does not match any known commands.\n", commandID);
		return FAIL;
		
	} // End processCommand
	
	command void CommandHandler.broadCast(uint8_t *payload, uint16_t destination)
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
		/*if (!call TCPTablePTR.contains(listenPort))
		{
			// Begin listening //TODO: Time out on this!
			signal TCP.setConnectionPTR(listenPort, SOCK_LISTEN);
			dbg("Project3", "\tOpened socket %d\n", listenPort);
		}
		else
		{
			dbg("Project3", "\tSocket %d already open\n", listenPort);
		}*/
		
	} // End setTestServer

	command void CommandHandler.setTestClient(uint16_t targetAddress, uint8_t sendPort, uint8_t targetPort, uint16_t transfer)
	{
		// uint32_t keyVal = call TCP.getKeyFromHeaderData(targetAddress, sendPort, targetPort);
		/*socket_storage_t* connectionData;
		
		if (!call TCPTablePTR.contains(sendPort))
		{
			// Begin listening
			dbg("Project3", "\tTrying to connect from %d, %d to %d, %d\n", TOS_NODE_ID, sendPort, targetAddress, targetPort);
			signal TCP.setConnectionPTR(sendPort, SOCK_SYN_SENT);
			connectionData =  signal TCP.getConnectionState(sendPort);
			signal TCP.updateHeader(sendPort, TOS_NODE_ID, sendPort, targetAddress, targetPort);
			signal TCP.createAndSend(connectionData, targetAddress); //socket_addr_t
		}
		else
		{
			dbg("Project3", "\tConnection exists from %d, %d to %d, %d\n", TOS_NODE_ID, sendPort, targetAddress, targetPort);
		}*/
	
	} // End setTestClient

	command void CommandHandler.setAppServer()
	{
		
	} // End setAppServer

	command void CommandHandler.setAppClient()
	{
		
	} // End setAppClient
   
} // End implementation