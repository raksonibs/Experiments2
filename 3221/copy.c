/*
Family Name: Niburski
Given Name: Oskar
Section: Summer 3221
Student Number: 212644944
CS Login: raksonib
*/

// grab libraries
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <semaphore.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

// setup various mutexes
pthread_mutex_t increase_this_tid; 
pthread_mutex_t decrease_this_tid; 
pthread_mutex_t increase_this_tid_out; 
pthread_mutex_t entire_program_lock; 
pthread_mutex_t thread_completed; 

// global variables setup for diff threads
int storage_mem = 0; 
FILE *input; 
FILE *output; 
FILE *entire_log_stream; 
int internal_count, outcount; 
int internal_thread_count_referenced; 
int *joined_thread_workers, *can_out_join; 
int i; 
#define PAUSE_TIME 10000000

// predefined struct. note: use full as a boolean tracker of whether full or empty
typedef struct{
  int full;
  char data; 
  off_t offset; 
} BufferStruct;

// assign pointer
BufferStruct *mem_state;

// function declarations
int possible_empty();
int possibly_full();
void sleep_time();
void *internal_threads_internal_function(void *param); 
void *external_thread_function(void *param);
void close_and_free_files();

//start
int main(int argc, char *argv[]){
  
  // incorrect number of arguments
  if (argc > 7 || argc < 7) {
    fprintf(stderr, "Invalid arguments.\n");
    exit(1);
  }
  
  // init the mutexes
  pthread_mutex_init(&increase_this_tid, NULL);
  pthread_mutex_init(&entire_program_lock, NULL);
  pthread_mutex_init(&increase_this_tid_out, NULL);
  pthread_mutex_init(&thread_completed, NULL);
  pthread_mutex_init(&decrease_this_tid, NULL);  

  // various argument assignments based on stdinput
  storage_mem = atoi(argv[5]);
  char *filename_in = argv[3];
  char *filename_out = argv[4];
  int internal_count = atoi(argv[1]);
  int outcount = atoi(argv[2]);
  internal_thread_count_referenced = internal_count;
  char *logger = argv[6];
  
  //memory allocation
  can_out_join = malloc(outcount * sizeof(int));
  joined_thread_workers = malloc(internal_count * sizeof(int));
  mem_state = (BufferStruct*) malloc(storage_mem * sizeof(BufferStruct));
  // invalid values check
  if (internal_count < 1 || outcount < 1 || storage_mem < 1)  {
    fprintf(stderr, "Invalid values.\n");
    exit(1);  
  } 

  // files check
  output = fopen(filename_out, "w");
  input = fopen(filename_in, "r");
  entire_log_stream = fopen(logger, "w");
  if (input == NULL || output == NULL || entire_log_stream == NULL || joined_thread_workers == NULL || can_out_join == NULL) {
    fprintf(stderr, "Invalid file and memory allocation.\n"); 
    exit(1);
  }
  
  //time to set up workers
  pthread_t internal_threads[internal_count];
  pthread_t external_threads[outcount];
  
  // printf("Creating the mem_state acting as mem state: \n");
  
  // assign all mem_states to initial state of empty
  for (int traversed_num = 0; traversed_num < storage_mem; traversed_num++) {
    mem_state[traversed_num].full = 0;
  }
  
  // printf("Creating and executing threads: \n");
  
  // create the input and output threads
  for (int traversed_num = 0; traversed_num < internal_count; traversed_num++) {
    pthread_create(&internal_threads[traversed_num], NULL, (void *) internal_threads_internal_function, input);
  }  
  
  for (int traversed_num = 0; traversed_num < outcount; traversed_num++) {
    pthread_create(&external_threads[traversed_num], NULL, (void *) external_thread_function, output);  
  }  
  
  // execute on the threads by checking wthther state of internal threads is joined, or able to join via for loop and while loop
  for (int traversed_num = 0; traversed_num < internal_count; traversed_num++) {
    while(joined_thread_workers[traversed_num] == 0);  
  }
  
  for (int traversed_num = 0; traversed_num < outcount; traversed_num++) {
    while(can_out_join[traversed_num] == 0);
  }
  
  // assign threas to internal 
  for (int traversed_num = 0; traversed_num < internal_count; traversed_num++) {
    pthread_join(internal_threads[traversed_num], NULL);
  }
  
  // assign threads to external via join
  for (int traversed_num = 0; traversed_num < outcount; traversed_num++) {
    pthread_join(external_threads[traversed_num], NULL);
  }
  
  // printf("Completed.\n");
  //free memory!
  close_and_free_files();

  exit(0);
}

//sleepy time function, provided to us
void sleep_time() {
  struct timespec t;
  t.tv_sec = 0;
  t.tv_nsec = rand() % (PAUSE_TIME+1); 
  nanosleep(&t, NULL);
}

// checks if mem state if emtpy or not
int possible_empty() {
  for (int i = 0; i < storage_mem; i++) {
    if(mem_state[i].full == 0) {
      return i;
    }
  }

  return -1;
}

