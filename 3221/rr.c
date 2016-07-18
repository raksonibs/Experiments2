/*
Family Name: Niburski
Given Name: Oskar
Student Number: 212644944
CS Login: raksonib
*/

// import standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "sch-helpers.h"     /* include a header file for function defintions and others */


// set up global variables used throughout functions
process processes[MAX_PROCESSES + 1];   // a large structure array to hold all processes read from data file 
int numberOfProcesses = 0;              // total number of processes 
int totalProcesses = 0;
int totalWaitingTime = 0;
int totalTurnAroundTime = 0;
int timer = 0;
int lastPID = 0;
int cpuUse = 0;
int cpuUseTotal = 0;
int context = 0; //no context switches in FCFS
int preReadyQueueSize = 0;
int quantum;
int tempProcessSize = 0;
process *preReadyQueue[MAX_PROCESSES];
process *tempProcess[MAX_PROCESSES];
process *cpus[NUMBER_OF_PROCESSORS];
process_queue readyQueue;
process_queue waitingQueue;
int nextProcess = 0;

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

//sets up varaibles used in the final print format
void setUpPrintVariables() {
  int b;
  int maxEndTime = 0;
  for (b = 0; b < numberOfProcesses; b++) {
  // calculate necessary ptin variables
    totalTurnAroundTime = totalTurnAroundTime + (processes[b].endTime - processes[b].arrivalTime);
    totalWaitingTime = totalWaitingTime + processes[b].waitingTime;    
    if (processes[b].endTime > maxEndTime) {
      lastPID = processes[b].pid;
    }
  } 
}

// this creates all processes in cpu array initially to none
void setupCPUS() {
  int d;
  for(d = 0; d < NUMBER_OF_PROCESSORS; d++){
    cpus[d] = NULL;  
  }
}

//check error method for arguments.
int checkErrors(int quantum) {
  if (numberOfProcesses == 0 || numberOfProcesses > MAX_PROCESSES ) {
    return -1;
  }

  if (quantum < 1 || quantum > 2147483647) {
    return -2;
  }

  return 0;
}

// does the heavy work.
// initially checks if puIndex is equal to the bursts currently occuring, and if so, switches to an I/o bust
// the cpu is then enqued into the waiting queure
// if there are bursts beyond the time for the process, the  cpu is sent back into the waiting queue
// otherwise it is nulled.
void cpuBurstAllocation(int cpuIndex, int cpuUse) {
  while (cpuIndex < NUMBER_OF_PROCESSORS) {
    if (cpus[cpuIndex] != NULL) { 
      // check if cpu occupied with process
      if (cpus[cpuIndex]->bursts[cpus[cpuIndex]->currentBurst].length == cpus[cpuIndex]->bursts[cpus[cpuIndex]->currentBurst].step) {
        cpus[cpuIndex]->currentBurst++; // switch to I/O burst
        if (cpus[cpuIndex]->currentBurst < cpus[cpuIndex]->numberOfBursts) {
          enqueueProcess(&waitingQueue, cpus[cpuIndex]);
          } else { 
          // add to waiting queue bursts remaining or otherwise terminate from cpu 
            cpus[cpuIndex]->endTime = timer;
          }
          cpus[cpuIndex] = NULL; 
        } else {
          // this takes and looks for remaining processes. basically if not actuallly occupied by current process, it will store it  wither in temporary array or remove time for each cpu step.
          if (cpus[cpuIndex]->quantumRemaining == 0) {
            // store processes with expired time slices in temporary array for now which will be referenced in waiting queue check
            tempProcess[tempProcessSize] = cpus[cpuIndex];
            tempProcessSize++;
            cpus[cpuIndex] = NULL;
            context++;
          } else {
            cpus[cpuIndex]->bursts[cpus[cpuIndex]->currentBurst].step++;
            cpus[cpuIndex]->quantumRemaining--; //decrease remaining time slice
            cpuUse++;
            cpuUseTotal++;
          }
        }
        
      }
      cpuIndex++;

    }
}

// goes through everything in the ready queue and sets up the actual quantum time allocated to process
// this then dequeues out the ready queue and bursts the current burst of the step
void conditionalCPUProcessQueue(int cpuIndex, int preReadyQueueSize, int tempProcessSize) {
  if (cpus[cpuIndex] == NULL) {
    if (readyQueue.size == 0) {
      cpus[cpuIndex] = NULL;
    } else { 
      //set quantum time, subtract one for current step
      if (readyQueue.front->data->startTime == 0) {
        readyQueue.front->data->startTime = timer;
      }
      readyQueue.front->data->quantumRemaining = quantum - 1;
      cpus[cpuIndex] = readyQueue.front->data;
      dequeueProcess(&readyQueue);
      cpus[cpuIndex]->bursts[cpus[cpuIndex]->currentBurst].step++;

      cpuUse++;
      cpuUseTotal++;
    }

  }
}

