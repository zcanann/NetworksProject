
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
	
	// Discovery timer component
	components new TimerMilliC() as DiscoveryTimer;
	App.DiscoveryTimer -> DiscoveryTimer;
	
	// Response time-out component
	components new TimerMilliC() as TimeOutTimer;
	App.TimeOutTimer -> TimeOutTimer;
	
	// Random component
	components RandomC as Random;
	App.Random -> Random;
}
