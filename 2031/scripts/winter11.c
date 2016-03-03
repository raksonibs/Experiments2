#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main() {
  char numCols[2];
  char numRows[2];
  char val[2];

  int numColsInt;
  int numRowsInt;

  scanf("%s %s %s", numCols, numRows, val);
  // printf("%s %s %s", numCols, numRows, val);
  numColsInt = atoi(numCols);
  numRowsInt = atoi(numRows);
  int i;
  int j;
  for (i = 0; i < numRowsInt; i++) {
    for (j = 0; j < numColsInt; j++) {
      if (i == 0 || i == numRowsInt - 1 || j == 0 || j == numColsInt - 1) {
        printf("%s", val);  
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}
