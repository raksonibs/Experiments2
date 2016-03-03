#include <string.h>
#include <stdio.h>
#include <stdlib.h>

main() {
  char input[200];

  int checker[200];
  int size;
  size = sizeof(checker)/sizeof(checker[0]);

  char temp;

  scanf("%s", &input);
  int i=0;
  for (i=0; i < size; i++) {
    checker[i] = 0;
  }

  for (i=0; i < strlen(input); i++) {
    temp = input[i];
    checker[temp] += 1;
  }


}