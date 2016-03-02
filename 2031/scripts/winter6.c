#include <string.h>
#include <stdio.h>

main() {
  char input[20000];
  char * pch;
  int totalwords=0;
  int numwords = 0;
  while (fgets(input, sizeof(input), stdin)) {
    pch = strtok(input, " \n");
    numwords++;

    if (pch[0] == '.') {
      printf("Stop drop and roll\n");
    } else {
      printf("Over here!");
      while (pch != NULL) {
        printf("Word: %s\n", pch);
        totalwords += strlen(pch);
        printf("length: %d\n", strlen(pch));
        pch = strtok(NULL, " \n");
        

        if (pch == NULL) {
          printf("total word length: %d\n", totalwords);
          printf("total words: %d\n", numwords);
          printf("Avg word length: %f\n", ((double)totalwords)/numwords);
        }

        numwords++;
      }
    }
  }
}