// checks if full
int possibly_full() {
  for (int i = 0; i < storage_mem; i++) {
    if (mem_state[i].full == 1) {
      return i;
    }
  }

  return -1;
}

//all the magic, makes them sleep, locks and then unlocks the variable to work on the critical internal count code
void *internal_threads_internal_function(void *param){
  
  sleep_time();
  
  int pos;
  char c;
  int address_of_memory;
  int local_internal_count;
  
  // unlocking locking part
  pthread_mutex_lock(&increase_this_tid);
  local_internal_count = internal_count++;
  pthread_mutex_unlock(&increase_this_tid);
  
  // checks input and whether end of line
  while (!feof(input)) {
    
    // locks entire program
    pthread_mutex_lock(&entire_program_lock);
    pos = possible_empty();     

    while (pos != -1){
      c = fgetc(input);
      // ftell is a sneaky way of grabbing an inputs tmp mem address
      address_of_memory = ftell(input);
      // output to log stream
      if (fprintf(entire_log_stream, "read_byte PT%d O%d B%d I-1\n", local_internal_count, address_of_memory, c) < 0) {
        fprintf(stderr, "Please provide valid files.\n");
        exit(1);
      }
      // check for line end
      if (c == EOF){
        break;
      }
      
      else { 
        // set mem_state data
        mem_state[pos].data = c;
        mem_state[pos].offset = address_of_memory;
        mem_state[pos].full = 1;
      }
      // output to log stream
      if (fprintf(entire_log_stream, "produce PT%d O%d B%d I%d\n", local_internal_count, address_of_memory, c, pos) < 0) {
        fprintf(stderr, "Please provide valid files.\n");
        exit(1);
      }
      // check again
      pos = possible_empty();
      // set thread to sleep
      sleep_time();
    }
    // done so can unlock
    pthread_mutex_unlock(&entire_program_lock);

  }
  
  // unlock and lock workers
  pthread_mutex_lock(&decrease_this_tid);
  internal_thread_count_referenced--;
  pthread_mutex_unlock(&decrease_this_tid);
  
  pthread_mutex_lock(&thread_completed);
  joined_thread_workers[local_internal_count] = 1;
  pthread_mutex_unlock(&thread_completed);
  
  sleep_time();  
  
  pthread_exit(0);
}
//closes
void close_and_free_files() {
  fclose(entire_log_stream);
  fclose(output);
  fclose(input);  
  free(joined_thread_workers);
  free(can_out_join);
  free(mem_state); 
}

void *external_thread_function(void *param){
  
  sleep_time();  
  
  //local variables
  int in_threads_running;
  int out_count;
  int pos = 0;
  char c;
  int address;
  int val;
  
  //increment thread count
  pthread_mutex_lock(&increase_this_tid);
  out_count = outcount++;
  pthread_mutex_unlock(&increase_this_tid);

  do {
    // critical section to read in the first item to be outputted
    pos = possibly_full();

    if (pos != -1){
      
      //obtain lock for consuming
      pthread_mutex_lock(&entire_program_lock);
      pos = possibly_full(); 
      
      //consume mem_state 
      address = mem_state[pos].offset;
      c = mem_state[pos].data;
      
      //write to log file
      if (fprintf(entire_log_stream, "consume CT%d O%d B%d I%d\n", out_count, address, c, pos) < 0) {
        fprintf(stderr, "\tProvide Valid Log File!\n\tExiting Now!\n");
        exit(1);
      }
      
      // store empty character to mem_state and indicate that it is empty
      mem_state[pos].full = 0;
      mem_state[pos].offset = 0;
      
      //release lock
      pthread_mutex_unlock(&entire_program_lock);

      //obtain lock for writing
      pthread_mutex_lock(&entire_program_lock);
      
      // critical section for writing to file 
      val = fseek(output, address, SEEK_SET);
      if (val < 0) {
        pthread_mutex_unlock(&entire_program_lock);
          fprintf(stderr, "\tProvide Valid Seek!\n\tExiting Now!\n");
        exit(1);
      }
      if (fputc(c, output) == EOF) {
        pthread_mutex_unlock(&entire_program_lock);
          fprintf(stderr, "\tInvalid File Write!\n\tExiting Now!\n");
        exit(1);
      }
      
      //write to log file
      if (fprintf(entire_log_stream, "write_byte CT%d O%d B%d I-1\n", out_count, address, c) < 0) {
        fprintf(stderr, "\tProvide Valid Log File!\n\tExiting Now!\n");
        exit(1);
      }
      
      //release lock
      pthread_mutex_unlock(&entire_program_lock);
    }
    sleep_time();
    
    //assign thread count for exiting
    in_threads_running = internal_thread_count_referenced;
  
  } while (in_threads_running > 0 || pos != -1);
  
  //let main() know thread has finished
  pthread_mutex_lock(&thread_completed);
  can_out_join[out_count] = 1;
  pthread_mutex_unlock(&thread_completed);
  
  pthread_exit(0);
}