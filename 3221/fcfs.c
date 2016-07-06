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
process processes[MAX_PROCESSES+1];                                
int numofProcesses;                
int nextProcess;                      
process_queue activeQueue;             
process_queue waitingQueue;           
process *cpus[NUMBER_OF_PROCESSORS];  
int totalWaitingTime;                 
int totalNumberOfContextSwitches;             
int simulationTime;                   
int cpuTimeUtilized;                  
process *preactiveQueue[MAX_PROCESSES];
int preactiveQueueSize;

/* initailizes all globals */
void initializeGlobals(void) {
  int i = 0;
  for (i=0; i<NUMBER_OF_PROCESSORS; i++) {
    cpus[i] = NULL;
  }

  simulationTime = 0; 
  cpuTimeUtilized = 0;
  totalWaitingTime = 0;
  totalNumberOfContextSwitches = 0;
  numofProcesses = 0;
  nextProcess = 0;

  preactiveQueueSize = 0;

  initializeProcessQueue(&activeQueue);
  initializeProcessQueue(&waitingQueue);
}

int comparePIDs(const void *aa, const void *bb) {
  // some magic stuff here with all these pointers.
  process *a = *((process**) aa);
  process *b = *((process**) bb);
  if (a->pid < b->pid) return -1;
  if (a->pid > b->pid) return 1;
  assert(0); 
  return 0;
}

int CurrentlyActiveAndRunningProcesses(void) {
  int result = 0;
  int i;
  for (i=0; i<NUMBER_OF_PROCESSORS; i++) {
    if (cpus[i] != NULL) {
      result++;
    }
  }

  return result;
}

int incomingProcesses(void) {
  return numofProcesses - nextProcess;
}

process *nextScheduledProcess(void) {
  if (activeQueue.size == 0) {
    return NULL;
  }

  process *result = activeQueue.front->data;
  dequeueProcess(&activeQueue);
  return result;
}


void moveIncomingProcesses(void) {
  while (nextProcess < numofProcesses && processes[nextProcess].arrivalTime <= simulationTime) { preactiveQueue[preactiveQueueSize++] = &processes[nextProcess++]; }
}

void moveWaitingProcesses(void) {
  int i;
  int size = waitingQueue.size;

  for (i=0; i<size; i++) {
    process *front = waitingQueue.front->data; 
    dequeueProcess(&waitingQueue);             

    assert(front->bursts[front->currentBurst].step <= front->bursts[front->currentBurst].length);

    if (front->bursts[front->currentBurst].step == front->bursts[front->currentBurst].length) {

    front->currentBurst++;
    preactiveQueue[preactiveQueueSize++] = front;
    } else {
      enqueueProcess(&waitingQueue, front);
    }
  }
}

void moveReadyProcesses(void) {
  int i;

  qsort(preactiveQueue, preactiveQueueSize, sizeof(process*), comparePIDs);
  for (i=0; i<preactiveQueueSize; i++) {
    enqueueProcess(&activeQueue, preactiveQueue[i]);
  }

  preactiveQueueSize = 0;

  for (i=0;i<NUMBER_OF_PROCESSORS;i++) {
    if (cpus[i] == NULL) {
      cpus[i] = nextScheduledProcess();
    }
  }
}

void moveCurrentlyActiveAndRunningProcesses(void) {
  int i;
  for (i=0;i<NUMBER_OF_PROCESSORS;i++) {
    if (cpus[i] != NULL) {
          
      if (cpus[i]->bursts[cpus[i]->currentBurst].step ==
        cpus[i]->bursts[cpus[i]->currentBurst].length) {

               
        cpus[i]->currentBurst++;

               
      if (cpus[i]->currentBurst < cpus[i]->numberOfBursts) {
        enqueueProcess(&waitingQueue, cpus[i]);

               
      } else {
        cpus[i]->endTime = simulationTime;
      }
                    cpus[i] = NULL;
                  }
                }
              }
            }

            void updateWaitingProcesses(void) {
              int i;
              int size = waitingQueue.size;
              for (i=0;i<size;i++) {
        process *front = waitingQueue.front->data;
        dequeueProcess(&waitingQueue);            


                front->bursts[front->currentBurst].step++;
        enqueueProcess(&waitingQueue, front);      
              }
            }


            void updateReadyProcesses(void) {
              int i;
              for (i=0;i<activeQueue.size;i++) {
        process *front = activeQueue.front->data; 
        dequeueProcess(&activeQueue);            
        front->waitingTime++;                   
        enqueueProcess(&activeQueue, front);     
              }
            }


            void updateCurrentlyActiveAndRunningProcesses(void) {
              int i;
              for (i=0;i<NUMBER_OF_PROCESSORS;i++) {
                if (cpus[i] != NULL) {

                  cpus[i]->bursts[cpus[i]->currentBurst].step++;
                }
              }
            }

            int main(void) {
              int sumOfTurnaroundTimes = 0;
              int doneReading = 0;
              int i;


              initializeGlobals();
              while (doneReading=readProcess(&processes[numofProcesses]))  {
               if(doneReading==1)  numofProcesses ++;
               if(numofProcesses > MAX_PROCESSES) break;
             }

    
             if (numofProcesses == 0) {
              fprintf(stderr, "Error: no processes specified in input.\n");
              return -1;
            } else if (numofProcesses > MAX_PROCESSES) {
              fprintf(stderr, "Error: too many processes specified in input; "
                "they cannot number more than %d.\n", MAX_PROCESSES);
              return -1;
            }

    
            qsort(processes, numofProcesses, sizeof(process), compareByArrival);


            while (1) {
        moveIncomingProcesses();
        moveCurrentlyActiveAndRunningProcesses();   
        moveWaitingProcesses();   
        moveReadyProcesses();    

        updateWaitingProcesses(); 
        updateReadyProcesses();   
        updateCurrentlyActiveAndRunningProcesses(); 

              cpuTimeUtilized += CurrentlyActiveAndRunningProcesses();

      
            if (CurrentlyActiveAndRunningProcesses() == 0 &&
              incomingProcesses() == 0 &&
              waitingQueue.size == 0) break;

              simulationTime++;
          }


          for (i=0;i<numofProcesses;i++) {
            sumOfTurnaroundTimes += processes[i].endTime - processes[i].arrivalTime;
            totalWaitingTime += processes[i].waitingTime;
          }

          printf("Average waiting time                 : %.2f units\n"
           "Average turnaround time              : %.2f units\n"
           "Time all processes finished          : %d\n"
           "Average CPU utilization              : %.1f%%\n"
           "Number of context switches           : %d\n",
           totalWaitingTime / (double) numofProcesses,
           sumOfTurnaroundTimes / (double) numofProcesses,
           simulationTime,
           100.0 * cpuTimeUtilized / simulationTime,
           totalNumberOfContextSwitches);

          printf("PID(s) of last process(es) to finish :");
          for (i=0;i<numofProcesses;i++) {
            if (processes[i].endTime == simulationTime) {
              printf(" %d", processes[i].pid);
            }
          }
          printf("\n");
          return 0;
        }