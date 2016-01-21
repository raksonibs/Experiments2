#include <stdio.h>
#include <stdlib.h>
#include <string.h>


main() {
  printf("Starting program\n");
 char buffer[50];
 FILE *stream;
 stream = fopen("input_3.txt" , "rb");
 char * number;
 char * stack[50] = {};
 int count = 1;
 int last_num;
 int second_last_num;
 int result;
 char * pch;
 int second_count = 0;
 int next_num;
 char string_val;
 int len;
 while (fgets(buffer, sizeof buffer, stream) != NULL)
 {
  len = strlen(stack);
  printf("Length of stack at start %d\n", len);
  pch = strtok (buffer,"\n");
  printf("Buffer here: %s\n", pch);
  printf("Last Val before going into anything: %c\n", stack[len - 1]);

  if (strcmp(pch, "p") == 0) {
    printf("Printing\n");
    printf("Last Val: %c\n", stack[len - 1]);
  } else if (strcmp(pch, "q") == 0) {
    printf("Quiting\n");
    break;
  } else if (strcmp(pch, "+") == 0) {
    printf("Adding\n");
  } else if (strcmp(pch, "-") == 0) {
    printf("Subtracting\n");
  } else if (strcmp(pch, "/") == 0) {
    printf("Dividing\n");
  } else if (strcmp(pch, "*") == 0) {
    printf("Multiplying\n");
  } else {
    // number
    printf("Numbering\n");
    next_num = pch;
    printf("Numbering this number %s\n", pch);
    strcat(stack, pch);
    int i = 0;
    len = strlen(stack);
    printf("Length before add %d\n", len);
    printf("Stack after addition %s\n", stack);
    printf("Last val after addition %c\n", stack[len - 1]);
    len = strlen(stack);
    printf("Length after add %d\n", len);
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
