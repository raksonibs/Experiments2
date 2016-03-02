#include <stdio.h>
#include <string.h>

main() {
  char input[2000];

  fgets(input, sizeof(input), stdin);
  int i = 0;
  int j = 0;
  int match = 0;
  for (i=0; i < strlen(input); i++) {
    // printf("%d\n", i);
    for (j=0;j < strlen(input);j++) {
      // printf("J is: %c\n", input[j]);
      // printf("I is: %c\n", input[i]);
      if (input[j] == input[i] && i != j) {
        // printf("Matching\n");
        match = 1;
        break;
      }
    }

    if (match == 1) {
      if (i == strlen(input)-1) {
        printf("%d", i);
      } else {
        printf("%d,", i);
      }
    }
    match = 0;
  }
}