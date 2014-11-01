#include "../../Headers/packet.h"
#include "../../Headers/command.h"

configuration TransportC
{
	provides interface Transport;
	uses interface PacketHandler;
	
	uses interface Hashmap<socket_storage_t*> as TCPTablePTR;

} // End configuration
	
implementation
{
	components TransportP as App;
	Transport = App.Transport;
	App.PacketHandler = PacketHandler;
	App.TCPTablePTR = TCPTablePTR;

} // End implementation
