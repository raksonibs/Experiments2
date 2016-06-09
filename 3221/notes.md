- os is an operating system acts as an intermediatry between user and computer hardware
- of is resource allocator
- os is a control program
- no universal defintion but one program is a kernal and either system program or application program
0 bootstrap program is loaded at powerup or reboot. typically stored in rom or eprom, known as firmware
  - insitalizes all aspects of system, loads operating system kernel and starts execution
-concurrent execution of cpu and devices competing for memory cycles
- i/o devices and cpu can execute concurrently. each devise controller has local bugger and type. cpu moves data from/to main memory to local buffer. i/o is from the device to local buffer of controller. device controler infroms cpu that is has finished its operation by causing an interrupt
- interrupt transfer control to the interrup service routine genrally, through the interrupt vector, which contains the addresses of all the service routines
- interrupt archeticture must save the address of interrupted instruction
- a trap or exception is a software gneerated interrupt cuased iether by an error or a user request
- an operating system is interrupt driven
- the operating system preservuces the state of teh cpu by storing registers and the program counter
-deremines which type of interrupt has occured, polling, vectored interrupt system.
- separate segements of code determine what action should be taken for each type of interrupt
- i/o structuer
  - after i/o starts, control returns to user program only upon i/o completion.. wait instruction idels the cpu until next interrupt. wait looop. at most on i/o request is outtanding at a time, no simultanous procesing
  - after i.o starts, control returns to a suer program without waiting for i/o completion
    - system call: request to os to allow user to wait for i/o completion
    - devicestatus table contains entry for each i/o device indictating is type, address, and state
    - os indexes into i/o device table to determine device status and to modify table entry to include interrupt

- storage strcutre:
  - main memory: only large storage media that cpu can access directly. RAndom access and it is vollatile
  - secondary storage: extension of main memory that provides large nonvolatei storage 
  - hard disks: disk surgace logically divied into tasks and disk controler determines the logical interaction between device and computer
  - solid state disk: faster than hard disks, nonvolatile
  - organized in hieracy of speed, cost, volatility
  - caching: copying info into faster storage system; main memory can be viewed as a cache for a secondary storage. device driver: for each device controller to manage i/o. provides uniform interace between controller and kernel. 
  - registers -> cache -> main memory -?ssd -> hard disk -> optical dism -> magnetic tapes

- caching:
  - information in use copied from slower to faster storage temporaly. cache checked first to determine if informationis there. if is, use from cache. if not, data copied to cache and used there. cachce smaller

- direct memory aceess used for high speed i/o devices able to transmit info close ot meory speeds. transfer block of data from bugger direction into main without CPU intervention. only oneinterrupt genreated per block, rather than one per byte
- most systems use single generalpurpose processor
- multiprocessors known as paralel systems, tightly coupted
  - increaed throughput, economy of scale, increased relaibility with graceful degradation
  - assymetic multiprocessing or systemmtric. symmetirci is where each processor perfroms all tasks

- dual core design: multichp and multicore.
- clustered systems: like multiprocesser but multipe systems work toegether. usually sharing storage via a sotrage area network.
- provides high availaiblity serivce which survives failures. 
- assymetic clustering has one machine in hotstandby mode, symmetric clustering has multiple nodes running applications, moitorig each other. 
- multiprogramming/batch system needed for efficinecy. single user cannot keep CPU and i/o decives busy at all times. multiprogramming organizes jobs so CPU always has one to excutue. job scheduling pcisk job. when has to wait, OS switches to another job.
- time sharing/multitasking is logical extension in which CPU switches jobs so freqnetly users can interact with each job while it is running, creating ineratcve computing. each user has at least one program executing in memory: process. 
- interrupt driven. hardware inerrupt by devices. softwar interrupt by exception or trp: software error, infinite loop, etc
- dual mode operation allows OS to protect itself and other system components. user mode and kernel mode.
- mode bit provided by hardware:
  - PROVIDES ABILITY TO DISTINGUISH WHEN SYSTEM RUNING. SOME ARE PRIVILEGED AND ONLY EXECTUble in kernel mode.
