#include "../../Headers/packet.h"
#include "../../Headers/socket.h"

/**
 * The Transport interface handles sockets and is a layer of abstraction
 * above TCP. This will be used by the application layer to set up TCP
 * packets. Internally the system will be handling syn/ack/data/fin
 * Transport packets.
 *
 * @project
 *   Transmission Control Protocol
 * @author
 *      Alex Beltran - abeltran2@ucmerced.edu
 * @date
 *   2013/11/12
 */

interface Transport
{
	command void initialize();
	command void printConnectionStates();
	command void resendSynAck();
	command error_t createAndSend(socket_storage_t* connectionData, transferProtocol protocol, uint8_t offset);
	
	// TCP connection table functions
	command bool isPortInUse(socket_addr_t* addr);			// Checks if port is being used
	command bool isConnectedTo(socket_addr_t* addr);		// Checks if we are connected to a port/dest pair
	command void setConnectionPTR(uint32_t connectionKey,	// Sets up the connection from hashmap to array
		socketState initialState);
	command socket_storage_t* getConnectionState(uint32_t connectionKey);		// Gets connection state for a port
	command void updateHeader(socket_addr_t* address);							// Updates the TCP header for a connection
	command void setConnectionState(uint32_t connectionKey, socketState state);	// Updates a connection's state
	
	// FSM functions
	command error_t receive(pack* package);
	command void receiveSyn(pack* Packet);
	command void receiveSynAck(pack* Packet);
	command void receiveAck(pack* Packet);
	
	command error_t connect(socket_addr_t* addr, uint16_t transfer);		// Connect to server (cs)
	command error_t close(socket_addr_t* addr);			// Close connection (css?)
	command error_t bind(socket_addr_t* addr,			// Binds socket to address (css)
		socketState initialState); 	
	command socket_t getSocket(socket_addr_t* addr);	// Gets a socket if there is one available (css)
	command error_t release(socket_addr_t* addr); 		// Hard close connection (css)
	command socket_t accept(socket_addr_t* addr);		// Connects to an available connection (ss)
	command error_t listen(socket_t socket); 			// Listen & wait for connection (ss)
	
	/*
	* Write to the socket from a buffer. This data will eventually be
	* transmitted through your TCP implementation.
	*    socket_t fd: file descriptor that is associated with the socket
	*       that is attempting a write.
	*    uint8_t *buff: the buffer data that you are going to write from.
	*    uint16_t bufflen: The amount of data that you are trying to
	*       submit.
	* @Side For your project, only client side. This could be both though.
	* @return uint16_t - return the amount of data you are able to write
	*    from the pass buffer. This may be shorter then bufflen
	*/
	command uint16_t write(socket_t fd, uint8_t *buff, uint16_t bufflen);
	
	/*
	* Read from the socket and write this data to the buffer. This data
	* is obtained from your TCP implimentation.
	*    socket_t fd: file descriptor that is associated with the socket
	*       that is attempting a read.
	*    uint8_t *buff: the buffer that is being written.
	*    uint16_t bufflen: the amount of data that can be written to the
	*       buffer.
	* @Side For your project, only server side. This could be both though.
	* @return uint16_t - return the amount of data you are able to read
	*    from the pass buffer. This may be shorter then bufflen
	*/
	command uint16_t read(socket_t fd, uint8_t *buff, uint16_t bufflen);

} // End interface
