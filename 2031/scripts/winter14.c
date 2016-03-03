#include <string.h>
#include <stdio.h>
#include <stdlib.h>

main() {
  char input [20000];

  fgets(input, sizeof(input), stdin);

  if (input[0] == '.') {
    printf("Period first\n");
  }

  int count=0;
  int wordLength= 0;
  int words = 0;
  int totalWords = 0;
  int i = 0;
  // should use pch for whitespace appreciation next, not by input, just check each pch for char!
  for (i=0; i <strlen(input) ;i++) {
    if (input[i] == '.') {
      totalWords += wordLength;
      wordLength = 0;
      words++;
      break;
    }

    
    if (input[i] == ' ') {
      totalWords += wordLength;
      wordLength = 0;
      words++;
    } else {
      wordLength++;
      printf("Current wordlength: %d\n", wordLength);
    }

  }

  printf("WOrds: %d\n", words);
  printf("Total WOrds: %d\n", totalWords);
  printf("AvG: %f\n", ((double)totalWords)/words);
}