Desciption: Need to receive udp packets from one port (multicasted) and send on other port to localhost.

Steps:
0) Create udp_bridge.services and paste the below:
    

************************************************************
[Unit]                                                                                                                                                                                                                                                                                                                        
After=network.service
 
[Service]
ExecStart=/bin/test_code.py
 
[Install]
WantedBy=default.target

************************************************************

************************************************************
********* test_code.py **************
#!/usr/bin/python3                                                                                                                                                                                                                                                                                                            
import socket
import struct
 
MCAST_GRP = '224.1.1.1'
MCAST_PORT = 5007
IS_ALL_GROUPS = True
 
 
UDP_IP = "127.0.0.1"
UDP_PORT = 5005
MESSAGE = "Hello, World!"
 
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
if IS_ALL_GROUPS:
    # on this port, receives ALL multicast groups
    sock.bind(('', MCAST_PORT))
else:
    # on this port, listen ONLY to MCAST_GRP
    sock.bind((MCAST_GRP, MCAST_PORT))
mreq = struct.pack("4sl", socket.inet_aton(MCAST_GRP), socket.INADDR_ANY)
 
 
while True:
    try:
        sock.setsockopt(socket.IPPROTO_IP, socket.IP_ADD_MEMBERSHIP, mreq)
        break
    except:
        continue
 
 
send_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP
 
while True:
  # For Python 3, change next line to "print(sock.recv(10240))"
  data = sock.recv(10240)
  print("Recieved on {}", MCAST_PORT)    
  print(str(data))
  send_sock.sendto(data, (UDP_IP, UDP_PORT))
 
************************************************************


************************************************************
$ sudo chmod 744 /usr/local/bin/udp_bridge.sh
$ sudo chmod 664 /etc/systemd/system/udp_bridge.service

$ sudo systemctl daemon-reload
$ sudo systemctl enable udp_bridge.service
*************************************************************

1) After system is up: It starts running udp_bridge (Module should be added in systemctl)
2) Run the script to send multcast UDP packets (python file: multicast.py)
3) Run the cmd: nc -l -u 5005  (to check udp_bridge is working or not)



References:
https://linuxconfig.org/how-to-run-script-on-startup-on-ubuntu-20-04-focal-fossa-server-desktop

