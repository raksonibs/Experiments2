#include <stdio.h>
#include <stdlib.h>
#include <string.h>


main() {
  printf("Starting program\n");
 char buffer[50];
 FILE *stream;
 stream = fopen("input_3.txt" , "rb");
 char * number;
 char * stack[50];
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
  printf("Last Val: %s\n", stack[(strlen(stack)-1)]);

  if (strcmp(pch, "p") == 0) {
    printf("Printing\n");
    printf("Last Val: %d\n", stack[(strlen(stack)-1)]);
  } else if (strcmp(pch, "q") == 0) {
    printf("Quiting\n");
    break;
  } else if (strcmp(pch, "+") == 0) {
    printf("Adding\n");
    last_num = atoi(stack[(strlen(stack)-1)]);
    second_last_num = atoi(stack[(strlen(stack)-2)]);
    stack[(strlen(stack)-1)] = NULL;
    stack[(strlen(stack)-2)] = NULL;
    result = last_num + second_last_num;
    stack[(strlen(stack)-2)] = result;        
  } else if (strcmp(pch, "-") == 0) {
    printf("Subtracting\n");
    last_num = atoi(stack[(strlen(stack)-1)]);
    second_last_num = atoi(stack[(strlen(stack)-2)]);
    stack[(strlen(stack)-1)] = NULL;
    stack[(strlen(stack)-2)] = NULL;
    result = last_num - second_last_num;
    stack[(strlen(stack)-2)] = result;        
  } else if (strcmp(pch, "/") == 0) {
    printf("Dividing\n");
    last_num = atoi(stack[(strlen(stack)-1)]);
    second_last_num = atoi(stack[(strlen(stack)-2)]);
    stack[(strlen(stack)-1)] = NULL;
    stack[(strlen(stack)-2)] = NULL;
    result = last_num / second_last_num;
    stack[(strlen(stack)-2)] = result;        
  } else if (strcmp(pch, "*") == 0) {
    printf("Multiplying\n");
    last_num = atoi(stack[(strlen(stack)-1)]);
    second_last_num = atoi(stack[(strlen(stack)-2)]);
    stack[(strlen(stack)-1)] = NULL;
    stack[(strlen(stack)-2)] = NULL;
    result = last_num * second_last_num;
    stack[(strlen(stack)-2)] = result;        
  } else {
    // number
    printf("Numbering\n");
    next_num = pch;
    if (strlen(stack) == 0) {
      stack[(strlen(stack))] = next_num;
    } else {

      stack[(strlen(stack)-1)] = next_num;
    }
    printf("Last val after addition %s\n", stack[(strlen(stack))]);
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
