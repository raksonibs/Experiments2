#include <stdio.h>
#include <string.h>

int main() {
  char input[500];
  char temp;
  int checker[200];

  int i, max = 0, size = sizeof(checker)/sizeof(checker[0]);

  scanf("%s", input);

  for (i =0; i < size; i++) {
    checker[i] = 0;
  }

  for (i = 0; i < strlen(input); i++) {
    temp = input[i];
    checker[temp] += 1;
  }

  for (i =0; i < size; i ++) {
    if (checker[i] > max) {
      max = checker[i];
    }
  }

  for (i = 0; i< size;i++) {
    printf("%c\n", i);
    if (checker[i] == max) {
      printf("Max is %c: %d\n", i, checker[i]);
    }
  }

  return 0;
}