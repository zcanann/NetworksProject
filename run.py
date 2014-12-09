#ANDES Lab - University of California, Merced
#Author: UCM ANDES Lab
#$Author: abeltran2 $
#$LastChangedDate: 2014-08-31 16:06:26 -0700 (Sun, 31 Aug 2014) $
#! /usr/bin/python
import sys

from TOSSIM import *
from packet import *

t = Tossim([])
r = t.radio()
numMote=0

# Load a topo file and use it.
def loadTopo(topoFile):
    print 'Creating Topo!'
    # Read topology file.
    topoFile = 'topo/'+topoFile
    f = open(topoFile, "r")
    global numMote
    numMote = int(f.readline());
    
    print 'Number of Motes', numMote
    for line in f:
        s = line.split()
        if s:
            print " ", s[0], " ", s[1], " ", s[2];
            r.add(int(s[0]), int(s[1]), float(s[2]))

# Load a noise file and apply it.
def loadNoise(noiseFile):
   if numMote == 0:
      print "Create a topo first"
      exit();
   # Get and Create a Noise Model
   noiseFile = 'noise/'+noiseFile;
   noise = open(noiseFile, "r")
   for line in noise:
      str1 = line.strip()
      if str1:
         val = int(str1)
      for i in range(1, numMote+1):
         t.getNode(i).addNoiseTraceReading(val)

   for i in range(1, numMote+1):
      print "Creating noise model for ",i;
      t.getNode(i).createNoiseModel()

def bootNode(nodeID):
    if numMote == 0:
        print "Create a topo first"
        exit();

    t.getNode(nodeID).bootAtTime(1333*nodeID);

def bootAll():
    i=0;
    for i in range(1, numMote+1):
        bootNode(i);

def moteOff(nodeID):
    t.getNode(nodeID).turnOff();

def moteOn(nodeID):
    t.getNode(nodeID).turnOn();

def package(string):
    ints = []
    for c in string:
        ints.append(ord(c))
    return ints

def run(ticks):
    for i in range(ticks):
        t.runNextEvent()

# Rough run time. tickPerSecond does not work.
def runTime(amount):
    i = 0
    while i < amount * 1000:
        t.runNextEvent() 
        i = i + 1

#Create a Command Packet
msg = pack()
msg.set_seq(0)
msg.set_TTL(15)
msg.set_protocol(99)

pkt = t.newPacket()
pkt.setData(msg.data)
pkt.setType(msg.get_amType())

# COMMAND TYPES
CMD_PING = "0"
CMD_NEIGHBOR_DUMP = "1"
CMD_ROUTE_DUMP = "3"
CMD_TEST_CLIENT = "4"
CMD_TEST_SERVER = "5"
CMD_CLIENT_CLOSE = "6"
CMD_HELLO = "7"
CMD_MSG = "8"
CMD_WHISPER = "9"
CMD_ListUsr = "!"

# Generic Command
def sendCMD(string):
    args = string.split(' ');
    msg.set_src(int(args[0]));
    msg.set_dest(int(args[0]));
    msg.set_protocol(99);
    payload=args[1]
    
    for i in range(2, len(args)):
        payload= payload + ' '+ args[i]
	
    msg.setString_payload(payload)
    
    pkt.setData(msg.data)
    pkt.setDestination(int(args[0]))
    
    pkt.deliver(int(args[0]), t.time()+5)

def cmdPing(source, destination, msg):
    dest = chr(int(destination))
    sendCMD(source +" "+ CMD_PING + dest + msg)

def cmdNeighborDMP(destination):
    sendCMD(str(destination) +" "+ CMD_NEIGHBOR_DUMP)

def cmdRouteDMP(destination):
    sendCMD(str(destination) +" "+ CMD_ROUTE_DUMP)

def cmdTestServer(destination, port):
    sendCMD(str(destination) +" "+ CMD_TEST_SERVER + chr(int(port)))

def cmdTestClient(client, destination, srcPort, destPort, transfer):
    sendCMD(str(client) +" "+ CMD_TEST_CLIENT + chr(int(srcPort)) + chr(int(destPort)) + chr(int(destination)) + string_to_byteArr(transfer, 2))
    
def cmdClientClose(client, destination, srcPort, destPort):
    sendCMD(str(client) +" "+ CMD_CLIENT_CLOSE + chr(int(srcPort)) + chr(int(destPort)) + chr(int(destination)))



def cmdHello(client, destination, srcPort, destPort, username):
    sendCMD(str(client) +" "+ CMD_HELLO + chr(int(srcPort)) + chr(int(destPort)) + chr(int(destination)) + username)

