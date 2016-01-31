#include <stdio.h>
#include <stdlib.h>
 
int main(void) {
  int i = 0;
  char* string[200];
  char line[21];
  char* c;
  bool match = false;
   
  FILE *file; 
  file = fopen("../../dictionary.txt", "r"); 
   
  while(fgets(line, sizeof line, file)!=NULL) {
    printf("%s", line);
    string[i]=line;
    printf("%s", string[i]);
    i++;
  }

  while ((c = getchar()) != EOF) {
    printf("Looking for %c\n", c);
    for (i = 0; i < 200; ++i)
    {
      printf("Looking at %s\n", string[i]);
      if (string[i] == c) {
        printf("match");
        match = true;
      }
    }

    if (match) {
      printf("Error: %s\n", c);
    } 
  }

  printf("%s\n", string[0]);
  printf("%s\n", string[1]);
  printf("%c\n", string[2]);

  fclose(file);
  return 0;
}
