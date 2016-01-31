#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
  char buffer[20];
  FILE *stream;
  stream = fopen("../../dictionary.txt" , "rb");
  char * pch;
  char words[200] = {};
  int count = 0;

  printf("%d\n", sizeof(words));
  while (fgets(buffer, sizeof buffer, stream) != NULL) {
    printf("%s\n", buffer);
    pch = strtok(buffer, "\n");
    words[count] = pch;
    count += 1;
    printf("%s\n", words);
  }
  if (feof(stream))
  {     
  }
  else
  {   
    printf("File error\n");
  }

  printf("Done\n");

  printf("%s\n", words);


}