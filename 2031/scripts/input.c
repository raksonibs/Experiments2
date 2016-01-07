#include <stdio.h>

main() {
  int c;

  c = getchar();
  while (c != EOF) {
    putchar(c);
    c = getchar();
  }

  // while ((cc = getchar()) != EOF)
      // putchar(c);
}