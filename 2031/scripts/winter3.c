#include <stdio.h>
#include <string.h>

int main() {
  char input[2000];

  char * pch;

  int i = 0;
  int j = 0;

  char output[4000];

  fgets(input, sizeof(input), stdin);

  for (i=0; i < strlen(input)-1; i++) {
    // printf("Current num %c\n,", input[i]);
    for (j=i; j < strlen(input)-1; j++) {
      // printf("Comparing num %c\n,", input[j]);
      // this comparison with other method doesn't work, because these guys are all cgoing to return a position
      if (input[i] == input[j]) {
        printf("%d,", j);
      }
    }

  }

  return 0;
}