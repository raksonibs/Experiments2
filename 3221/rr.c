/*
Family Name: Niburski
Given Name: Oskar
Student Number: 212644944
CS Login: raksonib
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "sch-helpers.h"     /* include a header file for function defintions and others */

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

// comparator modified to order based on processor id
int compareByPID(const void *aa, const void *bb) {
  process *a = *((process**) aa);
  process *b = *((process**) bb);
  if (a->pid < b->pid) return -1;
  if (a->pid > b->pid) return 1;
  return 0;
}

void setupCPUS() {
  int d;
  for(d = 0; d < NUMBER_OF_PROCESSORS; d++){
    cpus[d] = NULL;  
  }
}

void preparePreQueue() {
//queue processes to be in preready queue based on arrival time and current timer
  while (nextProcess < numberOfProcesses && processes[nextProcess].arrivalTime <= timer) {
    preReadyQueue[preReadyQueueSize++] = &processes[nextProcess++];
    
  }
}

int main(int argc, char *argv[]) {

  int status;
  while ((status=readProcess(&processes[numberOfProcesses])) && numberOfProcesses <= MAX_PROCESSES)  {
   if(status==1)  numberOfProcesses ++;
}   // it reads pid, arrival_time, bursts to one element of the above struct array
totalProcesses = numberOfProcesses;
//error management of invalid number of processes
if (numberOfProcesses == 0 || numberOfProcesses > MAX_PROCESSES ) {
  error("Invalid number of processes");
  return -1;
}

//sort processes by arrival time
qsort(processes, numberOfProcesses, sizeof(process), compareByArrival);

initializeProcessQueue(&readyQueue);
initializeProcessQueue(&waitingQueue);

setupCPUS();
//initialise cpus to null

//set the quantum slice, convert to integer
quantum = readInt(&argv[1]);
if (quantum < 1 || quantum > 2147483647) {
  error_bad_quantum();
}
// int nextProcess = 0;

while (1) {
  preparePreQueue();

// if finished cpu burst, move to waiting queue if it's not last cpu burst
  int cpuIndex = 0;
  int cpuUse = 0;

  while (cpuIndex < NUMBER_OF_PROCESSORS) {
    if (cpus[cpuIndex] != NULL) { // check if cpu occupied with process
      if (cpus[cpuIndex]->bursts[cpus[cpuIndex]->currentBurst].length ==
        cpus[cpuIndex]->bursts[cpus[cpuIndex]->currentBurst].step) {
            cpus[cpuIndex]->currentBurst++; // switch to I/O burst
          if (cpus[cpuIndex]->currentBurst < cpus[cpuIndex]->numberOfBursts) {
            enqueueProcess(&waitingQueue, cpus[cpuIndex]);
            } else { // add to waiting queue bursts remaining, otherwise terminate from cpu 
              cpus[cpuIndex]->endTime = timer;
                //totalProcesses--;
            }
            cpus[cpuIndex] = NULL; 
          } else {
            if (cpus[cpuIndex]->quantumRemaining == 0) {
          // store processes with expired time slices in seperate temporary array
              tempProcess[tempProcessSize] = cpus[cpuIndex];
              tempProcessSize++;
              cpus[cpuIndex] = NULL;
              context++;
            } else {
              cpus[cpuIndex]->bursts[cpus[cpuIndex]->currentBurst].step++;
        cpus[cpuIndex]->quantumRemaining--; //decrease remaining time slice for each step
        cpuUse++;
        cpuUseTotal++;
      }
    }
    
  }
  cpuIndex++;

}

//sort waiting queue every cycle by processes priority (whoever finishes I/O burst first)
int waitingQueueSize = waitingQueue.size;
// iterate over queue, no index present
int waitingIndex;
for (waitingIndex = 0; waitingIndex < waitingQueueSize; waitingIndex++) {
    process *front = waitingQueue.front->data; //check front of queue
    

    if (front->bursts[front->currentBurst].length ==
      front->bursts[front->currentBurst].step) {
            front->currentBurst++; // switch to cpu burst
          dequeueProcess(&waitingQueue);
          preReadyQueue[preReadyQueueSize++] = front;
        } else {
          front->bursts[front->currentBurst].step++;
          dequeueProcess(&waitingQueue);
        enqueueProcess(&waitingQueue, front); //I/O burst not finished
      }
    }

//sort preReadyQueue and queue containing expired time slices to ready queue
    qsort(preReadyQueue, preReadyQueueSize, sizeof(process*), compareByPID);
    qsort(tempProcess, tempProcessSize, sizeof(process*), compareByPID);
    int j;
//previous processes with expired time slices go into ready queue first
    for (j = 0; j < tempProcessSize; j++) {
      enqueueProcess(&readyQueue, tempProcess[j]);
    }
    tempProcessSize = 0;

    for (j = 0; j < preReadyQueueSize; j++) {
      enqueueProcess(&readyQueue, preReadyQueue[j]);
    }
    preReadyQueueSize = 0;


//assign available cpu to first process of ready queue
    for (cpuIndex = 0; cpuIndex < NUMBER_OF_PROCESSORS; cpuIndex++) {
      if (cpus[cpuIndex] == NULL) {
        if (readyQueue.size == 0) {
          cpus[cpuIndex] = NULL;
        } else { //set quantum time, subtract one for current step
          if (readyQueue.front->data->startTime == 0) {
            readyQueue.front->data->startTime = timer;
          }
          readyQueue.front->data->quantumRemaining = quantum - 1;
          cpus[cpuIndex] = readyQueue.front->data;
          dequeueProcess(&readyQueue);
          cpus[cpuIndex]->bursts[cpus[cpuIndex]->currentBurst].step++;

          cpuUse++;
          cpuUseTotal++;
            //cpuUse++;
        }

      }
    }

//update burst progression of all processes waiting, ready, and running
    int r;
    for (r = 0; r < readyQueue.size; r++) {
      process *front = readyQueue.front->data; //check front of queue
      dequeueProcess(&readyQueue);
      front->waitingTime++; // increment waiting time of each process in waiting queue
      enqueueProcess(&readyQueue, front);
    }


    if (cpuUse == 0 && waitingQueue.size == 0 && (numberOfProcesses - nextProcess) == 0) {
      break; // exit loop if no cpu in use, no running processes, and none in waiting queue
    }

    timer++; //increment one time unit for each loop
  }

int b;
for (b = 0; b < numberOfProcesses; b++) {
// calculate turnaround, waiting time, and last finished process
  totalTurnAroundTime = totalTurnAroundTime + (processes[b].endTime - processes[b].arrivalTime);
  totalWaitingTime = totalWaitingTime + processes[b].waitingTime;
  if (processes[b].endTime == timer) {
    lastPID = processes[b].pid;
  }
} // print out results
printf("Average waiting time                 : %.2f units\n", totalWaitingTime/(double)numberOfProcesses);
printf("Average turnaround Time              : %.2f units\n", totalTurnAroundTime/(double)numberOfProcesses);
printf("Time all processes finished          : %d\n", timer);
printf("Average CPU utilization              : %.1f%%\n", 100.0 * cpuUseTotal / timer);
printf("Number of context switches           : %d\n", context);
printf("PID(s) of last process(es) to finish : %d\n", lastPID);
return 0;
}