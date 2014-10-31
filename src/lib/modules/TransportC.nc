
#include <Timer.h>
#include "../../packet.h"
#include "../../command.h"

configuration TransportC
{
	provides interface Transport;
}
	
implementation
{
	components TransportP as App;
	Transport = App.Transport;
}
