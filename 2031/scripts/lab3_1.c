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
 int stack[50] = {1,2,3,4};
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
 len = sizeof stack;
 for (int i = 0; i < len; i++) {
  printf("%d\n", i);
 }
 printf("Stack is %d\n", stack);

 // while (fgets(buffer, sizeof buffer, stream) != NULL)
 // {
 //  pch = strtok (buffer,"\n");
  
 //  if (strcmp(pch, "p") == 0) {
 //    printf("Printing\n");
 //    printf("Last Val in print loop: %d\n", stack[len - 1]);
 //  } else if (strcmp(pch, "q") == 0) {
 //    printf("Quiting\n");
 //    break;
 //  } else if (strcmp(pch, "+") == 0) {
 //    printf("Addinggg\n");
    
 //    } else if (strcmp(pch, "-") == 0) {
 //      printf("Subtracting\n");
      
 //    } else if (strcmp(pch, "/") == 0) {
 //      printf("Dividing\n");
      
 //    } else if (strcmp(pch, "*") == 0) {
 //      printf("Multiplying\n");
 //    } else {
 //    // number
 //      printf("Numbering\n");
 //      next_num = atoi(pch);
 //      printf("Numbering this number %s\n", pch);
 //      len = strlen(stack);
 //      printf("Length before add %d\n", len);
 //      printf("Length - 1 calc: %d\n", len - 1);
 //      stack[len] = next_num;
 //      len = strlen(stack);
 //      printf("Length after add %d\n", len);
 //      printf("Length - 1 calc: %d\n", len - 1);
 //      printf("Stack after addition %d\n", stack);
 //      printf("Last val after addition %d\n", stack[len - 1]);
 //    }

 //    printf("next line \n\n");
  
 //  }
 //  if (feof(stream))
 //  {     
 //  }
 //  else
 //  {   
 //    printf("File error\n");
 //  }
  printf("Done!");

  return 0;
}
