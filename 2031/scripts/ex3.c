#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  
  char input[2000];
  int c;
  int i = 0;

  char line[2000];

  while( (c = getchar()) != EOF) {
    if (c == '\n') {
      line[i] = '\0';
      break;
    } else {
      printf("%c\n", c);
      line[i] = c;
    }
    i++;
  }  

  printf("line is %s\n", line);

  return 0;
}