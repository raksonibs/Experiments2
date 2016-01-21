#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* stradd(const char* a, const char* b){
    size_t len = strlen(a) + strlen(b);
    char *ret = (char*)malloc(len * sizeof(char) + 1);
    *ret = '\0';
    return strcat(strcat(ret, a) ,b);
}

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
 char * last_value;
 int result;
 char * pch;
 int second_count = 0;
 int next_num;
 char string_val;
 int len;
 while (fgets(buffer, sizeof buffer, stream) != NULL)
 {
  int i = 0;
  len = strlen(stack);
  printf("Length of stack at start %d\n", len);
  printf("Stack before addition %s\n", stack);
  pch = strtok (buffer,"\n");
  printf("Buffer here: %s\n", pch);
  printf("Length - 1 calc: %d\n", len - 1);
  for (i=0; i < len; i++)
    {
        printf("%c\n", stack[i]);
        last_value = stack[i];
    }
  printf("Last Val before going into anything: %c\n", last_value);

  if (strcmp(pch, "p") == 0) {
    printf("Printing\n");
    printf("Last Val in print loop: %c\n", last_value);
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
    len = strlen(stack);
    printf("Length before add %d\n", len);
    printf("Length - 1 calc: %d\n", len - 1);
    // char *str = stradd(stack, pch);
    // printf("String copied output %s\n", str);
    strcat(stack, pch);
    len = strlen(stack);
     for (i=0; i < len; i++)
    {
        last_value = stack[i];
    }
    printf("Length after add %d\n", len);
    printf("Length - 1 calc: %d\n", len - 1);
    printf("Stack after addition %s\n", stack);
    printf("Last val after addition %c\n", last_value);
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
