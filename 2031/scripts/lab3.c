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
 char stack[50];
 int count = 1;
 int last_num;
 int second_last_num;
 char * last_value;
 char * second_last_value;
 int result;
 char * pch;
 int second_count = 0;
 int next_num;
 char string_val;
 int len;
 char str[15];
 printf("Stack is %s\n", stack);

 // problem with current code is with number like -7 or 35, string doesn't preserve it. need commas then break it up!

 while (fgets(buffer, sizeof buffer, stream) != NULL)
 {
  int i = 0;
  len = strlen(stack);
  printf("Length of stack at start %d\n", len);
  printf("Stack before addition %s\n", stack);
  pch = strtok (buffer,"\n");
  printf("Buffer here: %s\n", pch);
  printf("Length - 1 calc: %d\n", len - 1);
  printf("Last Val before going into anything: %c\n", stack[len - 1]);

  if (strcmp(pch, "p") == 0) {
    printf("Printing\n");
    printf("Last Val in print loop: %c\n", stack[len - 1]);
  } else if (strcmp(pch, "q") == 0) {
    printf("Quiting\n");
    break;
  } else if (strcmp(pch, "+") == 0) {
    printf("Addinggg\n");
    len = strlen(stack);
    printf("Length of stack at start %d\n", len);
    printf("Last Val before addition: %c\n", stack[len - 1]);
    printf("Second Last Val before addition: %c\n", stack[len - 2]);
    printf("Trying to atoi\n");
    last_num = stack[len - 1] - '0';
    second_last_num = stack[len - 2] - '0';
    printf("Successful atoi\n");
    printf("Last Val before atoi addition: %d\n", last_num);
    printf("Second Last Val before atoi addition: %d\n", second_last_num);
    result = last_num + second_last_num;
    printf("Addition result: %d\n", result);
    sprintf(str, "%d", result);
    printf("Reassigning last two values to nill and setting result to final value: %s\n", str);
    stack[len - 1] = '\0';
    len = strlen(stack);
    printf("Length of stack at after first subtract %d\n", len);

    printf("stack is now: %s\n", stack);
    printf("Reassigning the next nill\n");
    stack[len - 1] = '\0';
    printf("stack is now this: %s\n", stack);
    len = strlen(stack);
    printf("Length of stack at after second subtract %d\n", len);
    strcat(stack, str);
    printf("Stack after actual math addition result %s\n", stack);
    } else if (strcmp(pch, "-") == 0) {
      printf("Subtracting\n");
      len = strlen(stack);
      printf("Length of stack at start %d\n", len);
      printf("Last Val before subtraction: %c\n", stack[len - 1]);
      printf("Second Last Val before subtraction: %c\n", stack[len - 2]);
      printf("Trying to atoi\n");
      last_num = stack[len - 1] - '0';
      second_last_num = stack[len - 2] - '0';
      printf("Successful atoi\n");
      printf("Last Val before atoi subtraction: %d\n", last_num);
      printf("Second Last Val before atoi subtraction: %d\n", second_last_num);
      result = second_last_num - last_num;
      printf("subtraction result: %d\n", result);
      sprintf(str, "%d", result);
      printf("Reassigning last two values to nill and setting result to final value: %s\n", str);
      stack[len - 1] = '\0';
      len = strlen(stack);
      printf("Length of stack at after first subtract %d\n", len);

      printf("stack is now: %s\n", stack);
      printf("Reassigning the next nill\n");
      stack[len - 1] = '\0';
      printf("stack is now this: %s\n", stack);
      len = strlen(stack);
      printf("Length of stack at after second subtract %d\n", len);
      strcat(stack, str);
      printf("Stack after actual math subtraction result %s\n", stack);
    } else if (strcmp(pch, "/") == 0) {
      printf("Dividing\n");
      len = strlen(stack);
      printf("Length of stack at start %d\n", len);
      printf("Last Val before dividing: %c\n", stack[len - 1]);
      printf("Second Last Val before dividing: %c\n", stack[len - 2]);
      printf("Trying to atoi\n");
      last_num = stack[len - 1] - '0';
      second_last_num = stack[len - 2] - '0';
      printf("Successful atoi\n");
      printf("Last Val before atoi dividing: %d\n", last_num);
      printf("Second Last Val before atoi dividing: %d\n", second_last_num);
      result = second_last_num / last_num;
      printf("dividing result: %d\n", result);
      sprintf(str, "%d", result);
      printf("Reassigning last two values to nill and setting result to final value: %s\n", str);
      stack[len - 1] = '\0';
      len = strlen(stack);
      printf("Length of stack at after first subtract %d\n", len);

      printf("stack is now: %s\n", stack);
      printf("Reassigning the next nill\n");
      stack[len - 1] = '\0';
      printf("stack is now this: %s\n", stack);
      len = strlen(stack);
      printf("Length of stack at after second subtract %d\n", len);
      strcat(stack, str);
      printf("Stack after actual math dividing result %s\n", stack);
    } else if (strcmp(pch, "*") == 0) {
      printf("Multiplying\n");
      len = strlen(stack);
      printf("Length of stack at start %d\n", len);
      printf("Last Val before multiplying: %c\n", stack[len - 1]);
      printf("Second Last Val before multiplying: %c\n", stack[len - 2]);
      printf("Trying to atoi\n");
      last_num = stack[len - 1] - '0';
      second_last_num = stack[len - 2] - '0';
      printf("Successful atoi\n");
      printf("Last Val before atoi multiplying: %d\n", last_num);
      printf("Second Last Val before atoi multiplying: %d\n", second_last_num);
      result = last_num * second_last_num;
      printf("multiplying result: %d\n", result);
      sprintf(str, "%d", result);
      printf("Reassigning last two values to nill and setting result to final value: %s\n", str);
      stack[len - 1] = '\0';
      len = strlen(stack);
      printf("Length of stack at after first subtract %d\n", len);

      printf("stack is now: %s\n", stack);
      printf("Reassigning the next nill\n");
      stack[len - 1] = '\0';
      printf("stack is now this: %s\n", stack);
      len = strlen(stack);
      printf("Length of stack at after second subtract %d\n", len);
      strcat(stack, str);
      printf("Stack after actual math multiplying result %s\n", stack);
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
    printf("Length after add %d\n", len);
    printf("Length - 1 calc: %d\n", len - 1);
    printf("Stack after addition %s\n", stack);
    printf("Last val after addition %c\n", stack[len - 1]);
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
