#include <stdio.h>
#include <string.h>

main() {
  char input[2000];

  char * pch;
  int internal_count;
  char tmp[2000];
  while (fgets(input, sizeof(input), stdin)) {
    printf("%s\n", input);

    pch = strtok(input, " \t\n");
    while (pch != NULL) {
      // printf("%s\n", pch);
      strcpy(tmp, pch);
      pch = strtok(NULL, " \t\n");

      if (pch == NULL) {
        printf("%s, ", tmp);
      }
    }

    pch = strtok(input, " \t\n");
    while (pch != NULL) {
      printf("%s\n", pch);
      if (pch != tmp) {        
        printf("%c. ", pch[0]);
      }

      pch = strtok(NULL, " \t\n");
      
    }

  }
}