#include <stdio.h>
#include <string.h>

int main() {

  char * pch;
  //array of strings which will be done in reverse
  char* words[200][200];

  int i = 0;

  char name[2000];

  int j = 0;

  while (scanf("%s", name) != EOF) {
    // get input
    // tokenize based on spaces
    pch = strtok(name, " ");

    while (pch != NULL) {
      printf("%s\n", pch);

      strcpy(words[i], pch);    
      i++;
      pch = strtok(NULL, " ");
    }
  }

  int sizeOf = sizeof(words) / sizeof(words[0]);

  // printf("%d\n", i);
  // printf("Word:\n");
  printf("%s,", words[i-1]);

  for (j=0; j < 50; j++) {
    if (j < i-1) {      
      printf(" %c.", words[j][0]);
    }
  }

  // for (j=0; j < 50 ; j++) {
  //   if (strcmp(words[j], "") == 0 || strcmp(words[j], " ") == 0 || strcmp(words[j], "\n") == 0) {
  //     // printf("nil");
  //   } else {
  //     if (j == 0) {        
  //       printf(" ,%s\n", words[j]);
  //     } else {

  //     }
  //   }
  // }

  return 0;
}
