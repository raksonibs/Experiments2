#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  /* code */
  int width;
  int height;
  char * character;

  char entire_string[200];

  char * pch;

  // fgets(entire_string, 100, stdin);
  fgets(entire_string, sizeof(entire_string), stdin);

  printf("\nOver here\n");
  printf("%s\n", entire_string);
  
  pch = strtok(entire_string, " \n");
  int count = 0;

  while (pch != NULL)
  {
    printf ("%s\n",pch);
    if (count == 0) {
      printf("setting width\n");
      width = atoi(pch);
    } else if (count == 1) {
      printf("setting height\n");
      height = atoi(pch);
    } else {
      printf("setting char\n");
      character = pch;
    }
    pch = strtok (NULL, " \n");

    count++;
  }

  printf("%d\n", width);
  printf("%d\n", height);
  printf("%s\n", character);

  printf("Over fear\n");

  for (int i = 0; i <= width; i++) {
    printf("%s", character);
  }
  printf("\n");

  int min_height = height - 2;

  for (int j = 0; j <= min_height; j++) {
    for (int q = 0; q <= width; q++) {
      if (q == 0 || q == width) {
        printf("%s", character);
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

  for (int i = 0; i <= width; i++) {
    printf("%s", character);
  }

  printf("\n");




  return 0;
}