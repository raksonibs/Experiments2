#include <string.h>
#include <stdio.h>
#include <stdio.h>

main() {
  char input[2000];

  fgets(input, sizeof(input), stdin);

  int i = 0;
  int j = 0;
  int match = 0;
  int k =0;

  int* finalArr[200];
  int count = 0;

  for (i=0; i < strlen(input); i++) {
    match = 0;
    for (j=0; j < strlen(input); j++) {
      if (input[i] == input[j] && i!= j) {
        match = 1;
        break;
      }
    }

    if (match) {
      finalArr[count] = i;
      count++;
    }
  }

  for (k=0; k < count-1;k++) {
    printf("%d,", finalArr[k]);
  }
  printf("%d", finalArr[count-1]);
}