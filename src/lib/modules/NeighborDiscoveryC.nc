
#include <Timer.h>
#include "../../packet.h"
#include "../../command.h"

configuration NeighborDiscoveryC
{
	provides interface NeighborDiscovery;
}
	
implementation
{
	components NeighborDiscoveryP as App;
	NeighborDiscovery = App.NeighborDiscovery;
}
