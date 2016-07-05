/*
Family Name: Niburski
Given Name: Oskar
Student Number: 212644944
CS Login: raksonib
*/
  
//Helper Function
#include "sch-helpers.h"     

//Include Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Global Variables
process processArray[MAX_PROCESSES + 1];
process *tempReadyQueue[MAX_PROCESSES + 1];
process *cpu[NUMBER_OF_PROCESSORS]; //processes as defined
process_queue readyQueue, waitQueue; //queues

//initializec variables
int t;
int flag = 0;

int tempReadySize = 0;
int turnaroundTimes = 0;
int tWaitingTime = 0;
int clock = 0;
int cpuTime = 0;
int ContextSwitches = 0;
int nextProcess = 0;
int numberOfProcesses = 0;


/* compares processes pointed to by *aa and *bb by process id,
   returning -1 if aa < bb, 1 if aa > bb and 0 otherwise. */
int compareByPIDs(const void *aa, const void *bb) {
    process *a = *((process**) aa);
    process *b = *((process**) bb);
    if (a->pid < b->pid) return -1;
    if (a->pid > b->pid) return 1;
    assert(0); /* case should never happen, o/w ambiguity exists */
    return 0;
}

void movein() {
  
  for (t = 0; t < numberOfProcesses; t++){
    if (processArray[t].arrivalTime == clock){
      tempReadyQueue[tempReadySize] = &processArray[t];
      tempReadySize++;
      nextProcess = tempReadySize;
    }
  }

  for (t = 0; t < NUMBER_OF_PROCESSORS; t++){
      
    if (cpu[t] != NULL)
    {   
      if (cpu[t]->bursts[cpu[t]->currentBurst].step == cpu[t]->bursts[cpu[t]->currentBurst].length) {
        
        cpu[t]->currentBurst++;
        if (cpu[t]->currentBurst >= cpu[t]->numberOfBursts) {
          cpu[t]->endTime = clock;
        }

        else {
          enqueueProcess(&waitQueue, cpu[t]);
        }
        cpu[t] = NULL;
      }
    else
    {
    
    cpu[t]->bursts[cpu[t]->currentBurst].step++;
      printf("hello");  
  
    }
    
  } 
  
  }

  for (t = 0; t < waitQueue.size; t++)
  {
    if (waitQueue.front->data->bursts[waitQueue.front->data->currentBurst].length != waitQueue.front->data->bursts[waitQueue.front->data->currentBurst].step){
      waitQueue.front->data->bursts[waitQueue.front->data->currentBurst].step++;
      dequeueProcess(&waitQueue);
      enqueueProcess(&waitQueue, waitQueue.front->data);
    }
    else{
      waitQueue.front->data->currentBurst++;
      dequeueProcess(&waitQueue);
      tempReadyQueue[tempReadySize] = waitQueue.front->data;
      tempReadySize++;
    }
  }
  qsort(tempReadyQueue, tempReadySize, sizeof(process*), compareByPIDs);
  for (t = 0; t<tempReadySize; t++) {
    enqueueProcess(&readyQueue, tempReadyQueue[t]);
  }
  tempReadySize = 0;
  t = 0;
  while (t < NUMBER_OF_PROCESSORS)
  {
    if (cpu[t] == NULL) {
      if (readyQueue.size == 0)
      {
      cpu[t] = NULL;
      }
      cpu[t] = readyQueue.front->data;
      dequeueProcess(&readyQueue);
    }
    
  }

}

void updatemove(void) {
  for (t = 0; t < waitQueue.size; t++)
  {
  process *hold = waitQueue.front->data;
  dequeueProcess(&waitQueue); 
  hold->bursts[hold->currentBurst].step++;  
  enqueueProcess(&waitQueue, hold);
  }
  
  for (t = 0; t < readyQueue.size; t++)
  {
  process *hold = readyQueue.front->data;
  dequeueProcess(&readyQueue);
  hold->waitingTime++;
  enqueueProcess(&readyQueue, hold);
  }

  for (t=0;t<NUMBER_OF_PROCESSORS;t++)
  {
    if (cpu[t] != NULL){
    cpu[t]->bursts[cpu[t]->currentBurst].step++;
    } 
  }
}



int main(void) {
  //initialize process queues
  initializeProcessQueue(&readyQueue);
  initializeProcessQueue(&waitQueue);

  for (t = 0; t<NUMBER_OF_PROCESSORS; t++) {
    cpu[t] = NULL;
  }

  while (flag = readProcess(&processArray[numberOfProcesses])) {
    if (flag == 1) numberOfProcesses++;
  }

  qsort(processArray, numberOfProcesses, sizeof(process), compareByArrival);

  while ((numberOfProcesses - nextProcess) != 0){

    t = 0;
  
    clock++;

    movein();
    
    updatemove();
  
    if (waitQueue.size == 0) break;

    for (t=0;t<NUMBER_OF_PROCESSORS;t++) 
    {
      if (cpu[t] != NULL)
      {
      cpuTime++;
      }
    }

    while (t<numberOfProcesses) {
      tWaitingTime += processArray[t].waitingTime;
      turnaroundTimes += processArray[t].endTime - processArray[t].arrivalTime;
      t++;
    }
  }
    printf("--------------------------------------FCFS--------------------------------------\n");
    printf("Average waiting time                 : %.2f units\n", (tWaitingTime / (double)numberOfProcesses));
    printf("Average turnaround time              : %.2f units\n", (turnaroundTimes / (double)numberOfProcesses));
    printf("Time all processes finished          : %d\n", (clock));
    printf("Average CPU utilization              : %.1f%%\n", (100.0 * cpuTime / clock));
    printf("Number of context switches           : %d\n", ContextSwitches);
    printf("PID(s) of last process(es) to finish : ");
    for (t = 0; t<numberOfProcesses; t++) {
      if (processArray[t].endTime == clock) {
        printf("%d ", processArray[t].pid);
      }
    } printf("\n");
  }
