
#include <Timer.h>
#include "../../packet.h"
#include "../../command.h"

configuration TCPC
{
	provides interface TCP;
}
	
implementation
{
	components TCPP as App;
	TCP = App.TCP;
}
