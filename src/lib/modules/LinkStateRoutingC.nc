#include <Timer.h>
#include "../../packet.h"
#include "../../command.h"
#include "../../linkedstate.h"
#include "../../neighbor.h"

configuration LinkStateRoutingC
{
	provides interface LinkStateRouting;
}
	
implementation
{
	components LinkStateRoutingP as App;
	LinkStateRouting = App.LinkStateRouting;
}
