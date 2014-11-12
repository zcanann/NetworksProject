#include "../../Headers/packet.h"
#include "../../Headers/command.h"
#include "../../Headers/socket.h"

configuration TransportC
{
	provides interface Transport;
	uses interface PacketHandler;
	uses interface DataTransfer;
	
	uses interface Random;
	uses interface Hashmap<socket_storage_t*> as TCPTablePTR;

} // End configuration
	
implementation
{
	components TransportP as App;
	
	Transport = App.Transport;
	App.PacketHandler = PacketHandler;
	App.DataTransfer = DataTransfer;
	App.TCPTablePTR = TCPTablePTR;
	App.Random = Random;

} // End implementation
