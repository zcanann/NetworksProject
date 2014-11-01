#include "../../Headers/packet.h"
#include "../../Headers/command.h"

configuration TransportC
{
	provides interface Transport;
	uses interface PacketHandler;
	
	uses interface Random;
	uses interface Hashmap<socket_storage_t*> as TCPTablePTR;

} // End configuration
	
implementation
{
	components TransportP as App;
	components new TimerMilliC() as AttemptConnection;
	
	Transport = App.Transport;
	App.PacketHandler = PacketHandler;
	App.TCPTablePTR = TCPTablePTR;
	App.Random = Random;
	App.AttemptConnection -> AttemptConnection;

} // End implementation
