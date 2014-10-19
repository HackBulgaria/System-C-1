# Memory management.



Every process uses memory to store its data. There is static memory, stack memory or something like that and - dynamic memory.

malloc and free - these system primitives call the kernel to free some memory for our program to store some things in. It also does not allow other processes to write there.
When our program stops - the kernel frees all the memory it gave to the process.

Memory leaks? Why we should use dynamic memory? It is complex and makes memory leaks.

Check out the source of malloc, alloc, free, bzero, calloc. 

Memory alignment. 

http://www.makelinux.net/books/lkd2/ch19lev1sec3

http://lwn.net/Articles/260832/

Memory paging.

http://www.linux-tutorial.info/modules.php?name=MContent&obj=page&pageid=89

How to make a log into malloc - this Friday will be fun.

Make a log into malloc if you think the other tasks are too easy for you.

Make a memory leak.

Make a process use a limited amount of memory, so it does not eat all our memory.
