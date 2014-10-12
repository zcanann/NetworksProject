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
}
