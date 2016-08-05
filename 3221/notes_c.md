- maximum cpu with multiprograming
- cpu burst bollowed by io burst
- short term schedulerselects from processes in ready queue
- switch from running to waiting, runnning to ready, waiting to ready, or terminates
- above is nonpreemptivve, all others are preemtive like shared data etc
- dispatcher gives control of cpu to process selected by shortterm scheduler, sitches context etc.
- dispatch latency time it takes for dispatcher to stop one process and start another
- cpu utilization: keep cpu as busy as possible
- throughput - # of processes completed per time
- waiting time: amount of time a process has been waiting in ready queue
- response time: amount of time it takes from when a request was submitted until first response is produced, not output
- fcfs scheduling: as they come. but dependendent on order of processes. when slow come first, better average wiaiting time
- shortestjobfirst scheduling: associate process length of next cpu and select shortest time. this is optimal, but difficult to kno length of next cpu burst
- could use exponential averaging or prediction similiar to next one for next cpu burst
- a priority number associated with each process
- cpu is allocated to process with highest priperity (smallest ingeger)
- SJR is where priority is inverse of predcited next CPUbrst time
- starvation: low prioirty processes may never execute
- solution: aging: as time progress, increase priority of process

- round robin: each process gets small unit of CPU time (time qunatum), once time is elapsed process is preempted and added to end of the ready queue
- if there are n processes in ready queue and the time qauntim is q, each process gets 1/n of the CPU time in chunks of at most q time units. no process waits more than (n-1)q time units.
- if q is large == FIFO
- if q is small == too many context switches
- higher average turn around than SJF but better response. 
-80% of cpu bursts should be shorter than q

- multilevel queue: ready queue partioned into separted queues, a foreground interactive and a background batch queue
- process permanately in given queue. 
- foreground is in RR
- background is in FCFS
- scheduling must be done between the queues. Fixed priprity scheulding is serving all foreground first then go background. 
- Time slice is similiar to RR with each queue gets some time for schedulng, 80% forgreound, 20% background
- process can be moved between queues: again
- multilevelfeedbackqueue implemented: number of queues, scheduling alg for each queue, method used to deterine when to upgrade a process, method used to deteremine when to demote a process, method used to determine which queue a process will enter when that process needs service
- A new job enters queue Q0 which is
served FCFS
 When it gains CPU, job receives 8
milliseconds
 If it does not finish in 8
milliseconds, job is moved to
queue Q1
 At Q1 job is again served FCFS and
receives 16 additional milliseconds
 If it still does not complete, it is
preempted and moved to queue Q2
-

- thread scheduling exists: many to one and many to many, schedules user level threads to run on LWP, known as process conention scope since schulding compeition is with process
- kernal thread scheduled onto availaible CPU is system contention scope
-can schedule ptrheads with PTRHEAD_SCOPE_PROCESS/SYSTEM
- 

