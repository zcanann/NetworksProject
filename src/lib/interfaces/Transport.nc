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
	command uint32_t getKeyFromHeaderData(uint16_t dest, uint8_t srcPort, uint8_t destPort);
	command void createAndSend(socket_storage_t *TCPHeader, uint16_t destination);
	
	command void setTestClient(uint16_t targetAddress, uint8_t sendPort, uint8_t targetPort, uint16_t transfer);
	command void setTestServer(uint8_t listenPort);
	
	// TCP connection table functions
	command void setConnectionPTR(uint32_t connectionKey, uint8_t initialState);
	
	command socket_storage_t* getConnectionState(uint32_t connectionKey);
	
	command void updateHeader(uint32_t connectionKey, uint16_t src, uint8_t srcPort, uint16_t dest, uint8_t destPort);
	command void setConnectionState(uint32_t connectionKey, uint8_t state);
	
	/*
	* Get a socket if there is one available.
	* @Side Client/Server
	* @return
	*    socket_t - return a socket file descriptor which is a number
	*    associated with a socket. If you are unable to allocate
	*    a socket then return a NULL socket_t.
	*/
	command socket_t socket();
	
	/*
	* Bind a socket with an address.
	*    socket_t fd: file descriptor that is associated with the socket
	*       you are binding.
	*    socket_addr_t *addr: the source port and source address that
	*       you are biding to the socket, fd.
	* @Side Client/Server
	* @return error_t - SUCCESS if you were able to bind this socket, FAIL
	*       if you were unable to bind.
	*/
	command error_t bind(socket_t fd, socket_addr_t *addr);

	/*
	* Checks to see if there are socket connections to connect to and
	* if there is one, connect to it.
	*    socket_t fd: file descriptor that is associated with the socket
	*       that is attempting an accept. remember, only do on listen. 
	* @side Server
	* @return socket_t - returns a new socket if the connection is
	*    accepted. this socket is a copy of the server socket but with
	*    a destination associated with the destination address and port.
	*    if not return a null socket.
	*/
	command socket_t accept(socket_t fd);

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
	* This will pass the packet so you can handle it internally. 
	*    pack *package: the TCP packet that you are handling.
	* @Side Client/Server 
	* @return uint16_t - return SUCCESS if you are able to handle this
	*    packet or FAIL if there are errors.
	*/
	command error_t receive(pack* package);
	
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
	
	/*
	* Attempts a connection to an address.
	* @param
	*    socket_t fd: file descriptor that is associated with the socket
	*       that you are attempting a connection with. 
	* @param
	*    socket_addr_t *addr: the destination address and port where
	*       you will attempt a connection.
	* @side Client
	* @return socket_t - returns SUCCESS if you are able to attempt
	*    a connection with the fd passed, else return FAIL.
	*/
	command error_t connect(socket_t fd, socket_addr_t * addr);
	
	/*
	* Closes the socket.
	* @param
	*    socket_t fd: file descriptor that is associated with the socket
	*       that you are closing. 
	* @side Client/Server
	* @return socket_t - returns SUCCESS if you are able to attempt
	*    a closure with the fd passed, else return FAIL.
	*/
	command error_t close(socket_t fd);
	
	/*
	* A hard close, which is not graceful. This portion is optional.
	* @param
	*    socket_t fd: file descriptor that is associated with the socket
	*       that you are hard closing. 
	* @side Client/Server
	* @return socket_t - returns SUCCESS if you are able to attempt
	*    a closure with the fd passed, else return FAIL.
	*/
	
	command error_t release(socket_t fd);
	
	/*
	* Listen to the socket and wait for a connection.
	* @param
	*    socket_t fd: file descriptor that is associated with the socket
	*       that you are hard closing. 
	* @side Server
	* @return error_t - returns SUCCESS if you are able change the state 
	*   to listen else FAIL.
	*/
	command error_t listen(socket_t fd);

} // End interface
