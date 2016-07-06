/*
Family Name: Niburski
Given Name: Oskar
Student Number: 212644944
CS Login: raksonib
*/

// for reference:
/*
Desired Output:
Average waiting time                 : 21.24 units
Average turnaround time              : 40860.00 units
Time all processes finished          : 68575
Average CPU utilization              : 77.0%
Number of context switches           : 0
PID(s) of last process(es) to finish : 28
*/

// DESCRIPTION: This code is meant to implement the first-come-first-serve quad-core CPU scheduling simulator (also known as four homoegenous CPUs).
// It does so and answers the average waiting time, average turnaround time, cpu time to finish processes, how many context switches, as well as which process is the alast to finish

// helper function provided
#include "sch-helpers.h"

// standard libraries dependenices
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//global variables
int numofProcesses = 0; // number of processes       
int nextProcessIndex = 0; // index of next process
int totalWaitingTimeOfProcesses = 0; //total waiting time for ALL processes    
int totalNumberOfContextSwitches = 0; //the number of context switches: NOTE: context switch is only for when a process is preempted during a CPU burst
int totalSimulationTime = 0; // total time simulated           
int totalCPUTime = 0; // total CPU time
int intermediaryQueueSize = 0; // this is the queue before the processes become active.
int i = 0; // global int i referenced in for loops.

process_queue activeQueue; // the process provided by helper with ready queue
process_queue queueWaiting; // process queue for qiaiting ques
process processes[MAX_PROCESSES+1]; // total number of processes                           
process *cpus[NUMBER_OF_PROCESSORS];  // all the cpus being used
process *intermidiaryArrayForProcesses[MAX_PROCESSES]; // intermiadte array to allow incoming processes to be sorted by priority

// functions used for comparison
// compares the processes that are pointed by aa and bb which are refered to via process id!
int comparePIDs(const void *aa, const void *bb) {
  
  process *a = *((process**) aa);
  process *b = *((process**) bb);
  // comparison of pointer processes
  if (a->pid < b->pid) {
    return -1;
  }
  if (a->pid > b->pid) {
    return 1;
  }

  return 0;
}

