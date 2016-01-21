#include <stdio.h>
#include <stdlib.h>
#include <string.h>


main() {
  printf("Starting program\n");
 char buffer[50];
 FILE *stream;
 stream = fopen("input_3.txt" , "rb");
 char * number;
 int * stack[50];
 int count = 1;
 int last_num;
 int second_last_num;
 int result;
 char * pch;
 int second_count = 0;
 int next_num;
 char string_val;
 while (fgets(buffer, sizeof buffer, stream) != NULL)
 {

  pch = strtok (buffer," ");
  printf("Buffer here: %s\n", pch);
  printf("Last Val: %d\n", stack[count]);
  
  if (strcmp(pch, "p") == 0) {
    printf("Printing\n");
    printf("Last Val: %d\n", stack[count]);
  } else if (strcmp(pch, "q") == 0) {
    printf("Quiting\n");
    break;
  } else if (strcmp(pch, "+") == 0) {
    printf("Adding\n");
    last_num = stack[count];
    second_last_num = stack[second_count];
    stack[count] = NULL;
    stack[second_count] = NULL;
    result = last_num + second_last_num;
    stack[second_count] = result;
    second_count = second_count - 2;
    count = count - 1;
  } else if (strcmp(pch, "-") == 0) {
    printf("Subtracting\n");
    last_num = stack[count];
    second_last_num = stack[second_count];
    stack[count] = NULL;
    stack[second_count] = NULL;
    result = last_num - second_last_num;
    stack[second_count] = result;
    second_count = second_count - 2;
    count = count - 1;
  } else if (strcmp(pch, "/") == 0) {
    printf("Dividing\n");
    last_num = stack[count];
    second_last_num = stack[second_count];
    stack[count] = NULL;
    stack[second_count] = NULL;
    result = last_num / second_last_num;
    stack[second_count] = result;
    second_count = second_count - 2;
    count = count - 1;
  } else if (strcmp(pch, "*") == 0) {
    printf("Multiplying\n");
    last_num = stack[count];
    second_last_num = stack[second_count];
    stack[count] = NULL;
    stack[second_count] = NULL;
    result = last_num * second_last_num;
    stack[second_count] = result;
    second_count = second_count - 2;
    count = count - 1;
  } else {
    // number
    printf("Numbering\n");
    next_num = atoi(pch);
    stack[count] = next_num;
    count = count + 1;
    second_count = second_count + 1;
  }

  printf("next line \n\n");
  
  }
  if (feof(stream))
  {     
  }
  else
  {   
    printf("File error\n");
  }
  printf("Done!");

  return 0;
}
