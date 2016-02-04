#include <stdio.h>
#include <string.h>

int main() {
  char * input;
  int c = 0;
  scanf("%s", input);

  while( input[c] != '\0' ) {
    c++;
  }

  printf("%d", c);

  return 0;
}