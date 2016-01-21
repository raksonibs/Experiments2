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
 

 // problem with current code is with number like -7 or 35, string doesn't preserve it. need commas then break it up!
 // alternate solution is to store with commas, and break with commas

 while (fgets(buffer, sizeof buffer, stream) != NULL)
  {
    int i = 0;
    len = strlen(stack);
    
    pch = strtok (buffer,"\n");
    

    if (strcmp(pch, "p") == 0) {
      printf("%c\n", stack[len - 1]);
    } else if (strcmp(pch, "q") == 0) {
      
      break;
    } else if (strcmp(pch, "+") == 0) {
      
      len = strlen(stack);
      
      last_num = stack[len - 1] - '0';
      second_last_num = stack[len - 2] - '0';
      
      result = last_num + second_last_num;
      
      sprintf(str, "%d", result);
      
      stack[len - 1] = '\0';
      len = strlen(stack);      

      
      stack[len - 1] = '\0';
      
      len = strlen(stack);
      
      strcat(stack, str);
      
    } else if (strcmp(pch, "-") == 0) {
      
      len = strlen(stack);
     
      last_num = stack[len - 1] - '0';
      second_last_num = stack[len - 2] - '0';
      
      result = second_last_num - last_num;
      
      sprintf(str, "%d", result);
      
      stack[len - 1] = '\0';
      len = strlen(stack);
      
      stack[len - 1] = '\0';
      
      len = strlen(stack);
      
      strcat(stack, str);
      
    } else if (strcmp(pch, "/") == 0) {
      
      len = strlen(stack);
      
      last_num = stack[len - 1] - '0';
      second_last_num = stack[len - 2] - '0';
      
      result = second_last_num / last_num;
      
      sprintf(str, "%d", result);
      
      stack[len - 1] = '\0';
      len = strlen(stack);
      stack[len - 1] = '\0';
      
      len = strlen(stack);
      
      strcat(stack, str);
      
    } else if (strcmp(pch, "*") == 0) {
      
      len = strlen(stack);
      
      last_num = stack[len - 1] - '0';
      second_last_num = stack[len - 2] - '0';
      
      result = last_num * second_last_num;
      
      sprintf(str, "%d", result);
      
      stack[len - 1] = '\0';
      len = strlen(stack);
      
      stack[len - 1] = '\0';
      
      len = strlen(stack);
      
      strcat(stack, str);
      
    } else {
      // number
      
      len = strlen(stack);
      
      strcat(stack, pch);
      len = strlen(stack);
      
    }

    
    
    }
    if (feof(stream))
    {     
    }
    else
    {   
      printf("File error\n");
    }
  
  

  return 0;
}
