#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() {
  int num;
  int nums[1000];

  scanf("%d", &num);

  int i = 0;
  int j = 0;
  int k =0;

  // if num is even i = i, esle i = 0

  if (num%2 == 0) {
    i = 0;
  } else {
    i = 1;
  }
  int numSpaces = 0;
  //could format strings
  for(i; i <= num; i = i+2) {
    numSpaces = (num -i) /2;
    for (k=0; k < numSpaces; k++) {
      printf(" ");
    }
    for (j=0; j< i;j++)  {
      printf("*");
    }
   
    printf("\n");
  }

}