int main(void) {
  // local variables used in main
  int allSwitchTime = 0;
  int finishedReadProcess = 0;
  i = 0;
  int result = -1;

  // initliaze all cpus to null
  for (i = 0; i < NUMBER_OF_PROCESSORS; i++) {
    cpus[i] = NULL;
  }

  // initialize the queues via the helper functions
  initializeProcessQueue(&activeQueue);
  initializeProcessQueue(&queueWaiting);

  // read the data from the processes
  // furthermore, create the process array initialized above and fill the array with those results
  while (finishedReadProcess = readProcess(&processes[numofProcesses]))  {
    if (finishedReadProcess == 1)  {
      numofProcesses++;
    }

    if (numofProcesses > MAX_PROCESSES) {
      break;
    }
 }

  // error check for invalid input
  if (numofProcesses == 0) {
    fprintf(stderr, "No processes provided.\n");
    return result;
  }

  if (numofProcesses > MAX_PROCESSES) {
    fprintf(stderr, "Too many processes provided.");
    return result;
  }
  
  // sort procsses in ASCENDING order as they come in (first come, first serve)
  qsort(processes, numofProcesses, sizeof(process), compareByArrival);

  // infinite loop until break, which runs all the quad core simulations
  while (1) {
    // initialize some variables in local while scope
    int size = queueWaiting.size;
    int resultActive = 0;

    //move all the incoming processes into a tmp array to allow for some amount of order
    while (processes[nextProcessIndex].arrivalTime <= totalSimulationTime && nextProcessIndex < numofProcesses) { 
      intermidiaryArrayForProcesses[intermediaryQueueSize++] = &processes[nextProcessIndex++]; 
    }

    //move all the active processes that are finished their small CPU bust and transition them into waiting, and then terminate those that are actually finished
    for (i = 0; i < NUMBER_OF_PROCESSORS; i++) {
      // conditional check to see if cpu is null, and to determine if the current burst is actually null
      if (cpus[i] != NULL && cpus[i]->bursts[cpus[i]->currentBurst].length == cpus[i]->bursts[cpus[i]->currentBurst].step) {
        cpus[i]->currentBurst++; // start next CPU burst
        //if not finished, then enqueue it into waiting queue
        if (cpus[i]->currentBurst < cpus[i]->numberOfBursts) {
          enqueueProcess(&queueWaiting, cpus[i]);
        } else {
          // terminate it instead!
          cpus[i]->endTime = totalSimulationTime;
        }

        //this stops the execution of processes
        cpus[i] = NULL;
      }
    }  

    //this increases the waiting processes current bust and upgrades the progress of this burst
    for (i = 0; i < size; i++) {
      // get the first process (provided by struct in helper)
      process *front = queueWaiting.front->data;
      //dequeue it out of the waiting queue
      dequeueProcess(&queueWaiting);

      //increment the current active burst!
      if (front->bursts[front->currentBurst].length == front->bursts[front->currentBurst].step) {
        front->currentBurst++;
        // put in the intermediary array for the process
        intermidiaryArrayForProcesses[intermediaryQueueSize++] = front;
      } else {
        // or enqueue it into the waiting queue
        enqueueProcess(&queueWaiting, front);
      }
    } 

    // moves ready processes into proper queue
    qsort(intermidiaryArrayForProcesses, intermediaryQueueSize, sizeof(process*), comparePIDs);

    //all things in the intermiadairy queue become enqueued into the active queue
    for (i = 0; i < intermediaryQueueSize; i++) {
      enqueueProcess(&activeQueue, intermidiaryArrayForProcesses[i]);
    }

    // reset the intermiadairy queue
    intermediaryQueueSize = 0;

    for (i = 0; i <NUMBER_OF_PROCESSORS; i++) {
      if (cpus[i] == NULL) {
        process *result;
        if (activeQueue.size == 0) {
          result = NULL;
        } else {
          result = activeQueue.front->data;
          dequeueProcess(&activeQueue);
        }

        cpus[i] = result;
      }
    }

    size = queueWaiting.size;
    // this was a bug above, need to reinlitize the size!
    // update all the waiting processes, and increment the processes currenlty active
    for (i = 0; i < size ; i++) {
      // deqeue all waiting processes
      process *front = queueWaiting.front->data;
      dequeueProcess(&queueWaiting);            

      //enqeueu all waiting processes
      front->bursts[front->currentBurst].step++;
      enqueueProcess(&queueWaiting, front);      
    }

    // all active and current processes are deqeueued and updated as long as in active queue
    for (i = 0; i < activeQueue.size; i++) {
      // dequeue front process
      process *front = activeQueue.front->data; 
      dequeueProcess(&activeQueue);    
      // incease qaiting time and inqeueu it again for reuse
      front->waitingTime++;                   
      enqueueProcess(&activeQueue, front);     
    }

    //this updates the progress of every single active cpu process in the cpus array
    for (i = 0; i < NUMBER_OF_PROCESSORS; i++) {
      if (cpus[i] != NULL) {
        cpus[i]->bursts[cpus[i]->currentBurst].step++;
      }
    }

    // local variables
    resultActive = 0;
    i = 0;
    // returns number of processes currently active and running some cpu function
    for (i = 0; i < NUMBER_OF_PROCESSORS; i++) {
      if (cpus[i] != NULL) {
        resultActive++;
      }
    }

    // add this number to total cpu time
    totalCPUTime += resultActive;

    // break out of while loop condition. 
    // If the resultActive is zero and the next index is zero and there is nothing waiting anymore, exit
    if (resultActive == 0 && (numofProcesses - nextProcessIndex) == 0 && queueWaiting.size == 0)  {
      break;
    }

    // increase the total simulation time
    totalSimulationTime++;
  }

  // calculate the total context switch time as well as the total waiting time for all processes
  for (i = 0; i < numofProcesses; i++) {
    allSwitchTime += (processes[i].endTime - processes[i].arrivalTime);
    totalWaitingTimeOfProcesses += processes[i].waitingTime;
  }

  // set up variables for final output
  float avgTime = totalWaitingTimeOfProcesses / (double) numofProcesses;
  float avgTurn = allSwitchTime / (double) numofProcesses;
  float avgCPU =  (100.0 * totalCPUTime / totalSimulationTime);

  // final output printfs
  printf("Average waiting time is %.2f units\n", avgTime);
  printf("Average turnaround time is %.2f units\n", avgTurn);
  printf("Time all processes finished is %d\n", totalSimulationTime);
  printf("Average CPU utilization is %.1f%%\n", avgCPU);
  printf("Number of context switches are %d\n", totalNumberOfContextSwitches);
  printf("PID(s) of the last process(es) to finish:");
  
  // find the potential multiple last processes
  for (i=0; i < numofProcesses; i++) {
    if (processes[i].endTime == totalSimulationTime) {
      printf(" %d", processes[i].pid);
    }
  }

  printf("\n");
  return 0;
}