- timer to prvent loops/process hog transitioning from user to kernel
- a process is program in execution. program is passive entity wherein process is an active entity.
- process termination requires relcaim of any reusable resources.
- single threaded process has one program counter specifiying location of next instruction to execute. 
- single threaded process has one program counter
- multi has one per thread
-os does process management: handle deadlock, synchronization, etc
- to execute a program instruction must be inmemory. memory mangement determins what is in memory. 
- storage mangement where os provides unforim ogical view of inormation storage. 
- mass stoage management: free space, disk scheduling, storage alloation 
- multitasking enviromnets must be careufl to use most recent value, no matter where it is stored in storage hierachy
- multiprocessor environment must provide cache coherency.
- i/o subststem repsonsible for memory managemnet of io including buffering, spooling, caching, etc
- protection: controlling access of resouces.
- dtermine users by identities, group id, privlege escalation
- kernel data structures: single, double circular linked
- balanced binary search trea
- hash map
- bitmap string of binary digits reprecenting n iitems
- distrubted ocomputing: collection of separate heterogenous stems working toeghet
  - network is communicatons path: tcip.
  - network operating system provides features between systems across network
- client server computing/ peer to peer
- virtualization: allows os to run within other os
- system call implementation maintains a table indexed according to these numbers. the system call invokes intended system in os kernel and returns status of ssystem. 
- three ways to pass paramters to os: simpliest via rgisters.pushed onto stack and popped off. seocn way is parameter passing via table
- freebsd vs msdos: freebsd is mutitasking, create processes, etc
- ms ds written to provide most functionality with least space. no modules,
- unix os has system prorams and the kernel. 
- layered approach: operating system sepearted into layers and eac h functionality in layer
- microkernal: move as much from kernel into user space. more relaible and secure but perfromance overhard of user space to kernal space communication
-loadable kernel modules
- 

# ch 3
- operaticitng system excutes bach system/jobs, and timeshared systems: userprgorams
- process is program in execution.
-multiple parts:
  - code/text section
  - current cactivity including program counter, processor registers
  - stack continaing temp data like paratemres, address, local variables
  -data section cntinaitng global vars
  - heap containing memory dynamiclally allocated during run time
  - program is pasively , process is active
  - as process excutes changes state: new, running, waiting, ready, terminated
  - niformation assocaited with each process called task control block
    - process state:
    - program counter
    0 process number
    - registers
    - cpu schedluing info
    - memormy managemnt info
    - accounting info
    - i/o status information

pid t_pid; /* process identifier */
long state; /* state of the process */
unsigned int time_slice /* scheduling information */
struct task_struct *parent; /* this process’s parent */
struct list_head children; /* this process’s children */
struct files_struct *files; /* list of open files */
struct mm_struct *mm; /* address space of this process */

- process scheduling:
  - maximize cpu use
  - process schedulr selects among availbie processes
  - maintins scheduling queues: job queue, ready queue, device queue

- short term schedulers: select which process should be excuted next and allocates CPU
- long term schedulers: selects which should be in the ready queue. controlls degree of multiprogramming. proceses can be either io bound process (many short cpu burts)., or cpu bound process
- long term scheduled strives for good process mix
- medium term schedued can be adeed if degree of multiple programming needs to decreas

- context switch: when cpu swithes to another process, system must save the state of old process and load the saved state for new process. context of a process represented in the pcb. 
- process creation: parent process create children processes which create more forming tree. processs identifieds managed via process identfier
- rsouce sharing options

