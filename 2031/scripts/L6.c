#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(void) {

  int arr [30][30];
  int tmpArr [30][30];
  int numRows;
  int numCols;
  int numGenerations;
  int i = 0;
  int j = 0;
  int z = 0;

  // printf("Put the number of rows and columns\n");
  scanf("%d %d", &numRows, &numCols);
  // printf("Number of rows %d and number of colums %d\n", numRows, numCols);
  // printf("Put number of generations\n");
  scanf("%d", &numGenerations);
  // printf("number of generations %d\n", numGenerations);
  int numPossCols = numCols * 20;
  char rowCurrent[60];
  char rowsAll[5000];

  int currentRow = 0;
  int currentCol = 0;
  int currentString;

  int numNeighbours = 0;

  // then receives r lines with c number of integers
  // how would this come in during the test?
  // with a one or a zero
  // printf("Input rows now\n");

  // fgets(rowsAll, sizeof(rowsAll), stdin);

  while (scanf("%s", rowsAll) != EOF) {
    // printf("scanning\n");
    // printf("Current rowsAll %s\n", rowsAll);
    arr[currentRow][currentCol] = atoi(rowsAll);
    currentCol += 1;

    if (currentCol == numCols) {
      // printf(" Increasing current row\n");
      currentCol = 0;
      currentRow += 1;
    }

    // if (strcmp(rowsAll, " ") == 0 || strcmp(rowsAll, "") == 0 || strcmp(rowsAll, "\n") == 0) {      
    // }
  }

  // printf("Done Scanning, now outputting arr\n");

  // rule block when iterating

  printf("\n");

  for (z=0; z < numGenerations; z++) {

    for (i=0; i<numRows;i++) {
    
      for (j=0; j<numCols;j++) {
         numNeighbours=0;
        // printf("Current: %d ", arr[i][j]);
        
          // if 1, check neighbours (horizontal, vertical, diagonal)
          // if two or three ones beside it, it is survives
          // if more than two or three ones around it, it dies
          // bottom center
          if (arr[i+1][j] == 1) {
            numNeighbours += 1; 
          }

          // bottom right
          if (arr[i+1][j+1] == 1) {
            numNeighbours += 1; 
          }
          // bottom left
          if (arr[i+1][j-1] == 1) {
            numNeighbours += 1; 
          }
          //right
          if (arr[i][j+1] == 1) {
            numNeighbours += 1; 
          }
          //left
          if (arr[i][j-1] == 1) {
            numNeighbours += 1; 
          }
          // top center
          if (arr[i-1][j] == 1) {
            numNeighbours += 1; 
          }

          // top left
          if (arr[i-1][j-1] == 1) {
            numNeighbours += 1; 
          }

          // top right
          if (arr[i-1][j+1] == 1) {
            numNeighbours += 1; 
          }

          if (arr[i][j] == 1) {
            if (numNeighbours == 3 || numNeighbours == 2) {
            // survives
               tmpArr[i][j] = 1;
            } else {
              // dies overpopulation
               tmpArr[i][j] = 0;
            }
          } else {
            if (numNeighbours == 3) {
            // recreates
               tmpArr[i][j] = 1;
            } else {
              // nothing cause dead
               tmpArr[i][j] = 0;
            }
          }



          
         

        // printf("Number of neibhours: %d ", numNeighbours);
        // printf("Changed: %d, ", arr[i][j]);
        // printf("%d ", arr[i][j]);
      }

      // rewrite current array


    }

    for (i=0; i<numRows;i++) {
    
      for (j=0; j<numCols;j++) {
        arr[i][j] = tmpArr[i][j];
        printf("%d ", arr[i][j]);
      }
      printf("\n");
    }


    printf("-----\n");
  }

  

   
  
}
