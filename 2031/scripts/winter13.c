#include <string.h>
#include <stdio.h>
#include <stdlib.h>

main() {
  char input[200];
  // remeber this
  char words[20][20];

  fgets(input, sizeof(input), stdin);

  char * pch;

  pch = strtok(input, " \n");
  int count = 0;
  while (pch != NULL) {
    printf("%s\n", pch);
    strcpy(words[count], pch);
    count++;
    pch = strtok(NULL, " \n");
  } 

  printf("%s, ", words[count-1]);
  int i =0;
  for (i=0; i < count-1 ;i++) {

    printf("%c. ", words[i][0]);
  }


}