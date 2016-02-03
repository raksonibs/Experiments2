#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  /* code */
  int width;
  int height;
  char character;

  char entire_string[6];

  char * pch;

  scanf("%s", entire_string);

  printf("Over here");
  
  pch = strtok(entire_string, " ");

  printf("Over now here");

  width = atoi(pch[0]);

  printf("Over hhere baby");
  height = atoi(pch[1]);
  printf("Over laadere");
  character = pch[2];

  printf("Over fear");

  for (int i = 0; i <= width; i++) {
    printf("%s", character);
  }

  int min_height = height - 2;

  for (int j = 0; j <= min_height; j++) {
    for (int q = 0; q <= width; q++) {
      if (q == 0 || q == width) {
        printf("%s", character);
      } 
    }
  }

  printf("\n");

  for (int i = 0; i <= width; i++) {
    printf("%s", character);
  }

  printf("\n");




  return 0;
}