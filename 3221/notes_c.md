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