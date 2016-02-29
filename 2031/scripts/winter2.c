#include <stdio.h>
#include <string.h>

int main() {
  char input[2000];

  char * pch;

  int numWords = 0;

  double wordLength = 0;

  fgets(input, sizeof(input), stdin);

  pch = strtok(input, " \n");

  // numWords++;

  if (strcmp(pch,".") == 0) {
    printf("Start with . ending\n");
  } else {    
    while (pch != NULL) {
      wordLength += strlen(pch);
      numWords++;

      pch = strtok(NULL, " \n");
    }
  }

  printf("Num words: %d\n", numWords);
  printf("Total word length: %f\n", wordLength);
  printf("Avg length: %f\n", wordLength / numWords);

  return 0;
}