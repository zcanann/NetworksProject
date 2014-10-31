#include <Timer.h>
#include "../../packet.h"
#include "../../command.h"
#include "../../linkedstate.h"
#include "../../neighbor.h"

configuration LinkStateRoutingC
{
	provides interface LinkStateRouting;
	uses interface Hashmap<uint16_t> as neighborTable;
	uses interface Hashmap<uint32_t> as routingTable;
}
	
implementation
{
	components LinkStateRoutingP as App;
	LinkStateRouting = App.LinkStateRouting;
	App.routingTable = routingTable;
}
