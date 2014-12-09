// Description: Processes commands and returns an Command ID Number.

#ifndef COMMAND_H
#define COMMAND_H
 
// Command ID Number
enum
{
	CMD_PING = '0',
	CMD_NEIGHBOR_DUMP='1',
	CMD_LINKSTATE_DUMP='2',
	CMD_ROUTETABLE_DUMP='3',
	CMD_TEST_CLIENT='4',
	CMD_TEST_SERVER='5',
	CMD_KILL='6',
	CMD_HELLO='7',
	CMD_MSG='8',
	CMD_WHISPER='9',
	CMD_LIST_USR='!',
	CMD_ERROR='@'
};

enum
{
	CMD_LENGTH = 1,
};

#endif /* COMMAND_H */
