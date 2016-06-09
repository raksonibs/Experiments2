#include <pthread.h> #include <stdio.h>
  int sum; /* this data is shared by the thread(s) */
  void *runner(void *param); /* threads call this function */
  int main(int argc, char *argv[]) {
    pthread t tid; /* the thread identifier */
pthread attr t attr; /* set of thread attributes */
    if (argc != 2) {
      fprintf(stderr,"usage: a.out <integer value>\n"); return -1;
    }

    if (atoi(argv[1]) < 0) {
      fprintf(stderr,"%d must be >= 0\n",atoi(argv[1])); return -1;
    }

    /* get the default attributes */
pthread attr init(&attr);
/* create the thread */
pthread create(&tid,&attr,runner,argv[1]); /* wait for the thread to exit */
pthread join(tid,NULL); printf("sum = %d\n",sum);

  }

void *runner(void *param)
{
     int i, upper = atoi(param);
     sum = 0;
     for (i = 1; i <= upper; i++)
       sum += i;
pthread exit(0);
}
