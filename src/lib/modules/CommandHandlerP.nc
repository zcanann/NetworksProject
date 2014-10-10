#include "../../packet.h"
#include "../../command.h"

module CommandHandlerP
{
	provides interface CommandHandler;
}

implementation
{
	// Receives a packet and figures out what to do with it
	command error_t CommandHandler.receive(pack* Packet)
	{
		// dbg("Project1F", "Package Payload: %s\n", Packet->payload);
		
		// Check if this packet was given via command
		if(Packet->protocol == PROTOCOL_CMD)
		{
			dbg ("genDebug", "Injecting packet\n");
			call CommandHandler.processCommand(Packet);
			return SUCCESS;
		}
		
		dbg("genDebug", "Ooops.\n");
		dbg("genDebug", "PROTOCOL_ERROR: \"%s\" does not match any known protocols.\n", Packet->protocol);
		
		return FAIL;
		
	}
	
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
			signal CommandHandler.broadCast(&buff[2], buff[1]);
			return SUCCESS;
		}
		else if(commandID == CMD_NEIGHBOR_DUMP)
		{
			dbg("cmdDebug", "Command Type: Neighbor Dump\n");
			signal CommandHandler.printNeighbors();
			return SUCCESS;
		}
		else if(commandID == CMD_LINKSTATE_DUMP)
		{
			dbg("cmdDebug", "Command Type: Link State Dump\n");
			signal CommandHandler.printLinkState();
			return SUCCESS;
		}
		else if(commandID == CMD_ROUTETABLE_DUMP)
		{
			dbg("cmdDebug", "Command Type: Route Table Dump\n");
			signal CommandHandler.printRouteTable();
			return SUCCESS;
		}
		else if(commandID == CMD_TEST_CLIENT)
		{
			dbg("cmdDebug", "Command Type: Client\n");
			signal CommandHandler.setTestClient();
			return SUCCESS;
		}
		else if(commandID == CMD_TEST_SERVER)
		{
			dbg("cmdDebug", "Command Type: Client\n");
			signal CommandHandler.setTestServer();
			return SUCCESS;
		}
		dbg("cmdDebug", "Ooops.\n");
		dbg("cmdDebug", "CMD_ERROR: \"%s\" does not match any known commands.\n", commandID);
		return FAIL;
		
	}
   
}
