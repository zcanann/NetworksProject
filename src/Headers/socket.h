#ifndef __STRUCT_H__
#define __STRUCT_H__

typedef enum socketState
{
	SOCK_CLOSED			= 0,
	SOCK_LISTEN			= 1,
	SOCK_SYN_SENT		= 2,
	SOCK_SYN_RECEIVED	= 3,
	SOCK_ESTABLISHED	= 4,
	SOCK_FIN_WAIT1		= 5,
	SOCK_FIN_WAIT2		= 6,
	SOCK_CLOSING		= 7,	// Unused?
	SOCK_TIME_WAIT		= 8,
	SOCK_CLOSE_WAIT		= 9,
	SOCK_LAST_ACK		= 10,
} socketState;

typedef enum transferProtocol
{
	SYN 		= 0,
	SYNACK 		= 1,
	ACK 		= 2,
	ACK_NODATA 	= 3,
	FIN			= 4,
	
} transferProtocol;

enum
{
	SOCKET_SEND_BUFFER_SIZE = 128,
	SOCKET_RECEIVE_BUFFER_SIZE = 128,
	
	POINTER_NULL = 0,					// Temporary socket value
	NULL_SOCKET = 0,
	LISTEN_PORT = 80,
	TOTAL_PORTS = 255,
	
	NO_OFFSET = 1,
	
	DATA_SIZE = 12
};

typedef nx_struct socket_addr_t
{
	nx_uint8_t srcPort;
	nx_uint8_t destPort;
	nx_uint16_t srcAddr;
	nx_uint16_t destAddr;
} socket_addr_t;

typedef struct transfer_packet // 20 bytes to work with
{
	uint8_t protocol;
	uint8_t srcPort;
	uint8_t destPort;
	uint8_t seqNum;
	uint8_t ackNum;
	uint8_t advWindow;
	uint8_t* data[12]; // Should be 14 but for some reason I have 12. Update constant if this number changes.
	
} transfer_packet;

typedef struct socket_storage_t
{
	socketState state;
	socket_addr_t sockAddr;
	uint16_t ackedBuffSize;
	uint8_t acked[SOCKET_RECEIVE_BUFFER_SIZE];
	uint8_t baseSeqNum;
	uint8_t baseAckNum;
	// Client
	uint16_t transfer_Amount;
	int16_t maxTransmit;
	
	uint16_t sendBuffSize;
	uint8_t sendBuff[SOCKET_SEND_BUFFER_SIZE];
	uint16_t lastByteSent;
	uint16_t lastByteWritten;
	uint16_t lastByteAck;
	// Server
	uint16_t recBuffSize;
	uint8_t recBuff[SOCKET_RECEIVE_BUFFER_SIZE];
	uint16_t lastByteRec;
	uint16_t lastByteRead;
	uint16_t lastByteExpected;
} socket_storage_t;

typedef uint16_t socket_t;

#endif
