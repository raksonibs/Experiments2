#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>

static float * totalMax = 0;
static float * totalMin;

void *runner(void *param);
int sum;
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
  // float sum;
  float current;
  char buffer[1024];
  char * readFile;
  int val = 0, len, i;
  count = argc - 1;
  int internalCount = 1;
  int fd[2*count];
  pthread_t tid;
  pthread_attr_t attr;

  if (argc != 2) {
    fprintf(stderr,"usage: a.out <integer value>\n");
    return -1;
  }

  if (atoi(argv[1]) < 0) {
    fprintf(stderr,"%d must be >= 0\n",atoi(argv[1]));
    return -1;
  }

  // get the default attributes

  pthread_attr_init(&attr);
  // create thread
  pthread_create(&tid, &attr, runner, argv[1]);
  // wait for thread to exit
  pthread_join(tid, NULL);

  printf("Sum = %d\n", sum);

  // define NUM_THREADS 10
  // pthread_t workers[NUM_THREADS]
  // for (int i = 0; i < NUM_THREADS; i++) { pthread_join(workers[i], NULL); }
  
  return 0;
}

void *runner(void *param) {
  int i, upper = atoi(param);
  sum = 0;
  for (i = 1; i <= upper; i++) {
    sum += i;
  }

  pthread_exit(0);

}
