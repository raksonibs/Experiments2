#include <stdio.h>
#include <string.h>

int main() {

  char input[20000];
  char word[200];
  printf("Input word\n");
  fgets(word, sizeof(word), stdin);
  printf("Input text\n");

  int c;
  int i;
  i=0;

  char line[1000];

  while ((c=getchar()) != EOF && c != '\n') {

  }

  char * pch;

  pch = strtok(input, "\n");

  while (pch != NULL) {
    printf("%s\n", pch);
    pch = strtok(NULL, "\n");
  }

  return 0;
}