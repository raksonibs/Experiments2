#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>

float totalMax = 0;
float totalMin = 100000;

void *runner(void *param);
// data shared on threads

int main(int argc, char *argv[]) {
  // for each data set, make a child thread
  // reads data set file names
  // each child process reads from its own file
  // calculates sum of large small, differenfce between large small, and min and max
  //  then sends to main process via a pipe to standard output the filename followed by received sum and dif values
  // may strucutre as waiting for all child process to finish then processing their data, or waiting for any child to finish and process its data.

  // pid_t pid;
  // mmap is also useful for inter process communication. You can mmap a file as read / write in the processes that need to communicate and then use sychronization primitives in the mmap'd 
  pthread_t tid;
  pthread_attr_t attr;

  // if (argc != 2) {
  //   fprintf(stderr,"usage: a.out <integer value>\n");
  //   return -1;
  // }

  // if (atoi(argv[1]) < 0) {
  //   fprintf(stderr,"%d must be >= 0\n", atoi(argv[1]));
  //   return -1;
  // }

  // get the default attributes
  pthread_attr_init(&attr);
  for (int i = 1; i < argc; ++i) {
    // create thread
    pthread_create(&tid, &attr, runner, argv[i]);

  }
  // wait for thread to exit
  pthread_join(tid, NULL);

  printf("TOTAL MAXIMUM = %f\t TOTAL MININMUM = %f\t", totalMax, totalMin);

  // define NUM_THREADS 10
  // pthread_t workers[NUM_THREADS]
  // for (int i = 0; i < NUM_THREADS; i++) { pthread_join(workers[i], NULL); }
  
  return 0;
}

void *runner(void *param) {
  char * arr[200];
  char * pch;
  char str[5000];
  FILE * fp;
  int count = 0;
  float max = 0;
  float min = 100000;
  float diff;
  // float sum;
  float current;
  char buffer[1024];
  char * readFile;
  int val = 0, len, i;
  int internalCount = 1;
  int fd[2*count];
  float sum;

  readFile = param;
  fp = fopen(readFile, "r");
  if (fp == NULL) 
  {
    perror("Error opening file");
    return(-1);
  }
  if( fgets (str, sizeof(str), fp) != NULL ) 
  {
    pch = strtok (str, " ");
    while (pch != NULL)
    {

      current = atof(pch);

      if (current > max) {
        max = current;
      }

      if (current < min) {
        min = current;
      } 

      pch = strtok (NULL, " ");
    }

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
