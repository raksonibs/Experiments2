/*
Family Name: Niburski
Given Name: Oskar
Section: Summer 3221
Student Number: 212644944
CS Login: raksonib
*/

// task: 
// Your task is to write a C program that creates two groups of Pthreads, an IN group and an OUT group, to create an exact copy of a source file passed as a command-line argument.

// grab libraries
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <semaphore.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

int buffer = 0; 
FILE *input; 
FILE *output; 
FILE *entire_log_stream; 
int global_internal_count, global_external_count; 
int internal_thread_count; 
int *joined_workers, *possible_to_external_join_thread; 
int i; 
#define PAUSE_TIME 10000000

// predefined struct. note: use full as a boolean tracker of whether full or empty
typedef struct {
  int full;
  char data; 
  off_t offset; 
} BufferStruct;
BufferStruct *mem_state;

// setup various mutexes
pthread_mutex_t increase_this_tid; 
pthread_mutex_t decrease_this_tid; 
pthread_mutex_t increase_this_tid_out; 
pthread_mutex_t entire_program_lock; 
pthread_mutex_t thread_completed; 

// function declarations
int possible_empty();
int possibly_full();
void sleep_time();
void *in_thread_internal_function(void *param); 
void *external_thread_function(void *param);
void close_and_free_files();

//start
int main(int argc, char *argv[]){
  // incorrect number of arguments
  if (argc > 7 || argc < 7) {
    fprintf(stderr, "Invalid arguments\n");
    exit(1);
  }
  
  // init the mutexes
  pthread_mutex_init(&increase_this_tid, NULL);
  pthread_mutex_init(&entire_program_lock, NULL);
  pthread_mutex_init(&increase_this_tid_out, NULL);
  pthread_mutex_init(&thread_completed, NULL);
  pthread_mutex_init(&decrease_this_tid, NULL);  

  // various argument assignments based on stdinput
  buffer = atoi(argv[5]);
  char *filename_in = argv[3];
  char *filename_out = argv[4];
  int internal_count = atoi(argv[1]);
  int external_count = atoi(argv[2]);
  internal_thread_count = internal_count;
  char *log_file = argv[6];
  
  //memory allocation
  possible_to_external_join_thread = malloc(external_count * sizeof(int));
  joined_workers = malloc(internal_count * sizeof(int));
  mem_state = (BufferStruct*) malloc(buffer * sizeof(BufferStruct));
  entire_log_stream = fopen(log_file, "w");
  output = fopen(filename_out, "w");
  input = fopen(filename_in, "r");

  if (entire_log_stream == NULL || joined_workers == NULL || possible_to_external_join_thread == NULL || output == NULL || internal_count < 1 || external_count < 1 || buffer < 1 || input == NULL) {
    fprintf(stderr, "Invalid Arguments\n"); 
    exit(1);
  }
  
  //time to set up workers
  pthread_t in_thread[internal_count];
  pthread_t out_thread[external_count];

  // assign all mem_states to initial state of empty
  for (int traversed_num = 0; traversed_num < buffer; traversed_num++) {
    mem_state[traversed_num].full = 0;
  }
  
  // create the input and output threads
  for (int traversed_num = 0; traversed_num < internal_count; traversed_num++) {
    pthread_create(&in_thread[traversed_num], NULL, (void *) in_thread_internal_function, input);
  }
  
  for (int traversed_num = 0; traversed_num < external_count; traversed_num++) {
    pthread_create(&out_thread[traversed_num], NULL, (void *) external_thread_function, output);  
  }
  
  for (int traversed_num = 0; traversed_num < internal_count; traversed_num++) {
    while(joined_workers[traversed_num] == 0);  
  }
  
  // execute on the threads by checking wthther state of internal threads is joined, or able to join via for loop and while loop
  for (int traversed_num = 0; traversed_num < external_count; traversed_num++) {
    while(possible_to_external_join_thread[traversed_num] == 0);
  }

  // assign threas to internal
  for (int traversed_num = 0; traversed_num < internal_count; traversed_num++) {
    pthread_join(in_thread[traversed_num], NULL);
  }
  
  // assign threads to external via join
  for (int traversed_num = 0; traversed_num < external_count; traversed_num++) {
    pthread_join(out_thread[traversed_num], NULL);
  }

  fclose(input);  
  fclose(entire_log_stream);
  fclose(output);
  free(mem_state); 
  free(joined_workers);
  free(possible_to_external_join_thread);

  exit(0);
}

