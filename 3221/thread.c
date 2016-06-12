/*
Family Name: Niburski
Given Name: Oskar
Student Number: 212644944
CS Login: raksonib
*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <math.h>

float totalMax = -INFINITY;
float totalMin = INFINITY;

void *runner(void *param);
// data shared on threads
// aiming for
// Filename: dataset2, sum: 100.984116, diff: -98.389618, max: 99.686867, min: 1.297250
// Filename: dataset1, sum: 99.500092, diff: -99.390106, max: 99.445099, min: 0.054990
// Filename: dataset3, sum: 99.915817, diff: -99.870956, max: 99.893387, min: 0.022430
// MINIMUM=0.022430  MAXIUMUM=99.893387

int main(int argc, char *argv[]) {
  // for each data set, make a child thread
  // reads data set file names
  // each child process reads from its own file
  // calculates sum of large small, differenfce between large small, and min and max
  //  then sends to main process via a pipe to standard output the filename followed by received sum and dif values
  // may strucutre as waiting for all child process to finish then processing their data, or waiting for any child to finish and process its data.

  pthread_t tid;
  pthread_attr_t attr;


  int i = 0;
  // get the default attributes
  pthread_attr_init(&attr);
  
  for (i = 1; i < argc; ++i) {
    // create thread
    pthread_create(&tid, &attr, runner, argv[i]);
    pthread_join(tid, NULL); 
  }

  // wait for thead to close

  printf("MINIMUM=%f\tMAXIMUM=%f\n", totalMin, totalMax);
  
  return 0;
}

void *runner(void *param) {
  char * arr[200];
  char * pch = "";
  char str[5000];
  FILE * fp;
  int count = 0;
  float max = -INFINITY;
  float min = INFINITY;
  float diff = 0;
  // float sum;
  float current = 0;
  char buffer[1024];
  char * readFile = "";
  int val = 0, len, i;
  int internalCount = 1;
  int fd[2*count];
  float sum = 0;
  // create local vars

  readFile = param;
  fp = fopen(readFile, "r");
  if (fp == NULL) 
  {
    perror("Error opening file");
    exit(-1);
  }

// read from file
  while ((fscanf (fp, "%s", str)) != EOF) {
          
    /* Reads arguments from file
     */
     double temp = atof(str);
     
     if (temp < min)
       min = temp; 
     
     if (temp > max)
       max = temp; 
       
    /*Reset array str.*/
    memset(str, '\0', 101);
  }

  diff = min - max;
  sum = min + max;

  if (max > totalMax) {

    totalMax = max;

  }

  if (min < totalMin) {

    totalMin = min;

  }

  fclose(fp);            
  snprintf(buffer, sizeof(buffer), "Filename: %s, sum: %f, diff: %f, max: %f, min: %f", readFile, sum, diff, max, min);
  printf("%s\n", buffer);
  pthread_exit(0);

}
