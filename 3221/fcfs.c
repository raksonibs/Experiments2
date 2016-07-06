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


// helper function
#include "sch-helpers.h"

// standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

//global variables
int numofProcesses;                
int nextProcess;                      
int totalWaitingTime;                 
int totalNumberOfContextSwitches;             
int totalSimulationTime;                   
int totalCPUTime;                  
int preQueueSize;

process_queue activeQueue;             
process_queue waitingQueue;           
process processes[MAX_PROCESSES+1];                                
process *cpus[NUMBER_OF_PROCESSORS];  
process *preactiveQueue[MAX_PROCESSES];

int comparePIDs(const void *aa, const void *bb) {
  // some magic stuff here with all these pointers.
  process *a = *((process**) aa);
  process *b = *((process**) bb);
  if (a->pid < b->pid) {
    return -1;
  }
  if (a->pid > b->pid) {
    return 1;
  }
  assert(0); 
  return 0;
}

int currentlyActiveAndRunningProcesses(void) {
  int result = 0;
  int i;
  for (i=0; i<NUMBER_OF_PROCESSORS; i++) {
    if (cpus[i] != NULL) {
      result++;
    }
  }

  return result;
}

process *nextScheduledProcess(void) {
  if (activeQueue.size == 0) {
    return NULL;
  }

  process *result = activeQueue.front->data;
  dequeueProcess(&activeQueue);
  return result;
}

int main(void) {
  int sumOfTurnaroundTimes = 0;
  int finishedReadProcess = 0;
  int i = 0;
  int result = -1;
  totalSimulationTime = 0; 
  totalCPUTime = 0;
  totalWaitingTime = 0;
  totalNumberOfContextSwitches = 0;
  numofProcesses = 0;
  nextProcess = 0;
  preQueueSize = 0;

  for (i = 0; i < NUMBER_OF_PROCESSORS; i++) {
    cpus[i] = NULL;
  }

  initializeProcessQueue(&activeQueue);
  initializeProcessQueue(&waitingQueue);

  while (finishedReadProcess = readProcess(&processes[numofProcesses]))  {
    if (finishedReadProcess == 1)  {
      numofProcesses ++;
    }

    if (numofProcesses > MAX_PROCESSES) {
      break;
    }
 }

  if (numofProcesses == 0) {
    fprintf(stderr, "Error Recorded: No processes provided.\n");
    return result;
  }

  if (numofProcesses > MAX_PROCESSES) {
    fprintf(stderr, "Error Recorded: Too many processes provided.");
    return result;
  }
  
  qsort(processes, numofProcesses, sizeof(process), compareByArrival);

  while (1) {
    // initialize some variables in local while scope
    int i;
    int size = waitingQueue.size;

    // moves incoming Processes!
    while (nextProcess < numofProcesses && processes[nextProcess].arrivalTime <= totalSimulationTime) { 
      preactiveQueue[preQueueSize++] = &processes[nextProcess++]; 
    }

    for (i = 0; i < NUMBER_OF_PROCESSORS; i++) {
      if (cpus[i] != NULL) {

        if (cpus[i]->bursts[cpus[i]->currentBurst].step == cpus[i]->bursts[cpus[i]->currentBurst].length) {
          cpus[i]->currentBurst++;

          if (cpus[i]->currentBurst < cpus[i]->numberOfBursts) {
            enqueueProcess(&waitingQueue, cpus[i]);
          } else {
            cpus[i]->endTime = totalSimulationTime;
          }

          cpus[i] = NULL;
        }
      }
    }  

    for (i = 0; i < size; i++) {
      process *front = waitingQueue.front->data; 
      dequeueProcess(&waitingQueue);             

      assert(front->bursts[front->currentBurst].step <= front->bursts[front->currentBurst].length);

      if (front->bursts[front->currentBurst].step == front->bursts[front->currentBurst].length) {
        front->currentBurst++;
        preactiveQueue[ preQueueSize++] = front;
      } else {
        enqueueProcess(&waitingQueue, front);
      }
    } 

    // moves ready processes into proper queue
    qsort(preactiveQueue,  preQueueSize, sizeof(process*), comparePIDs);

    for (i=0; i< preQueueSize; i++) {
      enqueueProcess(&activeQueue, preactiveQueue[i]);
    }

     preQueueSize = 0;

    for (i=0;i<NUMBER_OF_PROCESSORS;i++) {
      if (cpus[i] == NULL) {
        cpus[i] = nextScheduledProcess();
      }
    }

    size = waitingQueue.size;
    // this was a bug above, need to reinlitize the size!

    for (i=0;i<size;i++) {
      process *front = waitingQueue.front->data;
      dequeueProcess(&waitingQueue);            

      front->bursts[front->currentBurst].step++;
      enqueueProcess(&waitingQueue, front);      
    }

    for (i=0;i<activeQueue.size;i++) {
      process *front = activeQueue.front->data; 
      dequeueProcess(&activeQueue);    

      front->waitingTime++;                   
      enqueueProcess(&activeQueue, front);     
    }

    for (i=0; i < NUMBER_OF_PROCESSORS; i++) {
      if (cpus[i] != NULL) {
        cpus[i]->bursts[cpus[i]->currentBurst].step++;
      }
    }

    totalCPUTime += currentlyActiveAndRunningProcesses();

    if (currentlyActiveAndRunningProcesses() == 0 && (numofProcesses - nextProcess) == 0 && waitingQueue.size == 0)  {
      break;
    }

    totalSimulationTime++;
  }


  for (i = 0; i < numofProcesses; i++) {
    sumOfTurnaroundTimes += (processes[i].endTime - processes[i].arrivalTime);
    totalWaitingTime += processes[i].waitingTime;
  }

  float avgTime = totalWaitingTime / (double) numofProcesses;
  float avgTurn = sumOfTurnaroundTimes / (double) numofProcesses;
  float avgCPU =  (100.0 * totalCPUTime / totalSimulationTime);

  printf("Average waiting time: %.2f units\n", avgTime);
  printf("Average turnaround time: %.2f units\n", avgTurn);
  printf("Time all processes finished: %d\n", totalSimulationTime);
  printf("Average CPU utilization: %.1f%%\n", avgCPU);
  printf("Number of context switches: %d\n", totalNumberOfContextSwitches);
  printf("PID(s) of last process(es) to finish:");
  
  for (i=0; i < numofProcesses; i++) {
    if (processes[i].endTime == totalSimulationTime) {
      printf(" %d", processes[i].pid);
    }
  }

  printf("\n");
  return 0;
}