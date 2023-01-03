# T**hreads**

### defintion :

- A thread is a path of execution within a process. A process can contain multiple threads.
- A thread is the unit of execution within a process. A process can have anywhere from just one thread to many threads
    
    it comprise A thread Id A program counter A register set  and A stack
    
    it shares with other threads belonging to the same process its code section, data section, and ther operating-system resources, such as open files and signals.
    

![Screen Shot 2022-04-20 at 9.36.24 PM.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/abd548d4-d3b9-402f-9ca6-49a52da393cc/Screen_Shot_2022-04-20_at_9.36.24_PM.png)

                 single_threaded process                                        Multi_threaded process

- **Benefits of multithreaded** :
    - **Responsiveness** : One thread may provide rapid response while other threads are blocked or slowed down doing intensive calculations.
    - **Resource sharing** : By default threads share common code, data, and other resources, which allows multiple tasks to be performed simultaneously in a single address space.
    - **Utilization of multiprocessor architectures** : A single threaded process can only run on one CPU, no matter how many may be available, whereas the execution of a multi- threaded application may be split amongst available processors.

## difference between processe and thread !

## Mutex :

A Mutex is a lock that we set before using a shared resource and release after using it. When the lock is set, no other thread can access the locked region of code. So we see that even if thread 2 is scheduled while thread 1 was not done accessing the shared resource and the code is locked by thread 1 using mutexes then thread 2 cannot even access that region of code. So this ensures a synchronized access of shared resources in the code.

**Internally it works as follows :**

- Suppose one thread has locked a region of code using mutex and is executing that piece of code.
- Now if scheduler decides to do a context switch, then all the other threads which are ready to execute the same region are unblocked.
- Only one of all the threads would make it to the execution but if this thread tries to execute the same region of code that is already locked then it will again go to sleep.
- Context switch will take place again and again but no thread would be able to execute the locked region of code until the mutex lock over it is released.
- Mutex lock will only be released by the thread who locked it.
- So this ensures that once a thread has locked a piece of code then no other thread can execute the same region until it is unlocked by the thread who locked it.
- Hence, this system ensures synchronization among the threads while working on shared resources.

A mutex is initialized and then a lock is achieved by calling the following two functions :

<aside>
💡  int   pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
int pthread_mutex_lock(pthread_mutex_t *mutex);

</aside>

The first function initializes a mutex and through second function any critical region in the code can be locked.

The mutex can be unlocked and destroyed by calling following functions :

<aside>
💡 int pthread_mutex_unlock(pthread_mutex_t *mutex);
int pthread_mutex_destroy(pthread_mutex_t *mutex);

</aside>

The first function above releases the lock and the second function destroys the lock so that it cannot be used anywhere in future.

# semaphores

- A semaphore is a data structure used to help threads work together without interfering with each other.
    
                                                                                                                                                      by: Ali_louzizi
