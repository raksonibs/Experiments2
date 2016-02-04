#include <stdio.h>
#include <string.h>

int main() {
  char * str;
  fgets(str, sizeof(str), stdin);

  char *c = str;

  for(int i = 0; i< sizeof(str); i++) {
    printf("%c\n", str[i]);
  }
  
  return 0;
}