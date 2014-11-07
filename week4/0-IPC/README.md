#Inter process communication.

One process connects to another process and talks with him. 

http://en.wikipedia.org/wiki/Inter-process_communication

1. sockets

Server opens a listening sockets, the client connects to it. Then the server creates another socket to communicate with the client and remain listening for other clients.
The code you have to write for this is rather long. You can make a wrapper to make it short and neat.

http://www.thegeekstuff.com/2011/12/c-socket-programming/

2. pipes

http://hzqtc.github.io/2012/07/linux-ipc-with-pipes.html

3. shared memory

http://simplestcodings.blogspot.com/2010/08/ipc-shared-memory-implementation-in-c.html

http://www.cs.cf.ac.uk/Dave/C/node27.html - these guys have written way too much code.

