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

//Create Global Variables
process processes[MAX_PROCESSES + 1];
process *CPU[NUMBER_OF_PROCESSORS];
process_queue readyQueue, waitQueue; 

int clockRepresented;                    
int clockRepresentedCPU;           
int numberOfProcesses = 0;    
int processNextCount = 0;  
int i;
int readInput = 0;
int waitTime = 0;
int turnAroundTimes = 0;
int contextSwitch = 0;
int quantumOne = 0;
int quantumTwo = 0;

// setup print variables
void setupPrintVariables() {
  int i = 0;

  //calculate and display values
  while (i < numberOfProcesses) {
    waitTime = waitTime + processes[i].waitingTime;
    turnAroundTimes = turnAroundTimes + processes[i].endTime - processes[i].arrivalTime;
    i++;
  }
}

//Move in code to the ready queue, waiting queue, CPU Processors
void moveIntoQueues(){
  // unqueue the processes into ready Queue
  for (i = 0; i < numberOfProcesses; i++){
    if (processes[i].arrivalTime == clockRepresented){
      processes[i].currentQueue = 1;
      enqueueProcess(&readyQueue, &processes[i]); 
    }
  }

  // get the front in queue and deqeueu teh wait queue
  for (i = 0; i < waitQueue.size; i++){
    process *queueFront = waitQueue.front->data;
    dequeueProcess(&waitQueue);
    // if the front of the queue is equal to the current burst, then you enqueue the front process into the ready queue
    // if not, then enqeueue it into the wait queue
    if (queueFront->bursts[queueFront->currentBurst].step >= queueFront->bursts[queueFront->currentBurst].length) {    
      queueFront->currentBurst++;
      enqueueProcess(&readyQueue, queueFront);
    }
    else {
      enqueueProcess(&waitQueue, queueFront);       
    }
  }

  //loop through number of processes
  int t;
  for (t = 0; t < NUMBER_OF_PROCESSORS; t++){    //Number of Processors = 4
    if (CPU[t] != NULL) {
      //Burst finished. Move process
      if (CPU[t]->bursts[CPU[t]->currentBurst].step == CPU[t]->bursts[CPU[t]->currentBurst].length) {
      
        CPU[t]->currentBurst++;
        
        if (CPU[t]->currentBurst >= CPU[t]->numberOfBursts) {

          CPU[t]->endTime = clockRepresented;
          processNextCount++;          
        }
        else {
          // if not finished yet, move to the wait queue
          enqueueProcess(&waitQueue, CPU[t]);
        }
        CPU[t] = NULL;
      // Check if quantum expired
      } else {
        if (CPU[t]->quantumRemaining <= 0){ 
          // increment queue count
          CPU[t]->currentQueue++;       
          enqueueProcess(&readyQueue, CPU[t]);
          CPU[t]=NULL;
          contextSwitch++;
        }
      }     
    }
    // add new process from front and then dequeue it
    if (CPU[t] == NULL && readyQueue.size > 0){
      CPU[t] = readyQueue.front->data;
      if (CPU[t]->currentQueue == 1) {
        CPU[t]->quantumRemaining = quantumOne;
      }
      else {
        CPU[t]->quantumRemaining = quantumTwo;
      }
      dequeueProcess(&readyQueue);  
    }
  }
}

//update the queues
void updateQueues() {
  process * temp;
  int i;
  for (i= 0; i < readyQueue.size; i++) {
    // take the readyQueue and dequeue it for each process in ready queue
    temp = readyQueue.front->data;
    temp->waitingTime++;
    dequeueProcess(&readyQueue);
    enqueueProcess(&readyQueue,temp);
  }

  temp = NULL;
  int t;
  for (t = 0; t < waitQueue.size; t++) {
    // take the waitQueue and dequeue it for each process in wait queue
    temp = waitQueue.front->data;
    dequeueProcess(&waitQueue);
    temp->bursts[temp->currentBurst].step++;
    enqueueProcess(&waitQueue, temp);
  }
  // update each process in cpu
  for (t=0; t<NUMBER_OF_PROCESSORS; t++) {
    if (CPU[t]!=NULL){
      CPU[t]->bursts[CPU[t]->currentBurst].step++;
      clockRepresentedCPU++;     
      CPU[t]->quantumRemaining--;     
    }   
  }
}

// simple to setup into null array on initalization
void setupProcesses() {
  //clear all cpus
  for (i=0;i<NUMBER_OF_PROCESSORS;i++) {
    CPU[i] = NULL;
  }

  //read in processes, calculate number of processes to be sorted
  while (readInput = readProcess(&processes[numberOfProcesses])) {
    if (readInput == 1) {  
      numberOfProcesses++;
    }
  }
}

// simple check errors method
int checkErrors(int quantum, int quantumTwo) {
  if (numberOfProcesses == 0 || numberOfProcesses > MAX_PROCESSES ) {
    return -1;
  }

  if (quantum < 1 || quantum > 2147483647) {
    return -2;
  }

  if (quantumTwo != NULL && (quantumTwo < 1 || quantumTwo > 2147483647 )) {
    return -2;
  }

  return 0;
}

//main code
int main(int argc, char *argv[]){
  
  //initialize
  initializeProcessQueue(&readyQueue);
  initializeProcessQueue(&waitQueue);
  setupProcesses();

  int errors;
  
  // argument error check
  if (argc == 2) {
    quantumOne = atoi(argv[1]);
    errors = checkErrors(quantumOne, NULL);
  }

  if (argc == 3) {
    quantumOne = atoi(argv[1]);
    quantumTwo = atoi(argv[2]);
    errors = checkErrors(quantumOne, quantumTwo);
  }

  if (errors == -1) {
    error("Invalid number of processes");
    return -1;
  } else if (errors == -2) {
    error_bad_quantum();
    return -1;
  }
  
  //qsort processes
  qsort(processes, numberOfProcesses, sizeof(process), compareByArrival);

  //loop through processes
  for (clockRepresented = 0; processNextCount < numberOfProcesses; clockRepresented++){
    moveIntoQueues();
    updateQueues();
  }

  setupPrintVariables();
  // print
  printf("Average waiting time                 : %.2f units\n", ((double)waitTime/numberOfProcesses));
  printf("Average turnaround time              : %.2f units\n", (turnAroundTimes / (double)numberOfProcesses));
  printf("Time all processes finished          : %d\n", clockRepresented - 1);
  printf("Average CPU utilization              : %.1f  %% \n", ((100 * clockRepresentedCPU)/(double)( clockRepresented-1)));
  printf("Number of context switches           : %d\n", contextSwitch);
  printf("PID(s) of last process(es) to finish : ");
  for (i = 0; i<numberOfProcesses; i++) {
    if (processes[i].endTime == (clockRepresented-1)) {
      printf("%d ", processes[i].pid);
    }
  } 
  printf("\n");
  
  return 0;    
}