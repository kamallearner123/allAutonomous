import socket
import struct
import sys
import time

message = 'very important data'
multicast_group = ('224.1.1.1', 5007)

# Create the datagram socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Set a timeout so the socket does not block indefinitely when trying
# to receive data.
sock.settimeout(0.2)
while True:
    sent = sock.sendto(message.encode(), multicast_group)
    time.sleep(1)
