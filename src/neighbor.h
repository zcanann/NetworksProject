// Description: Connection enum

#ifndef NEIGHBOR_H
#define NEIGHBOR_H


// [FLAGS] Connection type
enum
{
	CONNECTION_NONE 				= 0x0 << 0,
	
	CONNECTION_RECEIVE				= 0x1 << 0,
	CONNECTION_SEND					= 0x1 << 1,
	CONNECTION_WAITING_RESPONSE		= 0x1 << 2,
	CONNECTION_TIMED_OUT			= 0x1 << 3,
};

// Define EMPTY as 0 for improved code readability
enum
{
	EMPTY = 0
};

// Max size of tables
enum
{
	NEIGHBOR_TABLE_SIZE = 255,
	SEQUENCE_TABLE_SIZE = 16
};

#endif /* NEIGHBOR_H */