def cmdMsg(client, destination, srcPort, destPort, message):
    sendCMD(str(client) +" "+ CMD_MSG + chr(int(srcPort)) + chr(int(destPort)) + chr(int(destination)) + message)

def cmdWhisper(client, server, serverPort, username, message):
    raise Exception("Whisper not implemented")

def cmdListUsr():
    raise Exception("ListUsr not implemented")



def sendInput(client, server, serverPort, inputStr):
    ArgCount = 0
    Command = ''
    ArgA = ''
    ArgB = ''
    
    if (inputStr.endswith("\r\n") == False):
        raise Exception("String should end with \r\n")
    
    # Trim off the end line stuff
    inputStr = inputStr[:-2];
    
    if (inputStr.find(" ") == -1):
        # No arguments given
        ArgCount = 0
    else:
        # Could be more, we will figure it out later
        ArgCount = 1
    
    # Process strings with no arguments
    if (ArgCount == 0 and inputStr == "listusr"):
        cmdListUsr();
        return
    elif (ArgCount == 0):
        raise Exception(inputStr + " - Unknown command or invalid arguments [a]")
    
     # Grab command and first argument
    Command = inputStr.split(' ', 1)[0]
    ArgA = inputStr.split(' ', 1)[1]
    
    if (ArgCount == 1 and Command == "msg"):
        cmdMsg(client, 0, server, serverPort, ArgA + "\r\n")
        return
    
    # Check for a 2nd argument
    if (ArgA.find(" ") != -1):
        ArgCount = 2
        ArgB = ArgA.split(' ', 1)[1]
        ArgA = ArgA.split(' ', 1)[0]
    
    if (ArgCount == 2 and Command == "whisper"):
        cmdWhisper(client, server, serverPort, ArgA, len(ArgA), ArgB + "\r\n")
        return;
    elif (ArgCount == 2 and Command == "hello"):
        cmdHello(client, ArgB, server, serverPort, ArgA + "\r\n")
        return;
    
    raise Exception(Command + "/" + ArgA + "/" + ArgB + " - Unknown command or invalid arguments [b]")
    

def string_to_byteArr(stringVal, num_bytes):
    return str(bytearray([(int(stringVal) & (0xff << pos * 8)) >> pos * 8 for pos in range(num_bytes)]))

def addChannel(channelName):
    print 'Adding Channel', channelName;
    t.addChannel(channelName, sys.stdout);

###################################################
###################################################
###################################################

runTime(10);
#loadTopo("long_line.topo");
#loadTopo("short_line.topo");
#loadTopo("linkstate.topo");
#loadTopo("complex.topo");
#loadTopo("complex2.topo");
loadTopo("pizza.topo");
#loadTopo("well_connected.topo");
#loadTopo("diamond.topo");
#loadTopo("diamond_dexter.topo");
#loadTopo("long_circle.topo");
#loadTopo("long_circle_connected.topo");

loadNoise("no_noise.txt");
#loadNoise("heavy_noise_10_.txt");
#loadNoise("heavy_noise_30_.txt");

bootAll();
addChannel("cmdDebug");
#addChannel("genDebug");
#addChannel("Project1F");
#addChannel("Project1N");
#addChannel("Project2");
addChannel("Project3");
addChannel("Project4");

runTime(300);
cmdRouteDMP(2);
runTime(20);
cmdTestServer("2", "41");
runTime(30);
sendInput("6", "41", "2", "hello mzedong 19\r\n");
runTime(30);
cmdRouteDMP(1);
runTime(30);
#sendInput("6", "41", "2", "msg 1234567890123\r\n");
sendInput("6", "41", "2", "msg sup nerds\r\n");
#runTime(10);
#sendInput("1", "41", "2", "hello vlenin 25\r\n");
#runTime(10);
#cmdTestClient("12", "12", "41", "2", "2048");
#runTime(10);
#cmdTestClient("8", "13", "41", "2", "1024");
#runTime(10);
#cmdTestClient("11", "14", "41", "2", "512");
runTime(2000);
cmdRouteDMP(1);
#runTime(10);
#cmdClientClose("12", "12", "41", "2");
#runTime(10);
#cmdClientClose("8", "13", "41", "2");
#runTime(10);
#cmdClientClose("11", "14", "41", "2");
#runTime(40000);
#cmdRouteDMP(1);
#moteOff(6);
#runTime(100);
#cmdRouteDMP(1);
#runTime(10);
#cmdPing("1", "12", "Hello, World 3");
#runTime(25);
#cmdPing("1", "10", "Goodbye, World 1");
#runTime(10);
#cmdNeighborDMP(2);
runTime(100);
