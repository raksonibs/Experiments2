#include <stdio.h>
#include <string.h>
// 56257278
//0,2,3,4,5,6
int main() {
  char input[2000];

  char * pch;

  int i = 0;
  int j = 0;

  char output[4000];
  int match = 0;

  fgets(input, sizeof(input), stdin);

  for (i=0; i < strlen(input)-1; i++) {
    match = 0;
    // printf("Current num %c\n,", input[i]);
    for (j=0; j < strlen(input)-1; j++) {
      // printf("Comparing num %c\n,", input[j]);
      // this comparison with other method doesn't work, because these guys are all cgoing to return a position
      if (input[i] == input[j] && i != j) {
        match = 1;
      }
    }

    if (match == 1) {
      if (i == strlen(input)-3) {        
        printf("%d", i);
      } else {
        printf("%d,", i);
      }
    }

  }

  return 0;
}