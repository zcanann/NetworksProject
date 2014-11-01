#include "../../Headers/packet.h"
#include "../../Headers/command.h"
#include "../../Headers/linkstate.h"
#include "../../Headers/neighbor.h"

configuration LinkStateRoutingC
{
	provides interface LinkStateRouting;
	uses interface PacketHandler;
	
	uses interface Hashmap<uint16_t> as neighborTable;
	uses interface Hashmap<uint32_t> as routingTable;
	
} // End configuration
	
implementation
{
	components LinkStateRoutingP as App;
	LinkStateRouting = App.LinkStateRouting;
	App.PacketHandler = PacketHandler;
	App.neighborTable = neighborTable;
	App.routingTable = routingTable;

} // End implementation
