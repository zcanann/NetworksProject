#ifndef PACKET_H
#define PACKET_H
# include "protocol.h"

enum
{
	PACKET_HEADER_LENGTH = 8,
	PACKET_MAX_PAYLOAD_SIZE = 28 - PACKET_HEADER_LENGTH,
	
	NO_DESTINATION = 0,
	SEQUENCE_START = 0,
	
	TTL_ONE_HOP = 1,
	MAX_TTL = 15
};


typedef nx_struct pack
{
	nx_uint16_t dest;		// Packet destination
	nx_uint16_t src;		// Packet source
	nx_uint16_t seq;		// Sequence Number
	nx_uint8_t TTL;			// Time to Live
	nx_uint8_t protocol;	// Packet protocol
	nx_uint8_t payload[PACKET_MAX_PAYLOAD_SIZE];
	
} pack;

/*
 * logPack
 * 	Sends packet information to the "genDebug" channel.
 * @param:
 * 		pack *input = pack to be printed.
 */
void logPack(pack *input)
{
	dbg("genDebug", "Src: %hhu Dest: %hhu Seq: %hhu TTL: %hhu Protocol:%hhu  Payload: %s\n",
	input->src, input->dest, input->seq, input->TTL, input->protocol, input->payload);
}

enum
{
	AM_PACK=6
};

#endif
