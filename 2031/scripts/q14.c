#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  
  char input[200];

  char fixed[200];

  char * pch;

  fgets(input, sizeof(input), stdin);

  // pch = strtok(input, " \t");

  // while (pch != NULL) {
  //   printf("%s", pch);
  //   pch = strtok(input, " \t");
  // } 

  

  for (int i=0; i < strlen(input); i++) {
    if (input[i] != '\t' && input[i] != ' ') {      
      printf("%c", input[i]);
    }
  }

  return 0;
}