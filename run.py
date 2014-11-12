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
    dest = chr(int(destination));
    sendCMD(source +" "+ CMD_PING + dest + msg);

def cmdNeighborDMP(destination):
    sendCMD(str(destination) +" "+ CMD_NEIGHBOR_DUMP);

def cmdRouteDMP(destination):
    sendCMD(str(destination) +" "+ CMD_ROUTE_DUMP);

def cmdTestServer(destination, port):
    sendCMD(str(destination) +" "+ CMD_TEST_SERVER + chr(int(port)));

def cmdTestClient(client, destination, srcPort, destPort, transfer):
    sendCMD(str(client) +" "+ CMD_TEST_CLIENT + chr(int(srcPort)) + chr(int(destPort)) + chr(int(destination)) + string_to_byteArr(transfer, 2));
    
def cmdClientClose(client, destination, srcPort, destPort):
    sendCMD(str(client) +" "+ CMD_CLIENT_CLOSE + chr(int(srcPort)) + chr(int(destPort)) + chr(int(destination)));

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
bootAll();
addChannel("cmdDebug");
addChannel("genDebug");
addChannel("Project1F");
addChannel("Project1N");
addChannel("Project2");
addChannel("Project3");

runTime(75);
cmdRouteDMP(1);
runTime(10);
cmdTestServer("1", "80");
runTime(10);
cmdTestClient("2", "12", "80", "1", "48");
runTime(10);
cmdClientClose("2", "12", "80", "1");
runTime(100);
cmdRouteDMP(1);
#moteOff(6);
#runTime(100);
#cmdRouteDMP(1);
#runTime(10);
#cmdPing("1", "12", "Hello, World 3");
#runTime(25);
#cmdPing("1", "10", "Goodbye, World 1");
#runTime(10);
#cmdNeighborDMP(2);
#runTime(10);
#cmdNeighborDMP(3);
#runTime(10);
#cmdNeighborDMP(4);
#runTime(10);
#cmdNeighborDMP(5);
#runTime(10);
#cmdNeighborDMP(6);
runTime(100);
