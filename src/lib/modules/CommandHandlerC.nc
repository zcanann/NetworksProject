#include "../../packet.h"
#include "../../command.h"

configuration CommandHandlerC
{
	provides interface CommandHandler;
}

implementation
{
	components CommandHandlerP as App;
	CommandHandler = App.CommandHandler;
}
