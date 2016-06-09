
// shared memory bounded buffer
#define BUFFER_SIZE 10
typedef struct {
// . . .
} item;
item buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

// bounded buffer producer
item next_produced;
while (true) {
/* produce an item in next produced */
while (((in + 1) % BUFFER_SIZE) == out)
; /* do nothing */
buffer[in] = next_produced;
in = (in + 1) % BUFFER_SIZE;
} 

// bounded buffer - consumer
item next_consumed;
while (true) {
while (in == out)
; /* do nothing */
next_consumed = buffer[out];
out = (out + 1) % BUFFER_SIZE;
/* consume the item in next consumed */
} 

// synchronization - pproducer consumer becomes tiriavl
message next_produced;
 while (true) {
 /* produce an item in next produced */
 send(next_produced);
 }
message next_consumed;
while (true) {
 receive(next_consumed);

 /* consume the item in next consumed */
}

// pthreads joining threads
#define NUM THREADS 10
/* an array of threads to be joined upon */ pthread t workers[NUM THREADS];
for (int i = 0; i < NUM THREADS; i++) pthread join(workers[i], NULL);



  // open mp parallelism
  #include <omp.h> #include <stdio.h>
  int main(int argc, char *argv[]) {
    #pragma omp parallel {
    printf("parralel")
    // parralel code
  }
  }