/* set the scheduling algorithm to PCS or SCS */
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
 /* create the threads */
 for (i = 0; i < NUM_THREADS; i++)
 pthread_create(&tid[i],&attr,runner,NULL);
 /* now join on each thread */
 for (i = 0; i < NUM_THREADS; i++)
 pthread_join(tid[i], NULL);
}
/* Each thread will begin 

- homogeouns processors withing multiprocessor
- assymetiric multiprocessing: only one processor accesses system data sctructures
- symmetric multiprocessing, each process is self scheduling
- processor affinity: soft/hard 
- if SMP, need to keep all CPUS loaded for efficieny via load balancing: makes workload distributed. Push migration: periodic task checks load on each processor, pull migration: idel processors pulls waiting task from busy processor
- real time scheduling: softrealtime systems: no guarantee when critical process is scheduled. hard realtime system: taks must be served by a deadline
- two latencey affecies: interrupy latency (time from arrival of interrupot to start of routine), dispatch latency: time for schedule to take current process of CPU and switch to another
- for realtime schedlung, scheduler must supprt preemptive prority based scheduling
- processes have new charactierstics: periodic ones require cpu at constant intervals. 
- virtualization software schedules mutliple guest into cpu. 
- rate montonic scheduling: prioirty is assigned based on invierse of its period. shorter periods = highe rpriority
- earliest deadline first scheduling
- proprotional share scheduling: t shares are allocated among all processes in the system, an application receives n shares here n < T. ensures each application will receive N/T total processor time
- posicrealteim schedluing has SCHED_RR and SCHED_FF

- deadlocks prevent set of concurrent processes from ompleting their tasks
- system consists  fo reousrces and has so many instances. each process utilizes a reousrece as follows: request, use, release
-deadlock happens when four happen simultanouesly:
  - mutual exclusion: only one process at  time can use resource
  - hold and wait: processs olding at least one resource is waiting to acquire additional resources held by other processes
  - no preemption: a resouce can be released only voluntarily by the process holding it, after that process has completed its task
  - circular wait: there exists a set of processes waiting thatthey reference one another

- deadlocks can happen with mutexes
- requrested edge, process to resource
- assignment edge: direct edge rsouce to process
- if graph contains no cycles => no deadlokc
- if graph contians cycle: and only one instance per resouce type, deadlock
- deadlock avoidance/prevention
- restrain the ways requests can be made: 
  - mutual exlucion: not required fro shareable reosurces. must hold non shareable reousrces
  - hold and wait: must guarante that when process requests a resource, does not hold any other resouce. make process request all of its reousces before execution
  - no premeption: ir a process holding another resouce that canot be immediately allocated, then all are relaeased
  - circular waite: impose a total ordering of all and make prcess request according to increasing order
  -

- deadlock avoidance:
  - require apriori knwoldge
  - simplest and most useful declare max number of reosuces of each tiype. 

- safe state: when process requests an avaialbe resouce, must declare if immediate allocaiton leaves the system in  a safe space. safe space if there exists a sequence of process such that reousce be can stil request can be satifised currently availabe roeucres
-if system is in safe state = no deadlocks
- unsafe sapace = possible
-avoidance = make sure nevr enter unsafe space
- use banker's algorhtim when multiple reousce types, or resoure grap when one
- claim edge: p-> r indcaed process may request
- banker's algorhtim: each process must a prorio claim max use. when process requests a resource it may have to wait. when a process gets all its resources it must return them in a finite amount of time

- safety allgoruthm: work and finish when all finish is true.
- recovery from deadlock: resource presmetion, or termination

- a pair of base and limit registers define logical address space
- cpu check every memory acess generated in user mode to user it is ebtween base and limit for that user
- programs on disk form an input queue
- binding to memory addresses happens at:
  - compile time, if memory knowkn a prioiri, absolute code can be generated
  - load tiem: must generate reloctable code if memory not known
  - excecution time: binding delaying until run time if process can be moved

- logical address space bound to separate physical address space
  -logical address generated by CPU
  -physical address seen be memory unit
- same but differ in execution time
- memory management unit mapes virtual to physical address
- base rgeister is called relocaiton regsiter
- execution time binding occurs when refrence made to location in memory
- dynamic relocation using a relocation register. not loaded until it is called. better memory space utilization
- dnamiyc linking:
  - static linking system libraries and program code cominder by loaded
  - linking poistoing until execution time in dynamic linking
  - small piece of stub code used to locate approtiate memoryresident library routine
  - stub replaces itself with address of routine, and executes the routine
  - 
- swappping: temp out of memory to a backing store, then brought back into memory for continued exection. 
- backing store: fast disk to acccomodate copies of all memory images for all uses; must provide direct access to these memory images
- roll out roll in: swapping variant used for priority based scheduling aloghtims. 
- system maintins ready queue of ready to run processes
- if next processnot in memeory need to swap out process and swap in target process. context switch very high
- double buffering is contrast always tranfer i/o to kernal space, then i/o device. this adds overhead
- not typically support to swap on mobile systems. flash memory based. usually just ask to reliniquish memory if memory low
- contiguous allocation: main memory. limited resouce. usually in two partions, the resident operating system, usually held in low memory with interrupt vector. user processes held in high memory. each process contained in single continguous section of memory
- reloaction registers used to protect processes. base register contains value of smalllest physical address. limit register contains range of logical addresses, ach logical address must be less than limit register. MMU maps logical address dynamically. allow kernel bode being transient and changing size
- degree of multiprogramming limited by number of partitions
- variable partion sizes for efficenciy
- hole: block of memory available
- when process arrives it is allocated memory from a hole large enough to accommodate it
- process exiting frees partition
- dynamic storagge allocation problem: firstfit: allocate the first hole big enough. Best-fit: allocate smallest hole that is big enough. Worst fit: largest hole
- external fragmentation: total memory space exists to satisfy a request, but it is not contiguous
- internal fragmentation: allocatied memory may be slightly larger than requested memory.
- 0.5N blocks lost to fragmenetation: 50% rule
- reduce extenral fragamaention by compaction: shuffle memory contents to place all free memory in one block. only possible if relocation dynamic and done at execution time
- segmentation: logical unit of memory
- logical address consists of two tuple <segment number, offset>. Segment table: maps two dimensional physical address that has base: starting physical adrdress, and limit: specifics the length of the segment
-segment number is legel if s < STLY (segment length register)
- protection bits have a validation bit with read/write/execute priveleges
- paging: physical adddress space of process can be noncontiguoes, avoids external fragmation. avoids problem of varying sized memory chunks.
- divide physical memory into frames. Didive memory into blocks call pages.
- address translation scheme: address generated into page number for page talbe, and page offset combined with base address to define physical memory
- two memory problem solved by lookup hardware case called translation look-aside buffers. TLBs store address-space identifiers which uniquely identify each process to provide address space protection for that process. otherwise need to flush at every context switch. if miss, value is loaded for faster access next time. can be wired down for permananet fast access
- associative memory: parallel search if p is in register, get frame out. 
- effective access time: 2 + E - a where A is hit ratio, perfcentage of time page number is found in associated registers. E is associative lookup
-memory protection implemented by associating prtoection bit with each frame to indiciate if read-only or read-write acess allowed. Valid invalid bit attached to each entry in page table. 
= shared pages: one copy of rentrant, readonly code
- structure of page table: memory strucutres for paging can be:
  - heirrachical page tables: break up the logical address space into multiple page tables. ex: 32 bit machine split into page number of 22 bits and page offset of 10 bits. The page number is further divided into a 12 bit page number and 10 big offset
  - known as forward mapped page table
  - hashed page tables: virtual page is hashed into a page table which contains chain of elements hashing to same location. Each element contians virtual page nuber, value of mapped page frame, and pointer to next element. virtual page numbers are compared in this chain searching for a match. could be clustered page tables with each hash refers to several pages
  - inverted page table: track all pages, one entry to each real page of memory. entry consits of virtual address of page stored in real memory.
  -

  - code needs to be in memory butentire rpgraom rarlery used
  - partially loaded program: not constarineted by limits of phyiscal memory. each program takes less memory while running
    - increased cpu uitlization
    less i/o needed to swap programs
- virtual memory: speartion of logical memory from physical memory
  - only part needs to be in memory for exection. soe much larger physical address space
  - virtual address space usually start at address 0, contiginous until end of space. physical memory organized in page grames
- design logical address space for stack to start at max logical space and grown down while heap grows up
- unused space between two is hole
- enables sparse address space with holes left for growth
- demand paging: could bring entire process into memory at load time, or bring when needed. page is needed => refrence it
- lazy swapper: never swaps a page into memory unless page will be needed. 
- with swapping, pager guesses which pages will be used before swapping out again
- instead pager brings in only those pages
- if pages are needed are already memory resident no difference from nondemand paging. if not, need to detect and load page into memory from storage
= valid/invalid bit is associated in memory. v is in memory and memory rsident, i not in memory. intially all is set to i
- during MMU address translation, if i, entry is page fault
- if there is a reference to page, first refecne to that page will trap to operating system: page fault
- if page fault, just find free frame and swap page intro gramde via scheduled disk operation
- reference, trap, page is on backing store, bring in missing page, reset page talbe, restart

- aspcets of demand paging:
  - extreme case: start process with no pages in memory
  - pure demand paging
- could be multiple page faults: pain decreased because of locality of reference. 
- hardaware support for demand paging: page table with valid/invalid bit, secondary memory with swap space, insctruction restart
- instruction restart:
  - block move, auto increment/decrement location
- performance of demang paging:
  - service the interupt, read the page, restart the process
  - effectve access time: 
- optomize demand paging: swap space i/o faster than file system, copy entire process image to swap space at process load time
- 

- copy on write: allows both parent and child process to initally share same pages in memory
- free pages allocated rfrom a pool of zero-fill-on-demand pages: vfork()
- if no free frame: page replacement. same page brought many times into meomry
- page replacement: prevent overallocation of memory by modifiginy serivce tourinte or use dirty bit to reduce overhead
- find location of page, find free frame, bring into free frame
- frame allocation algorthim, page replacement algorthim
-fifo algorthim: Belady's anomly: more frames casue more page faults
- optimal algorthim: replace page that will not be used for longest period of time.
-least recentyl used algorthimg, past knowldge rather than future
-counter immpentation or stack implemtnation
-LRU needs refernce bit and second changce algrothim 
- page buffering algorthims: keep a pool of freen frames,
-memory intensive applcations have double buffering: os keeps copy aof memory, so does applciation
-fixed allocation:
  - equal allocation for all processes
  - proprtional allocation, according to size of process
  - priortiy allocation: use proprtional using priotties rather than size
  - 
- global replacement: process selects replacement frame from all other frames, process excution time varies greatly, but thorughout greater.
- local replacement: slects from own local frames, more consistent
- many memory systems are nonuniform memory acesss
- optimal preforamnce comes from allocation memory close to cpu on which thread is schedueld
- thrashing: if a process does not have enough pages, page fault rate is so high. thrasing = a process is busy swapping pages in and out
- locality model: process migrates from one to another. thrasing occurs when size of locatiy > total memory size
- working set model: total number of pages referneces in most recent. if too small, not encompas everyhing, if too large encomopes all locailitys. if D > M, thrrasing. D is total deman frames. so if d is more than all working set frames, thrasing
- establish acceptable page falut frequency, if too low process loses frame but gains frame when too hgih
- direct relationship between working set of process and page fault rate. 
- memory mapped fiels: file to be trated as routine memory acess by mapping a disk block to a page in memory.allows several processes to map the same file allowing the pages in memory to be shared
- mmap()
-buddy system: allocations memory from a fixed sixed segment of phyicsally ocntinugos pages. allocated using powerof2 allocatioer. requets in units sized power of 2. avdvantge: quickly coalsce unused chunks into larger, disadvantage: fragementation
-slab allocation: single cache for each unique kernal data strcture. filled with objcets, when cahce created objects marked as free, when stored marked as used. when all full, allocated from empry slab. if no new slabes, new slab allocation. no fragementions
- pages must sometimes be locked into memory. pinning of pages to lock into memory
-

- principles of least protection:
  - given just enough privelges
  - limits damage if bug or gets abused
  - or dynamic with domain switchingg, privelge escalation
  - grain aspect: rough grained privleage management easier, simpler but least privelged
- domain strucutre: access-right: where rigghts-set is a subset of all valid operations that can be performed on the object
- domain implenation: user-id, domain switch accomplaied via file system. each file has associated domain bit. set user id during execution, reset when done
- domain switch accomplied via sudo
- multics: two domain rings with n - 1rings: mutlics benefits: ring hieriracl structure provided more than basic kernel, fairly complex more overhead
  - object accebile in D, not d i then j < i
  -every element in Di is accessible in Dj
- access matrix: view protection as a matrix. rows represent domains, columns represent objects. access(i, j)
-access matrix separates mechanism from policy. 
  - mehcnaism: ensures matrix is only manipulated by authorized agents and that rules are stirclty enforced. user dictteas policy. doens-t solve general confinement problem
-copy rights vs owner rights
- store ordered triple in table. but won;t fit in main memory
- instead use acces list for objects. each column impleneted as an access lsit for object. resulting lists is <domain, rights-set>
- each column thus is the access control list for one object,  and defines who can perform what object
- each row: capability, show what operatins are allowed
- third options: instead of object based, domain is list based. capcility list for domain is list of objects togher with operations allowed. object represents by addres aka capability
-process requests operation and specifcs capability as parameter
- capbility list associated with domain but never directly accessible by domain.
- lockkey: compormise between access lists and caiblity lists. each opbject has unique bit patterns, called locks. each domains has list of unique bit patterns called keys. process in domain can only access object if domain has key that matches one of the locks
-global table simple, capbility list useful for locating, lockkey effective and flexible
-usually access list and cababilityes: first access an object via access list then crate capability
-role based access control to implement least privilege: privlege is right to excute cole. user roles
- revocation of access rights
- delete access list with acces rights
-remove capbility list: reacquistion, 

- theft of service: unautorized use of reosuces
- denial of service: prevention of legimiate use
- masquering (breach authentication)
- replacy attack, main in the middle
- session hijacking
- trojan horse:
  - code segement misuses env. explortsfor allowing probgram to be executed by other users
- trap door:
  - specific user identify
- logic bomb
- stackbuffer overflow
  - write past arguments on stack into return address of stack, when rotuine returns to call, returns to hacked address
- some systems open rather than secure by defualt to recduce attack surface.
- network threats: worms, swpan
- crpyotgraphy to constrain potential senders or desintactio via secrey keys
-encrtpion: constain set of possible receivers. k keys, m messages, c ciphertexts
- can only comput message if it posses k and ciphertext
- assymetric enctrion: public key and private key only known t indivudal user
- usually RSA block cipher (detect if number is prime or not)
- ke is public key, kd is private key. N is product of two large random numbers.  D(c) = c **K mod(n)
-syymetric based on transformactions, assymetric based on matehcmaitlca functions
- computer holding k can generate authenticators on messages.
- hash functions are basis of authentication. creates small fixed message digets. 
- must be colision resistant.
- symmetric encription used in message authencatin code algorthim
- digital signatued based on assmyricate keys. very usuael as anyone can verifiy authenticiy of message. 
- key distribution when syymetric someimtes done out of badn. assymetric kets stored on key ring
- digital certificates: proof of who owns public key. 
- example: ssl: at one layer of iso netowkr model at transport layer.
- limits only two computers to do it.
- server is veried with certificate assuing client talking to correct server with asymmetric cryptography used to establish a secure session key for bulk communication
- 