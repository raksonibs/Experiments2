#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

// static void createChild(int pid, const char *fileName) {
//   pid_t childPid = fork();
//   if (childPid < 0) {
//     fprintf(stderr, "%.5d: failed to fork (%d: %s)\n", (int)getpid(), errno, strerror(errno));
//      exit(1);
//   } else if (pid > 0) {
//     return;
//   } else {
//     exit(0);
//   }
// }

float totalMax = 0;
float totalMin = 100000;

int main(int argc, char **argv) {
  // for each data set, make a child process
  // reads data set file names
  // each child process reads from its own file
  // calculates sum of large small, differenfce between large small, and min and max
  //  then sends to main process via a pipe to standard output the filename followed by received sum and dif values
  // may strucutre as waiting for all child process to finish then processing their data, or waiting for any child to finish and process its data.

  // pid_t pid;
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
  // int fd[2];
  // pipe(fd);

  count = argc - 1;
  int internalCount = 1;

  // printf("Count is %d\n", count);

  // int fd[2];
  int fd[2*count];
  pipe(fd); 
  int pid;

  for (int i = 1; i < argc; ++i) {
    // printf("argv[%d]: %s\n", i, argv[i]);
    pid = fork();
    if (pid == 0) {
      // child process
      close(fd[1]);
      int ret = dup2(fd[0],0);
      // len = read(fd[0], &val, sizeof(val));
      // if (len < 0) {
      //     perror("Child: Failed to read data from pipe");
      //     exit(EXIT_FAILURE);
      // }
      // else if (len == 0)
      // {
      //     // not an error, but certainly unexpected
      //     fprintf(stderr, "Child: Read EOF from pipe");
      // }
      // else {
        if (ret < 0) perror("dup2");
        // printf("\n Hello I am the child process ");
        // printf("\n My pid is %d \n",getpid());
        readFile = argv[i];
        // printf("Child(%d): Received %d\n", pid, val);
        val *= 2;
        // printf("Child(%d): Sending %d back\n", pid, val);
        // if (write(fd[1], &val, sizeof(val)) < 0)
        // {
        //     perror("Child: Failed to write response value");
        //     exit(EXIT_FAILURE);
        // }
        
        // printf("I am going to read %s\n", readFile);
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
                // printf ("%s\n",pch);
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
              // printf("Changing total Max: %f\n to %f\n", max, totalMax);
          totalMax = max;
              // printf("Changed total Max: %f\n\n", totalMax);
        }
        if (min < totalMin) {
              // printf("Changing total Min: %f\n to %f\n", min, totalMin);
          totalMin = min;
              // printf("Changed total Min: %f\n\n", totalMin);
        }

        // dup2(fd[0], totalMin);
        // dup2(fd[0], totalMax);

        fclose(fp);
            // printf("*****END CHILD PROCESS *******\n");
        snprintf(buffer, sizeof(buffer), "Filename: %s, sum: %f, diff: %f, max: %f, min: %f", readFile, sum, diff, max, min);
            // printf("Filename: %s, sum: %f, diff: %f, max: %f, min: %f\n", readFile, diff, sum, max, min);

        execl("/bin/echo", "echo", buffer, NULL);
      // }
      
    } 
  }


  // Create one child process for more

  // wait for the more process to finish
  int status;
  waitpid(pid, &status, 0);
  printf("MINIMUM=%f\tMAXIUMUM=%f", totalMin, totalMax);
  // printf("Done!\n");
  return 0;
}
