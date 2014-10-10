#include "../../packet.h"
#include "../../command.h"

configuration PacketHandlerC
{
	provides interface PacketHandler;
}

implementation
{
	components PacketHandlerP as App;
	PacketHandler = App.PacketHandler;
}
