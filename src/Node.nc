#include <Timer.h>
#include "../../Headers/command.h"
#include "../../Headers/packet.h"
#include "../../Headers/neighbor.h"
#include "../../Headers/sendInfo.h"
#include "../../Headers/linkstate.h"
#include "../../Headers/socket.h"

module Node
{
	uses interface Boot;			// Interface for booting
	uses interface SplitControl;	// Interface for radio
	uses interface Receive;			// Interface for receiving packets
	
	uses interface PacketHandler;		// Interface for processing and sending packets
	uses interface CommandHandler;		// Interface for processing commands
	uses interface NeighborDiscovery;	// Interface for discovering neighbors
	uses interface LinkStateRouting;	// Interface for link state routing
	uses interface Transport;			// Interface for transport
	
	uses interface Random;							// Interface for random module
	uses interface Timer<TMilli> as FrequentUpdate;	// Timer events that happen frequently
	uses interface Timer<TMilli> as ModerateUpdate;	// Timer events that happen moderately
	uses interface Timer<TMilli> as SparseUpdate;	// Timer events that happen sparsely
	uses interface Timer<TMilli> as RareUpdate;		// Timer events that happen rarely
	
	uses interface Hashmap<uint16_t> as neighborTable;			// Stores immediate neighbors
	uses interface Hashmap<uint16_t> as sequenceTable;			// Stores sequence table data
	uses interface Hashmap<uint32_t> as routingTable;			// Stores routing table data
	uses interface Hashmap<socket_storage_t*> as TCPTablePTR;	// Stores [pointer to] TCP connection state struct

} // End module

implementation
{
	bool NeighborsChanged = FALSE;
	
	uint32_t PeriodFrequent;
	uint32_t PeriodModerate;
	uint32_t PeriodSparse;
	uint32_t PeriodRare;
	
	//////////////////////////////////////////////////
	// INITIALIZATION
	//////////////////////////////////////////////////
	
	event void Boot.booted()
	{
		call SplitControl.start();
		
		// Initialize all components
		call LinkStateRouting.initialize();
		call PacketHandler.initialize();
		call NeighborDiscovery.initialize();
		call Transport.initialize();
		
		// Initialize all update timer periods
		PeriodFrequent = (call Random.rand32() % 200) + 3999;
		PeriodModerate = (call Random.rand32() % 2000) + 19991;
		PeriodSparse = (call Random.rand32() % 20000) + 189999;
		PeriodRare = (call Random.rand32() % 40000) + 889999;
		
		call FrequentUpdate.startOneShot(PeriodFrequent);
		call ModerateUpdate.startOneShot(PeriodModerate);
		call SparseUpdate.startOneShot(PeriodSparse);
		call RareUpdate.startOneShot(PeriodRare);
		
		dbg("genDebug", "Booted\n");
		
	} // End booted
	
	event void NeighborDiscovery.neighborChanged()
	{
		NeighborsChanged = TRUE; // Indicate that a neighbor has changed
		
	} // End neighborChanged
	
	//////////////////////////////////////////////////
	// RECEIVE
	//////////////////////////////////////////////////
	
	event message_t* Receive.receive(message_t* msg, void* payload, uint8_t len)
	{
		pack* Packet;
		
		if(len != sizeof(pack))
		{
			dbg("genDebug", "Unknown Packet Type %d\n", len);
			return msg;
		}
		
		Packet = (pack*)payload;
		
		// Always check for commands
		call CommandHandler.receive(Packet);
		
		// Check for duplicate packet
		if (call PacketHandler.isPacketDuplicate(Packet))
			return msg;
		
		call NeighborDiscovery.receive(Packet);		// Neighbor discovery processing
		call LinkStateRouting.receive(Packet);		// Link state routing processing
		call PacketHandler.receive(Packet);			// General packet processing
		call Transport.receive(Packet);				// TCP processing
		
		return msg;
		
	} // End receive
	
	//////////////////////////////////////////////////
	// TIMER EVENTS
	//////////////////////////////////////////////////
	
	task void doFrequentEvents()
	{
		call NeighborDiscovery.discoverNeighbors();			// Send neighbor discovery packets
		call FrequentUpdate.startOneShot(PeriodFrequent); 	// Restart timer
		
	} // End doFrequentEvents
	
	task void doModerateEvents()
	{
		call NeighborDiscovery.timeOutCheck();	// Time out neighbors that have died
		if (NeighborsChanged)
		{
			NeighborsChanged = ! NeighborsChanged;
			call LinkStateRouting.shareLinkState();	// Send link state on changed neighbor
		}
		call ModerateUpdate.startOneShot(PeriodModerate);	// Restart timer

	} // End doModerateEvents
	
	task void doSparseEvents()
	{
		call LinkStateRouting.calculateRoute();			// Calculate routes via link states
		call SparseUpdate.startOneShot(PeriodSparse);	// Restart timer
		
	} // End doSparseEvents
	
	task void doRareEvents()
	{
		call LinkStateRouting.shareLinkState();		// Share link state regardless of neighbor changes
		call PacketHandler.ageSequenceTable();		// Age sequence table on occasion to handle a super rare edge case
		call RareUpdate.startOneShot(PeriodRare);	// Restart timer
		
	} // End doRareEvents
	
	// Events that need to fire frequently
	event void FrequentUpdate.fired()
	{
		post doFrequentEvents();
		
	} // End FrequentUpdate
	
	// Events that need to fire moderately
	event void ModerateUpdate.fired()
	{
		post doModerateEvents();
		
	} // End ModerateUpdate
	
	// Events that need to fire sparsely
	event void SparseUpdate.fired()
	{
		post doSparseEvents();
		
	} // End SparseUpdate
	
	// Events that need to fire rarely
	event void RareUpdate.fired()
	{
		post doRareEvents();
		
	} // End RareUpdate
	
	//////////////////////////////////////////////////
	// OTHER STUFF
	//////////////////////////////////////////////////
	
	event void SplitControl.startDone(error_t err)
	{
		if(err == SUCCESS)
		{
			dbg("genDebug", "Radio On\n");
		}
		else
		{
			// Retry until successful
			call SplitControl.start();
		}
		
	} // End startDone

	event void SplitControl.stopDone(error_t err)
	{
		if(err == SUCCESS)
		{
			dbg("genDebug", "Radio Off\n");
		}
		else
		{
			// Retry until successful
			call SplitControl.stop();
		}
		
	} // End stopDone
	
} // End implementation
