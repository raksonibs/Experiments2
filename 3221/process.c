#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>

static float * totalMax = 0;
static float * totalMin;

int main(int argc, char **argv) {
  // for each data set, make a child process
  // reads data set file names
  // each child process reads from its own file
  // calculates sum of large small, differenfce between large small, and min and max
  //  then sends to main process via a pipe to standard output the filename followed by received sum and dif values
  // may strucutre as waiting for all child process to finish then processing their data, or waiting for any child to finish and process its data.

  // pid_t pid;
  // mmap is also useful for inter process communication. You can mmap a file as read / write in the processes that need to communicate and then use sychronization primitives in the mmap'd 
  totalMax = mmap(NULL, sizeof *totalMax, PROT_READ | PROT_WRITE, 
    MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  totalMin = mmap(NULL, sizeof *totalMin, PROT_READ | PROT_WRITE, 
    MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  * totalMin = 1000000;
  char * arr[200];
  char * pch;
  char str[5000];
  FILE * fp;
  int count = 0;
  float max = 0;
  float min = 100000;
  float diff;
  float sum;
  float current;
  char buffer[1024];
  char * readFile;
  int val = 0, len, i;

  count = argc - 1;
  int internalCount = 1;

  int fd[2*count];
  pipe(fd); 
  int pid;

  for (int i = 1; i < argc; ++i) {
    pid = fork();
    if (pid == 0) {
      // child process
      close(fd[1]);
      int ret = dup2(fd[0],0);
      if (ret < 0) perror("dup2");

      readFile = argv[i];

      val *= 2;

      fp = fopen(readFile, "r");
      if (fp == NULL) 
      {
        perror("Error opening file");
        return(-1);
      }
      if( fgets (str, sizeof(str), fp)!=NULL ) 
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

      if (max > *totalMax) {

        *totalMax = max;

      }
      if (min < *totalMin) {

        *totalMin = min;

      }

      fclose(fp);            
      snprintf(buffer, sizeof(buffer), "Filename: %s, sum: %f, diff: %f, max: %f, min: %f", readFile, sum, diff, max, min);            

      execl("/bin/echo", "echo", buffer, NULL);      
      
    } 
  }
  
  int status;
  waitpid(pid, &status, 0);
  printf("MINIMUM=%f\tMAXIUMUM=%f", *totalMin, *totalMax);
  munmap(totalMax, sizeof *totalMax);
  munmap(totalMin, sizeof *totalMin);  
  return 0;
}
