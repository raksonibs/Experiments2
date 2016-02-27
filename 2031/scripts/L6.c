#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(void) {

  int arr [30][30];
  int numRows;
  int numCols;
  int numGenerations;
  int i = 0;
  int j = 0;

  printf("Put the number of rows and columns\n");
  scanf("%d %d", &numRows, &numCols);
  printf("Number of rows %d and number of colums %d\n", numRows, numCols);
  printf("Put number of generations\n");
  scanf("%d", &numGenerations);
  printf("number of generations %d\n", numGenerations);
  int numPossCols = numCols * 20;
  char rowCurrent[60];
  char rowsAll[5000];

  int currentRow = 0;
  int currentCol = 0;
  int currentString;

  // then receives r lines with c number of integers
  // how would this come in during the test?
  // with a one or a zero
  printf("Input rows now\n");

  // fgets(rowsAll, sizeof(rowsAll), stdin);

  while (scanf("%s", rowsAll) != EOF) {
    printf("scanning\n");
    printf("Current rowsAll %s\n", rowsAll);
    arr[currentRow][currentCol] = atoi(rowsAll);
    currentCol += 1;

    if (currentCol == numCols) {
      printf(" Increasing current row\n");
      currentCol = 0;
      currentRow += 1;
    }

    // if (strcmp(rowsAll, " ") == 0 || strcmp(rowsAll, "") == 0 || strcmp(rowsAll, "\n") == 0) {      
    // }
  }

  printf("Done Scanning, now outputting arr\n");



  for (i=0; i<numRows;i++) {
    
    for (j=0; j<numCols;j++) {
      printf("%d ", arr[i][j]);
    }

    printf("\n");
  }

   
  
}
