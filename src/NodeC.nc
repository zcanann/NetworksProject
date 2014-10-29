#include <Timer.h>

configuration NodeC
{
	
}

implementation
{
	components Node;
	
	components MainC;
	Node -> MainC.Boot;
	
	components new AMReceiverC(6);
	Node.Receive -> AMReceiverC;

	components ActiveMessageC;
	Node.AMControl -> ActiveMessageC;

	components SimpleSendC;
	Node.Sender -> SimpleSendC;
	
	// Command processing component
	components CommandHandlerC;
	Node.CommandHandler -> CommandHandlerC;
	
	// Packet processing component
	components PacketHandlerC;
	Node.PacketHandler -> PacketHandlerC;
	
	// Neighbor discovery component
	components NeighborDiscoveryC;
	Node.NeighborDiscovery -> NeighborDiscoveryC;
	
	// Link state routing component
	components LinkStateRoutingC;
	Node.LinkStateRouting -> LinkStateRoutingC;
	
	// TCP component
	components TCPC;
	Node.TCP -> TCPC;
	
	// Random component
	components RandomC as Random;
	Node.Random -> Random;
	
	// Frequent timer component
	components new TimerMilliC() as FrequentUpdate;
	Node.FrequentUpdate -> FrequentUpdate;
	
	// Moderate timer component
	components new TimerMilliC() as ModerateUpdate;
	Node.ModerateUpdate -> ModerateUpdate;
	
	// Sparse timer component
	components new TimerMilliC() as SparseUpdate;
	Node.SparseUpdate -> SparseUpdate;
	
	// Rare timer component
	components new TimerMilliC() as RareUpdate;
	Node.RareUpdate -> RareUpdate;
	
	// Table to keep track of immediate neighbors and the connection types
	components new HashmapC(uint16_t, NEIGHBOR_TABLE_SIZE) as neighborTable;
	Node.neighborTable -> neighborTable;
	
	// Table to keep track of immediate neighbors and the connection types
	components new HashmapC(uint16_t, SEQUENCE_TABLE_SIZE) as sequenceTable;
	Node.sequenceTable -> sequenceTable;
	
	// Table to keep track of immediate neighbors and the connection types
	components new HashmapC(uint32_t, ROUTING_TABLE_SIZE) as routingTable;
	Node.routingTable -> routingTable;
	
	// Table to keep track of immediate neighbors and the connection types
	components new HashmapC(socket_storage_t*, TOTAL_PORTS) as TCPTablePTR;
	Node.TCPTablePTR -> TCPTablePTR;
}
