#include "../../Headers/packet.h"
#include "../../Headers/command.h"

configuration CommandHandlerC
{
	provides interface CommandHandler;
	uses interface PacketHandler;
	uses interface NeighborDiscovery;
	uses interface LinkStateRouting;
	uses interface Transport;
	
} // End configuration

implementation
{
	components CommandHandlerP as App;
	CommandHandler = App.CommandHandler;
	App.PacketHandler = PacketHandler;
	App.NeighborDiscovery = NeighborDiscovery;
	App.LinkStateRouting = LinkStateRouting;
	App.Transport = Transport;

} // End implementation
