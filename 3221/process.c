#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
  // for each data set, make a child process
  // reads data set file names
  // each child process reads from its own file
  // calculates sum of large small, differenfce between large small, and min and max
  //  then sends to main process via a pipe to standard output the filename followed by received sum and dif values
  // may strucutre as waiting for all child process to finish then processing their data, or waiting for any child to finish and process its data.

  pid_t pid;

  char * arr[200];

  char * pch;

  char str[5000];

  FILE * fp;
  int count = 0;
  float max = 0;
  float min = 0;
  float diff;
  float sum;
  float current;

  char buffer[1024];

  char * readFile;

  for (int i = 0; i < argc; ++i) {
    printf("argv[%d]: %s\n", i, argv[i]);
  }

  count = argc - 1;
  int internalCount = 1;

  printf("Count is %d\n", count);

  for (int i = 0; i < count; i++) {
    printf("*****NEW CHILD PROCESS *******\n");
    pid = fork();
  }

  // fork child process

  if (pid < 0) {
    // error occured
    perror("fork() error");
    exit(-1);
  } else if (pid == 0) {
    // child processs
    printf("\n Hello I am the child process ");
    printf("\n My pid is %d \n",getpid());
    readFile = argv[internalCount];
    internalCount++;
    printf("I am going to read %s\n", readFile);
    fp = fopen(readFile, "r");
     if(fp == NULL) 
     {
        perror("Error opening file");
        return(-1);
     }
     if( fgets (str, sizeof(str), fp)!=NULL ) 
     {
        pch = strtok (str," ,.-");
        while (pch != NULL)
        {
          // printf ("%s\n",pch);
          current = atof(pch);
          if (current > max) {
            max = current;
          }

          if (current < min) {
            min = current;
          }
          pch = strtok (NULL, " ,.-");
        }

        diff = min - max;
        sum = min + max;

     }
      fclose(fp);
      printf("*****END CHILD PROCESS *******\n");
      snprintf(buffer, sizeof(buffer), "Filename: %s, sum: %f, diff: %f, max: %f, min: %f\n", readFile, diff, sum, max, min);
      // printf("Filename: %s, sum: %f, diff: %f, max: %f, min: %f\n", readFile, diff, sum, max, min);
      execl("/bin/echo", "echo", buffer, NULL);
    // execlp("/bin/ls", "ls", NULL);
  } else {
    // parent will wait for child to complete
    wait(NULL);
    printf("YOOWHOOO Child complete\n");
    printf("\n Hello I am the parent process ");
    printf("\n My actual pid is %d \n ",getpid());
    printf("Total stuff here \n");
  }

  return 0;
}
