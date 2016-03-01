#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  
  char input[2000];
  int c;
  int i = 0;

  char line[2000];

  char * pch;
  int j = 0;

  while( (c = getchar()) != EOF) {
    if (c == '\n') {
      // if match
      printf("line is %s\n", line);
      // proper match would loop through each char of line and see if works
      //  would break match up into how many words
      for (j=0; j < 2000 ;j++) {
        if (line[j] == 'c' && line[j + 1] == 'a' && line[j + 2] == 't') {
          printf("match: %s", line);
          break;
        }
      }
      if (strcmp(line, "cat") == 0) {
        printf("match");
      }

      line[i] = '\0';
      i = -1;

    } else {
      printf("%c\n", c);
      line[i] = c;
    }
    i++;
  }  

  printf("line is %s\n", line);

  return 0;
}