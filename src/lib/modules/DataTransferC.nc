#include "../../Headers/packet.h"
#include "../../Headers/command.h"
#include "../../Headers/socket.h"

configuration DataTransferC
{
	provides interface DataTransfer;
	uses interface PacketHandler;
	uses interface Transport;
	
	uses interface Random;
	uses interface Hashmap<socket_storage_t*> as TCPTablePTR;
	uses interface List<uint8_t> as slidingWindow;

} // End configuration
	
implementation
{
	components DataTransferP as App;
	components new TimerMilliC() as WriteTimer;
	
	DataTransfer = App.DataTransfer;
	App.PacketHandler = PacketHandler;
	App.Transport = Transport;
	App.TCPTablePTR = TCPTablePTR;
	App.slidingWindow = slidingWindow;
	App.Random = Random;
	App.WriteTimer -> WriteTimer;

} // End implementation
