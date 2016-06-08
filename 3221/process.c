#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // for each data set, make a child process
  // reads data set file names
  // each child process reads from its own file
  // calculates sum of large small, differenfce between large small, and min and max
  //  then sends to main process via a pipe to standard output the filename followed by received sum and dif values
  // may strucutre as waiting for all child process to finish then processing their data, or waiting for any child to finish and process its data.

  int pid;

  char * arr[200];

  char * pch;

  char str[5000];

  FILE * fp;
  int count = 0;

  // fgets(stdin, arr, sizeof(arr));

  // printf("%s", arr);

   // fp = fopen("file.txt" , "r");
   // if(fp == NULL) 
   // {
   //    perror("Error opening file");
   //    return(-1);
   // }
   // if( fgets (str, 60, fp)!=NULL ) 
   // {
   //    /* writing content to stdout */
   //    puts(str);
   // }
   // fclose(fp);

  // this will be reading from command line each data set
  while (count < 3) {

    pid = fork();
    // fork child process

    if (pid < 0) {
      // error occured
      fprintf(stderr, "%s\n", "ouch");
      return 1;
    } else if (pid == 0) {
      // child processs
      printf("\n Hello I am the child process ");
      printf("\n My pid is %d \n",getpid());
      fp = fopen("dataset1.txt" , "r");
       if(fp == NULL) 
       {
          perror("Error opening file");
          return(-1);
       }
       if( fgets (str, 60, fp)!=NULL ) 
       {
          /* writing content to stdout */
          puts(str);
       }
       count++;
       fclose(fp);
      // execlp("/bin/ls", "ls", NULL);
    } else {
      // parent will wait for child to complete
      wait(NULL);
      printf("Child complete\n");
      printf("\n Hello I am the parent process ");
      printf("\n My actual pid is %d \n ",getpid());
    }
  }

  return 0;
}