// simple method to setup the intial number of processes
void setUpProcesses() {
  int status;
  while ((status=readProcess(&processes[numberOfProcesses])) && numberOfProcesses <= MAX_PROCESSES)  {
    if( status==1 ) {
      numberOfProcesses++;
    } 
  } 
}

// updates the queue to coincide with FIFO structure of RR
// if it is at front of the queue, dequeue that, and then enqueue the next process at the front
void updateQueues() {
  //check front of queue
  process *front = readyQueue.front->data; 
  dequeueProcess(&readyQueue);
  front->waitingTime++; 
  // increment waiting time of each process in waiting queue
  enqueueProcess(&readyQueue, front);
}

//make in the preready queue
void preparePreQueue() {
  //queue processes in preready queue based on arrival time
  while (nextProcess < numberOfProcesses && processes[nextProcess].arrivalTime <= timer) {
    preReadyQueue[preReadyQueueSize++] = &processes[nextProcess++];    
  }
}

// go through the qwaiting queue and deqeue that front FIFO burst
// complete it's value
// and then enqueue it eitehr back into the qaiting queue if it is not finished, or into the preReadyQueue to be placed in the ready queue
void dequeueEnqueueWaitingBusts(int waitingIndex, int waitingQueueSize) {
   //check the front of queue 
  process *front = waitingQueue.front->data;  

  if (front->bursts[front->currentBurst].length == front->bursts[front->currentBurst].step) {
    // switch to cpu burst that is current at front
    front->currentBurst++;
    dequeueProcess(&waitingQueue);
    preReadyQueue[preReadyQueueSize++] = front;
  } else {
    //I/O burst not finished
    front->bursts[front->currentBurst].step++;
    dequeueProcess(&waitingQueue);
    enqueueProcess(&waitingQueue, front);
  }
}

int main(int argc, char *argv[]) {
  int waitingIndex;
  setUpProcesses();

  totalProcesses = numberOfProcesses;

  //error management of invalid number of processes
  quantum = readInt(&argv[1]);
  if (checkErrors(quantum) == -1) {
    error("Invalid number of processes");
    return -1;
  } 

  //sort processes by arrival time and priority
  qsort(processes, numberOfProcesses, sizeof(process), compareByArrival);

  initializeProcessQueue(&readyQueue);
  initializeProcessQueue(&waitingQueue);

  setupCPUS();

  //set the quantum slice
  if (checkErrors(quantum) == -2) {
    error_bad_quantum();
    return -1;
  }

  while (1) {
    preparePreQueue();

    // if finished cpu burst, move to waiting queue if it is not the last cpu burst
    int cpuIndex = 0;
    int cpuUse = 0;

    // set up the current CpuBursts
    cpuBurstAllocation(cpuIndex, cpuUse);

    //sort waiting queue by processes priority
    int waitingQueueSize = waitingQueue.size;
    
    // iterate over queue where there are no indexes, and are waiting
    for (waitingIndex = 0; waitingIndex < waitingQueueSize; waitingIndex++) {
      dequeueEnqueueWaitingBusts(waitingIndex, waitingQueueSize);
    }

    //sort preReadyQueue and queue the expired time slices to the ready queue
    qsort(preReadyQueue, preReadyQueueSize, sizeof(process*), comparePIDs);
    qsort(tempProcess, tempProcessSize, sizeof(process*), comparePIDs);
    int j;

    //previous processes with expired time slices go into ready queue first as is in fifo
    for (j = 0; j < tempProcessSize; j++) {
      enqueueProcess(&readyQueue, tempProcess[j]);
    }

    tempProcessSize = 0;

    //enqueue everything in the ready queue
    for (j = 0; j < preReadyQueueSize; j++) {
      enqueueProcess(&readyQueue, preReadyQueue[j]);
    }

    preReadyQueueSize = 0;

    //assign the available cpu to first process of ready queue
    for (cpuIndex = 0; cpuIndex < NUMBER_OF_PROCESSORS; cpuIndex++) {
      conditionalCPUProcessQueue(cpuIndex, preReadyQueueSize, tempProcessSize);
    }

    //update burst of all processes in every queue
    int r;
    for (r = 0; r < readyQueue.size; r++) {
      updateQueues();
    }


    if (cpuUse == 0 && waitingQueue.size == 0 && (numberOfProcesses - nextProcess) == 0) {
      break; // exit loop if no cpu in use or no running processes and none in waiting queue
    }

    timer++; //increment one time unit for each loop
  }

  setUpPrintVariables();
  //print values
  printf("Average waiting time                 : %.2f units\n", totalWaitingTime/(double)numberOfProcesses);
  printf("Average turnaround Time              : %.2f units\n", totalTurnAroundTime/(double)numberOfProcesses);
  printf("Time all processes finished          : %d\n", timer);
  printf("Average CPU utilization              : %.1f%%\n", 100.0 * cpuUseTotal / timer);
  printf("Number of context switches           : %d\n", context);
  printf("PID(s) of last process(es) to finish : %d\n", lastPID);
  
  return 0;
}