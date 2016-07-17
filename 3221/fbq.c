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
process_queue readyQue, waitQue; 

int clockRepresented;                    
int clockRepresentedCPU;           
int numberOfProcesses = 0;    
int ProcessNextComCount = 0;  
int i;
int ReadIn = 0;
int waitTime = 0;
int turnAroundTimes = 0;
int countextSwitch = 0;
int quantumnumber = 0;
int quantumtwo = 0;

//Move in code to the ready queue, waiting queue, CPU Processors
void Move(){

  for (i = 0; i < numberOfProcesses; i++){
    if (processes[i].arrivalTime == clockRepresented){
      processes[i].currentQueue = 1;
      enqueueProcess(&readyQue, &processes[i]); 
    }
  }

  for (i = 0; i < waitQue.size; i++){
    process *quefront = waitQue.front->data;
    dequeueProcess(&waitQue);

    if (quefront->bursts[quefront->currentBurst].step >= quefront->bursts[quefront->currentBurst].length){    
      quefront->currentBurst++;
      enqueueProcess(&readyQue, quefront);
    }
    else {
      enqueueProcess(&waitQue, quefront); 
      //printf("\r ioburst - waiting size: %d.....", waitQue.size);
    }
  }

  int t;
  for (t = 0; t < NUMBER_OF_PROCESSORS; t++){    //Number of Processors = 4
    if (CPU[t] != NULL) {
      //Burst finished. Move process
      if (CPU[t]->bursts[CPU[t]->currentBurst].step == CPU[t]->bursts[CPU[t]->currentBurst].length) {
      
        CPU[t]->currentBurst++;
        
        if (CPU[t]->currentBurst >= CPU[t]->numberOfBursts) {

          CPU[t]->endTime = clockRepresented;
          ProcessNextComCount++;
          // printf("%d Processes finished.\n", ProcessNextComCount);                  
        }
        else {
          enqueueProcess(&waitQue, CPU[t]);
        }
        CPU[t] = NULL;
      // Check if quantum expired
      } else {
        if (CPU[t]->quantumRemaining <= 0){ 
          // increment queue count (FBQ)
          CPU[t]->currentQueue++;       
          enqueueProcess(&readyQue, CPU[t]);
          CPU[t]=NULL;
          countextSwitch++;
        }
      }     
    }
    // add new process
    if (CPU[t] == NULL && readyQue.size > 0){
      CPU[t] = readyQue.front->data;
      if (CPU[t]->currentQueue == 1)
        CPU[t]->quantumRemaining = quantumnumber;
      else 
        CPU[t]->quantumRemaining = quantumtwo;
      dequeueProcess(&readyQue);  
    }
  }
}

//update the queues
void Update(){
  process * temp;
  int i;
  for (i= 0; i < readyQue.size; i++){
    temp = readyQue.front->data;
    temp->waitingTime++;
    dequeueProcess(&readyQue);
    enqueueProcess(&readyQue,temp);
  }
  temp = NULL;
  int t;
  for (t = 0; t < waitQue.size; t++)
  {
    temp = waitQue.front->data;
    dequeueProcess(&waitQue);
    temp->bursts[temp->currentBurst].step++;
    enqueueProcess(&waitQue, temp);
  }
  for (t=0; t<NUMBER_OF_PROCESSORS; t++){
    if (CPU[t]!=NULL){
      CPU[t]->bursts[CPU[t]->currentBurst].step++;
      clockRepresentedCPU++;     
      CPU[t]->quantumRemaining--;     
    }   
  }
}


//main code
int main(int argc, char *argv[]){
  
  //initialize
  initializeProcessQueue(&readyQue);
  initializeProcessQueue(&waitQue);
  
  if (argc == 2)
    quantumnumber = atoi(argv[1]);

  if (argc == 3){
    quantumnumber = atoi(argv[1]);
    quantumtwo = atoi(argv[2]);
  }

  //clear all cpus
  for (i=0;i<NUMBER_OF_PROCESSORS;i++) {
    CPU[i] = NULL;
  }

  //read in processes, calculate number of processes to be sorted
  while (ReadIn = readProcess(&processes[numberOfProcesses])) {
    if (ReadIn == 1) numberOfProcesses++;
  }
  
  //qsort processes
  qsort(processes, numberOfProcesses, sizeof(process), compareByArrival);

  //loop through processes
  for (clockRepresented = 0; ProcessNextComCount <numberOfProcesses; clockRepresented++){
    Move();
    Update();
  }

  i = 0;

  //calculate and display values
  while (i < numberOfProcesses){
    waitTime = waitTime + processes[i].waitingTime;
    turnAroundTimes = turnAroundTimes + processes[i].endTime - processes[i].arrivalTime;
    i++;
  }
  
  printf("Average waiting time                 : %.2f units\n", ((double)waitTime/numberOfProcesses));
  printf("Average turnaround time              : %.2f units\n", (turnAroundTimes / (double)numberOfProcesses));
  printf("Time all processes finished          : %d\n", clockRepresented - 1);
  printf("Average CPU utilization              : %.1f  %% \n", ((100 * clockRepresentedCPU)/(double)( clockRepresented-1)));
  printf("Number of context switches           : %d\n", countextSwitch);
  printf("PID(s) of last process(es) to finish : ");
  for (i = 0; i<numberOfProcesses; i++) {
    if (processes[i].endTime == (clockRepresented-1)) {
      printf("%d ", processes[i].pid);
    }
  } 
  printf("\n");
  
  return 0;    
}