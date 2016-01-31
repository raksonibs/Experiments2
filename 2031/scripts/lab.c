#include <stdio.h>

void main() {

  int i, sum = 0;

  while((scanf("%d", &i) > 0) ) {
    if (i < 0) {
      break;
    }

    sum += i;
  }

  printf("%10d\n", sum);

}

