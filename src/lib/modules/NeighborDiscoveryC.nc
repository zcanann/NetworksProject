#include "../../Headers/packet.h"
#include "../../Headers/command.h"

configuration NeighborDiscoveryC
{
	provides interface NeighborDiscovery;
	uses interface PacketHandler;
	uses interface LinkStateRouting;
	
	uses interface Hashmap<uint16_t> as neighborTable;

} // End configuration
	
implementation
{
	components NeighborDiscoveryP as App;
	NeighborDiscovery = App.NeighborDiscovery;
	App.PacketHandler = PacketHandler;
	App.LinkStateRouting = LinkStateRouting;
	App.neighborTable = neighborTable;

} // End implementation