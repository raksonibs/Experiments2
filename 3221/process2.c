/*
Family Name: Niburski
Given Name: Oskar
Student Number: 212644944
CS Login: raksonib
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/wait.h>
#include <sys/mman.h>

/* This is the main class that will be used to read entire data file and store respective files. Store incrementally! */
typedef struct {
  char filename[1000]; 
  double sum;
  double diff;
  double min; 
  double max;
} ValueArr;

/*Read and Write constants*/
#define WRITE 1
#define READ 0
  
ValueArr *array; //declare array pointer

// shared memory
int current_position = 0;
double min = INFINITY;
double max = -INFINITY;

//main functions starts
int main(int argc, char *argv[]) {

  if (argc < 2) {
    fprintf(stderr, "No files\n");
    exit(-1);
    return 1;
  }
  
  array = (ValueArr*) malloc(sizeof(ValueArr)*argc);
  int count = 1;
  /*Important actual array of pipes. First arg is the child, read and write is second arg*/
  int readWriteArr[argc-1][2]; 
  FILE *file;
  char *filename;
  int pid;
  double current;
  char * pch;
  
  while (count < argc) {
  
    filename = argv[count];
    file = fopen(filename, "r");
    
    if (file == NULL) {
      fprintf(stderr, "Invalid File!\n"); 
      exit(-1);
    }
    
    if (pipe (readWriteArr[count-1]) < 0) {
      fprintf(stderr, "Can't actually read...\n"); 
      exit(-1);
    }
  
  // Might need to reassign forking here!
    if ((pid = fork()) < 0) {
      fprintf(stderr, "Fork a child incorrect!\n"); 
      exit(-1);
    }
    
    if (pid == 0) {
     //Child Process
      
      /* Now we can go and read from the child proces.*/
      close(readWriteArr[count-1][READ]);
      
      char str[1000];
      int q = 0;
      double sum = 0.0;
      double diff = 0.0;
      double min = INFINITY;
      double max = -INFINITY;
      
      while ((fscanf (file, "%s", str)) != EOF) {
        
         double current = atof(str);
         
         if (current < min) {
           min = current; 
         }
         
         if (current > max) {
           max = current; 
         }
           
        /* clear the memory!*/
        memset(str, '\0', 101);
      }

      /*
        Close file.
      */
      fclose(file);
      
      diff = max - min;
      sum = max + min;
      
      /* assign the various args */
      array[count-1].diff = diff;
      array[count-1].sum = sum;
      array[count-1].max = max;
      array[count-1].min = min;
        
      strcpy(array[count-1].filename, argv[count]); //Copy filename 
      
      /*
        Write signal to parent. Note: &array here refers to struct of current child
      */
      write(readWriteArr[count-1][WRITE], &array[count-1], sizeof(ValueArr));
      
      /*
        Close pipe
      */
      close(readWriteArr[count-1][WRITE]);
    
      /*Successful termination.*/
      exit(0);
      
    } //child process end
    
    //Parent Process
    else {
    
      /*Close write pipe for parent.*/
      close(readWriteArr[count-1][WRITE]);
      
      /* 
       * parent needs to read once count is great than the entire argument, count is defined as the current children elements read
       */
      if (count + 1 == argc) {
        
        for(current_position = 0; current_position < argc - 1; current_position++) {
          
          /*
            wait for 1 process at a time, 
            and then enter it in current `array'. 
            Then print.
          */

          wait(NULL);
          read(readWriteArr[current_position][READ], &array[current_position], sizeof(ValueArr));
          close(readWriteArr[current_position][READ]); //close pipe
          printf("%s\tSUM = %f\tDIF = %f\tMIN = %f\tMIX = %f\n", array[current_position].filename, array[current_position].sum, array[current_position].diff, array[current_position].min, array[current_position].max);
        
          if (array[current_position].min < min) {
            min = array[current_position].min;
          }
          
          if (array[current_position].max > max) {
            max = array[current_position].max;
          }
          
          // answer!:D
          if (current_position == argc - 2) {
            printf("MINIMUN = %f\tMAXIMUM = %f\n", min, max);
          }
        }
      } 
      
    }
    count++;
  }
  
  /* free entire memory! garbage collection ftw..*/
  free(array);
  return 1;
}