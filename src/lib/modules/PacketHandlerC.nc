configuration PacketHandlerC
{
	provides interface PacketHandler;
	
	uses interface Hashmap<uint16_t> as sequenceTable;
	uses interface Hashmap<uint32_t> as routingTable;

} // End configuration

implementation
{
	components PacketHandlerP as App;
	components new TimerMilliC() as sendTimer;
	components new QueueC(sendInfo*, 20);
	components new PoolC(sendInfo, 20);
	components RandomC as Random;
	components new AMSenderC(6);
	
	PacketHandler = App.PacketHandler;
	sequenceTable = App.sequenceTable;
	routingTable = App.routingTable;
	
	App.sendTimer -> sendTimer;
	App.AMPacket -> AMSenderC;
	App.Packet -> AMSenderC;
	App.AMSend -> AMSenderC;
	App.Random -> Random;
	App.Queue -> QueueC;
	App.Pool -> PoolC;
	
} // End implementation