//sleepy time function, provided to us
void sleep_time() {
  struct timespec t;
  t.tv_sec = 0;
  t.tv_nsec = rand()%(PAUSE_TIME+1); 
  nanosleep(&t, NULL);
}

// checks if mem state if emtpy or not
int possibly_full() {
  int return_val = -1;
  for (int i = 0; i < buffer; i++) {
    if (mem_state[i].full == 1) {
      return_val = i;
      return return_val;
    }
  }
  return return_val;
}
// checks if mem state if emtpy or not
int possible_empty() {
  int return_val = -1;
  for (int i = 0; i < buffer; i++) {
    if (mem_state[i].full == 0) {
      return_val = i;
      return return_val;
    }
  }
  return return_val;
}

//all the magic, makes them sleep, locks and then unlocks the variable to work on the critical internal count code
void *in_thread_internal_function(void *param){

  sleep_time();
  
  int possibility = 0;
  char c;
  int address;
  int local_internal_ref;
  
  // unlocking locking part
  pthread_mutex_lock(&increase_this_tid);
  local_internal_ref = global_internal_count++;
  pthread_mutex_unlock(&increase_this_tid);
  
  // checks input and whether end of line
  while (!feof(input)) {
    //mtx lock on entire progrma
    pthread_mutex_lock(&entire_program_lock);
    possibility = possible_empty();     

    //if possiblity is not -1, so empty
    while (possibility != -1){

      // get address
      address = ftell(input);
      c = fgetc(input);
      //get input val
      //output to local incoutn
      if (fprintf(entire_log_stream, "read_byte PT%d O%d B%d I-1\n", local_internal_ref, address, c) < 0) {        
        exit(1);
      }
      
      if (c == EOF){
        break;
      }

      else { 
        mem_state[possibility].data = c;
        mem_state[possibility].offset = address;
        mem_state[possibility].full = 1;
      }
      
      if (fprintf(entire_log_stream, "produce PT%d O%d B%d I%d\n", local_internal_ref, address, c, possibility) < 0) {        
        exit(1);
      }

      possibility = possible_empty();
      
      sleep_time();
    }
    
    pthread_mutex_unlock(&entire_program_lock);

  };

  pthread_mutex_lock(&decrease_this_tid);
  internal_thread_count--;
  pthread_mutex_unlock(&decrease_this_tid);
  
  pthread_mutex_lock(&thread_completed);
  joined_workers[local_internal_ref] = 1;
  pthread_mutex_unlock(&thread_completed);
  
  sleep_time();  
  
  pthread_exit(0);
}

//all the magic, makes them sleep, locks and then unlocks the variable to work on the critical external count code
void *external_thread_function(void *param){
  //set up local vars and external ref
  sleep_time();  
  
  int external_count;
  int number_of_internal_threads;
  int possibility = 0;
  char c;
  int address;
  int val;
  //mutx locks
  pthread_mutex_lock(&increase_this_tid_out);
  external_count = global_external_count++;
  pthread_mutex_unlock(&increase_this_tid_out);

  do {
    //check if full
    possibility = possibly_full();

    if (possibility != -1){

      //lock program
      pthread_mutex_lock(&entire_program_lock);
      possibility = possibly_full(); 
      // setup data
      address = mem_state[possibility].offset;
      c = mem_state[possibility].data;
      
      if (fprintf(entire_log_stream, "consume CT%d O%d B%d I%d\n", external_count, address, c, possibility) < 0) {        
        exit(1);
      }
      //reassign offset and full boolean
      mem_state[possibility].full = 0;
      mem_state[possibility].offset = 0;
      
      //lock and unlock
      pthread_mutex_unlock(&entire_program_lock);
      pthread_mutex_lock(&entire_program_lock);
      
      //sneaky way of grabbing address
      val = fseek(output, address, SEEK_SET);
      if (fputc(c, output) == EOF || val < 0) {
        pthread_mutex_unlock(&entire_program_lock);          
        exit(1);
      }
      //wirte to file
      if (fprintf(entire_log_stream, "write_byte CT%d O%d B%d I-1\n", external_count, address, c) < 0) {        
        exit(1);
      }
      //critical section done, unlock yo!
      pthread_mutex_unlock(&entire_program_lock);
    }

    sleep_time();
    number_of_internal_threads = internal_thread_count;

  } while (number_of_internal_threads > 0 || possibility != -1);

  //unlock and lock code for external code (similiar to internal count)
  pthread_mutex_lock(&thread_completed);
  possible_to_external_join_thread[external_count] = 1;
  pthread_mutex_unlock(&thread_completed);
  
  pthread_exit(0);
}