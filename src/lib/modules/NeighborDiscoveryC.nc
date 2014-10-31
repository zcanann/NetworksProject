
#include <Timer.h>
#include "../../packet.h"
#include "../../command.h"

configuration NeighborDiscoveryC
{
	provides interface NeighborDiscovery;
	uses interface Hashmap<uint16_t> as neighborTable;
}
	
implementation
{
	components NeighborDiscoveryP as App;
	NeighborDiscovery = App.NeighborDiscovery;
	App.neighborTable = neighborTable;
}
