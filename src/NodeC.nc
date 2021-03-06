#include <Timer.h>
#include "../../Headers/command.h"
#include "../../Headers/packet.h"
#include "../../Headers/neighbor.h"
#include "../../Headers/sendInfo.h"
#include "../../Headers/linkstate.h"
#include "../../Headers/socket.h"

configuration NodeC
{
	
} // End configuration

implementation
{
	// Core components
	components Node;				// The node to deal with packets
	components MainC;				// Main class
	components new AMReceiverC(6);	// ??
	components ActiveMessageC;		// ??
	components PacketHandlerC;		// Packet processing and sending component
	components CommandHandlerC;		// Command processing component
	components NeighborDiscoveryC;	// Neighbor discovery component
	components LinkStateRoutingC;	// Link state routing component
	components TransportC;			// TCP component
	components DataTransferC;		// TCP transfer component
	
	// Wire core components
	Node -> MainC.Boot;
	Node.Receive -> AMReceiverC;
	Node.SplitControl -> ActiveMessageC;
	Node.PacketHandler -> PacketHandlerC;
	Node.CommandHandler -> CommandHandlerC;
	Node.NeighborDiscovery -> NeighborDiscoveryC;
	Node.LinkStateRouting -> LinkStateRoutingC;
	Node.Transport -> TransportC;
	CommandHandlerC.PacketHandler -> PacketHandlerC;
	CommandHandlerC.NeighborDiscovery -> NeighborDiscoveryC;
	CommandHandlerC.LinkStateRouting -> LinkStateRoutingC;
	CommandHandlerC.Transport -> TransportC;
	NeighborDiscoveryC.PacketHandler -> PacketHandlerC;
	NeighborDiscoveryC.LinkStateRouting -> LinkStateRoutingC;
	LinkStateRoutingC.PacketHandler -> PacketHandlerC;
	TransportC.PacketHandler -> PacketHandlerC;
	TransportC.DataTransfer -> DataTransferC;
	DataTransferC.PacketHandler -> PacketHandlerC;
	DataTransferC.Transport -> TransportC;
	
	// Tables
	components new HashmapC(uint16_t, NEIGHBOR_TABLE_SIZE) as neighborTable;	// Neighbor Table
	components new HashmapC(uint16_t, SEQUENCE_TABLE_SIZE) as sequenceTable;	// Sequence Table
	components new HashmapC(uint32_t, ROUTING_TABLE_SIZE) as routingTable;		// Routing table
	components new HashmapC(socket_storage_t*, TOTAL_PORTS) as TCPTablePTR;		// TCP Table
	components new ListC(uint8_t, SOCKET_SEND_BUFFER_SIZE) as slidingWindow;	// Sliding window
	
	// Wire tables
	Node.neighborTable -> neighborTable;
	NeighborDiscoveryC.neighborTable -> neighborTable;
	Node.sequenceTable -> sequenceTable;
	Node.routingTable -> routingTable;
	Node.TCPTablePTR -> TCPTablePTR;
	PacketHandlerC.sequenceTable -> sequenceTable;
	PacketHandlerC.routingTable -> routingTable;
	LinkStateRoutingC.neighborTable -> neighborTable;
	LinkStateRoutingC.routingTable -> routingTable;
	TransportC.TCPTablePTR -> TCPTablePTR;
	DataTransferC.TCPTablePTR -> TCPTablePTR;
	DataTransferC.slidingWindow -> slidingWindow;
	
	// Timers
	components RandomC as Random;						// Random component
	components new TimerMilliC() as FrequentUpdate;		// Frequent timer component
	components new TimerMilliC() as ModerateUpdate;		// Moderate timer component
	components new TimerMilliC() as SparseUpdate;		// Sparse timer component
	components new TimerMilliC() as RareUpdate;			// Rare timer component
	components new TimerMilliC() as AttemptConnection;	// Timer to attempt tcp connection component
	
	// Wire timers
	Node.Random -> Random;
	Node.FrequentUpdate -> FrequentUpdate;
	Node.ModerateUpdate -> ModerateUpdate;
	Node.SparseUpdate -> SparseUpdate;
	Node.RareUpdate -> RareUpdate;
	PacketHandlerC.Random -> Random;
	TransportC.Random -> Random;
	DataTransferC.Random -> Random;

} // End implementation
