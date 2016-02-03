#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  int num_stars;
  scanf("%d", &num_stars);
  char * str;
  int space;
  for(int i = 1; i <= num_stars; i = i + 2) {
    space = num_stars - i;
    for (int q = 0; q <= space/2; q++ ) {
      printf(" ");
    }
    for (int j = 1; j <= i; j++) {
      printf("*");
    }

    for (int z = 0; z <= space/2; z++ ) {
      printf(" ");
    }

    printf("\n");
  }
  return 0;
}