- process executes last statemnet then asks system to delete using ecit)_/ retuns stats daata from child to parent via wait()/ process reosuces are deallocated
- parent may terminate execution of children processes using abort() system call if child execced resocuces, task assigned to child no longer required, prent is exiting and thus kill cild
- could be cascading temrination where parent's children die
- pid = wait(&status); rturns status info and pid of terminate info
- if parent waiting, did not invoke wait, process is zombie, but if termination without invokgin wait, process is orphan
- google chrome is a multiprocess with three different types of processes: browser, rendere, plu in
-processes can be independnt or copperating. coppretaintg processes need interprocess commmunication. two types: shared memory and message passing
- paradigm for cooperating processes: producer produces info consumed by a consume. unbounded places no practical limit on size of bugger. bounded assumes there is a fixed buffer size. 

- interprocess communcation: shared memory
  - communcation under control of the users process not the operating system.
  - major issue is to provide mechanism that will allow the user process to synchornize actions
  - interprocess communcation: message passing
  - process communcate without resorting to shared variables.
  - if wish to connect need communcation link, and messages sent/received
  -communcation link: phyiscal or logcial
  - messaged recvieed from mailbozes also known as ports adn can communciate if share mailbox.
  - 
- message passing may be either blocking or non blocking. blocking is snynchonouns. 
- buffering:
  - queueof messages attached to link with zero capccity, bounded capacity, unbounded capacity

-ipc system: posix:
  - process first creates shared memory segment. set size of object, then can write to shared memory.

- mach system is message based. each task gets maiblboxes. 
- communications in client server systems, sockets remote procedure calls, etc.

- multithreaded server archeticture:
  - client, request, server creates new thread to service the request, thread then has server resume listening for additonal client requests
  - benefits: allow for conintued exction if part of process is blocked, especially important for user interfaces
  - resource sharing: threads across resource shearing
  -economy cheaper than process creation
  - multicore programming: dividing activiteis, balance, data splitting, data depedency
  - parallelism: implies can perofmr more than one taks ismilutatnously
  - concurrency supports more than one task makig progress
  - data parallelism: distrubtes subsets of same data across multiple cores, same operation
  - task parallelism: distrubtuing threads across cores, each thread perfomance
  - as # of threads grows, so does archeticural support for threading
  concurrency vs parallism: multiple cores splitting tasks.
  - amdahl's law: perfromance gains from addition additonal cores to an applicatttion that has both serial and parallel components
  - serial portion of an application has disporotionate effect on perfomance gained  by additional additonal cores
  - user threads management done by userlebel threads, or kernal threadas
  - many to one multithreads, one to one, many to many
  - two level allows user thread to be bound to kernel thread
- p threads may be either user level or kernel level
- implicit threading: creation and managemnt of threads done by compilers and runtime libraries rather tha nprogrammers
- thread pools: create a nuber of threads in a pool where they awat work
  - slightly faster to service a request with an exisitng thread rather than create a new thread
  - allows number of threads in applcation to be bound to size of pool
  - separating task to be performed from mchains of creating task
- openMP set of compilter directives
- runs loop in parallel

- grand central dispatch:
  - allow idnetification of parallel sections, details via threading,. blocks placed in dispatch queue.
  - two types of dispatch queues:
    - serial: blocks removed in FIFO order, queue is per process, called main queue
    - concurrent: removed in fifo order but serval may be removed at time
  - threading issues:
    - semantics of fork and exec
- signal handling
  - signals used in unix to notify a process
    - signal genreated with default or user defined handlers
  - thread cancaellation
    - thread to be canccled is target thread with two general approches: asynchyonous cancellation, defrerred cancelation
  - invoking thread cancellation requests cancellation, but actual
cancellation depends on thread state
  - If thread has cancellation disabled, cancellation remains pending
until thread enables it
- canceleation only occurs when thread reaches 
- thread local storage allows thread to have its copy of data  
- both mm and two lebel models requires communication to maintain the approrpate number of kernel threads
- tpyically use intermidate data strcutre between user and kernel threads a lightwear process
- 