#include <Timer.h>

configuration NodeC { }

implementation
{
	components MainC;
	components Node;
	components new AMReceiverC(6);
	
	Node -> MainC.Boot;
	
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
}
