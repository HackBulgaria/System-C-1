# fork and exec

1. Relationships between processes.

pstree

THE HOLY CREATOR! -> parent -> child -> zombie -> reaped zombie

https://idea.popcount.org/2012-12-11-linux-process-states/

8.2. Daemonizing

http://codingfreak.blogspot.com/2012/03/daemon-izing-process-in-linux.html

8.3. State machines

We start our process, and it listenes for something. It may block the execution of a bash script until something happens.

Our process has become a deamon. It listenes for stuff and things and then parses the signals he got and fork and maybe then execs something to do the job. The file descriptors are saved in the fork, so it is really nice when you make a server it will have the socket for the connection. Interesting - how come two processes have the same socket?

8.4. Making a process that forks and execs stuff.

Usually when you fork, you exec another process. How does one debug that?

8.5. Restrict forking and exec. 

gdb --follow-fork or something like that

#Posix threads and fibers as threads

11.1. Very easy. Much fun. 

http://en.wikipedia.org/wiki/POSIX_Threads

https://computing.llnl.gov/tutorials/pthreads/ - long, long read

Synchronisation hurts. We'll do it next time.

