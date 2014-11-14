
# Normal tasks

1. Make a server that holds one table  and clients can connect and append, rewrite and get the table.

2. In the producer-consumer problem, one process (the producer) generates data items and another process (the consumer) receives and uses them. They communicate using a queue of maximum size N and are subject to the following conditions:

    The consumer must wait for the producer to produce something if the queue is empty.
    The producer must wait for the consumer to consume something if the queue is full.

The semaphore solution to the producer-consumer problem tracks the state of the queue with two semaphores: emptyCount, the number of empty places in the queue, and fullCount, the number of elements in the queue. To maintain integrity, emptyCount may be lower (but never higher) than the actual number of empty places in the queue, and fullCount may be lower (but never higher) than the actual number of items in the queue. Empty places and items represent two kinds of resources, empty boxes and full boxes, and the semaphores emptyCount and fullCount maintain control over these resources.

The binary semaphore useQueue ensures that the integrity of the state of the queue itself is not compromised, for example by two producers attempting to add items to an empty queue simultaneously, thereby corrupting its internal state. Alternatively a mutex could be used in place of the binary semaphore.

http://en.wikipedia.org/wiki/Semaphore_%28programming%29#Example:_Producer.2Fconsumer_problem

3. Make a thread safe queue for two threads to send each other messages.
