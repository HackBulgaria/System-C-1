System-C-1
==========

The repository for the System ANSI C course for http://hackbulgaria.com


In this course we will get familiar with basic system C programming techniques and how they are applied in Linux/BSD distributions. The goal of the course is to give a good start to anyone who wants to play or work in this field.

In the course, we will cover the following topics:

- Vim and Emacs as IDEs. "Flame wars". During the course we will introduce different system tools used for the development process, like grep, cat, tail and others.

- Build of projects, tools for dependency resolving, problems with building a software project. 

- I/O from devices, consoles, sockets. Processor interruptions and I/O.

- Debuging with GDB - how to use GDB on a local and remote machine.

- Memory management what happens when we allocate and free memory. How does the kernel manage the memory. Reference counters and other popular techniques. Not using dynamic memory?!

- Debuging of memory - Valgrind. How to make memory leaks and how to find and fix them later. 

- How to debug with traces and logs, why Gdb is not enough. Using syslog and /var/log/messages. How to make processes nad plugins to show logs and how to read them.

- fork and exec, relations between processes. Making daemons and state machines with fork and exec. Inter process communications.

- mutex, locks how to make IPC work right(at least a little bit right).

- Multithreading - Posix threads, strings

- Finding 3-4 open source projects and analyzing, possibly documenting their code.(Raver(has gread code), Aircrack-ng(...horrible code) )


## Course Program

1. Choosing your IDE and basic C. Vim, Emacs, Geany, Eclipse?!?!,….

    1.1. Installation, plugins

    1.2. Configuration

    1.3. Using it on remote machine

    1.4. Excersises with arryas(compiling single files, no makefiles)

    1.5. Excersises with IO files


2. Build of projects in C

    2.1. Makefiles - good sides and bad sides

    2.2. cmake, make, gcc

    2.3. Using libraries, dynamically and statically 

    2.4. Helpful tools- ldd, nm,(others)..

    2.5. Excersises with data structures and some libraries(pcap, maybe others)
    
3. I/O from devices 

    3.1. How to find our device - dmesg and /dev 

    3.2. How to sniff communication between PC and device 

    3.3. Libraries for commmunicating with devides, making your own primitive one. 

    3.4. Excersises with bluetooth mice, USB flash sticks(and other devices to be found) 


4. Debuging with Gdb

    4.1. Attaching to process, using the source code.

    4.2. Breakpoints, steping through code, layout mode.

    4.3. Debugging and developing code from previous excersise.

5. Memory management.

    5.1. Stack and dynamic memory, how they are filled, aligned and cut into pieces.

    5.2. Good practices for good memory.

    5.3. Rewriting the code from the previous excersise using dynamic memory.

6. Debuging the dynamic memory.
    6.1. Valgrind.

    (6.2. TBD)

    6.3. Fixing memory leaks in our code from the previous excersise.

7. How to debug with traces and logs. (unfinished chapter)

    7.1. Using syslog, /var/log/messages. 

    7.2. How to configure logs in processes and plugins.

    7.3. Add log to our code

    7.4. Seeing real life bugs and their logs.(flash player and other software)

8. fork and exec

    8.1. Relationships between processes.

    8.2. Daemonising and state machines.

    8.3. Making a process that forks and execs stuff.

    8.4. How to debug and restrict forking and exec.

9. Inter process communication.

    9.1. sockets

    9.2. pipes

    9.3. shared memory    

    9.4. Excersise - making a primitive server client.

    9.5. Excersise - making a primitive IPC between a group of processes using shared memory.

10. mutex, locks how to make the IPC work properly (no race condition)

    10.1. shared memory locking

    10.2. semaphors

    10.3. mutex

    10.4. Excersise - making a primitive IPC between a group of processes using shared memory properly.

11. Posix threads and fibers as threads

    11.1. Very easy.

    11.2. Synchronisation hurts.

    11.3. Excersise - making a simple state machine with threads who stop and play each other.

12. Choosing 3-4 open source projects and having fun with them.


