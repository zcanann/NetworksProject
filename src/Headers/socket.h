#ifndef __STRUCT_H__
#define __STRUCT_H__

typedef enum socketState
{
	SOCK_CLOSED			= 0,
	SOCK_LISTEN			= 1,
	SOCK_SYN_SENT		= 2,
	SOCK_SYN_RECEIVED	= 3,
	SOCK_ESTABLISHED	= 4,
	SOCK_CLOSE_WAIT		= 5,
	SOCK_FIN_WAIT1		= 6,
	SOCK_FIN_WAIT2		= 7,
	SOCK_TIME_WAIT		= 8,
	SOCK_LAST_ACK		= 9
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
	NO_OFFSET = 0,
	DATA_SIZE = 12,
	ACK_TIMEOUT = 80000,
	TRANSITION_TIMEOUT = 200000,
	CLOSE_TIMEOUT = 400000,
	CONNECT_TIMEOUT = 4000000,
	
	MAX_USER_LEN = 20,
	MAX_MSG_LEN = 255
};

typedef struct transfer_packet // 20 bytes to work with
{
	uint8_t protocol;			// Byte 1
	uint8_t srcPort;			// Byte 2
	uint8_t destPort;			// Byte 3
	uint8_t seqNum;				// Byte 4
	uint8_t ackNum;				// Byte 5
	uint8_t advWindow;			// Byte 6
	uint8_t nextByteExpected;	// Byte 7
	uint8_t packet_size;		// Byte 8
	uint8_t* data[DATA_SIZE];	// Byte 9-20
} transfer_packet;

typedef nx_struct socket_addr_t
{
	nx_uint8_t srcPort;
	nx_uint8_t destPort;
	nx_uint16_t srcAddr;
	nx_uint16_t destAddr;
} socket_addr_t;

typedef struct socket_storage_t
{
	// Application layer stuff. Yep I know this is a huge layer violation. I dont have the time to care.
	uint8_t* userName[MAX_USER_LEN];
	uint8_t* transferMessage[MAX_MSG_LEN];
	
	socketState state;
	socket_addr_t sockAddr;
	
	int64_t timeInState;
	
	uint8_t advWindow;
	
	uint8_t baseSeqNum;
	uint8_t baseAckNum;
	
	// Client
	uint16_t transfer_Amount_Original;
	uint16_t transfer_Amount;
	int16_t inBuffer;
	int16_t inTransit;
	
	uint16_t sendBuffSize;
	uint8_t sendBuff[SOCKET_SEND_BUFFER_SIZE];
	uint16_t ackedBuffSize;
	uint8_t acked[SOCKET_RECEIVE_BUFFER_SIZE];
	uint16_t lastByteSent;
	uint16_t lastByteWritten;
	uint16_t lastByteAck;
	
	// Server
	uint16_t recBuffSize;
	uint16_t hasRecBuffSize;
	uint8_t recBuff[SOCKET_RECEIVE_BUFFER_SIZE];
	uint8_t hasRecvd[SOCKET_RECEIVE_BUFFER_SIZE];
	uint16_t lastByteRec;
	uint16_t lastByteRead;
	uint16_t lastByteExpected;
	
} socket_storage_t;

typedef uint16_t socket_t;

#endif
