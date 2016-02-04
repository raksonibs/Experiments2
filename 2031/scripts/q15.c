#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  FILE *file;
  file = fopen("election.txt", "rb");
  char line[200];

  int pointsA = 0;
  int pointsB = 0;
  int pointsC = 0;
  int pointsD = 0;
  int totalVotes = 0;

  int points = 0;

  char* pch;

  int count = 0;
  int internal_count = 0;
  int max = 0;
  char winner[2];

  while (fgets(line, sizeof line, file) != NULL) {
    if (count >= 2) {

      printf("%s", line);
      pch = strtok(line, " ");
      internal_count = 0;
      while (pch != NULL) {
        if (internal_count == 1) {
          points = atoi(pch);
          totalVotes += points;
          pointsA += points;
          if (pointsA > max) {
            strcpy(winner,"A");
            max = pointsA;
          }
        } else if (internal_count == 2) {
          points = atoi(pch);
          totalVotes += points;
          pointsB += points;
          if (pointsB > max) {
            strcpy(winner,"B");
            max = pointsB;
          }
        } else if (internal_count == 3) {
          points = atoi(pch);
          totalVotes += points;
          pointsC += points;
          if (pointsC > max) {
            strcpy(winner,"C");
            max = pointsC;
          }
        } else if (internal_count == 4) {
          points = atoi(pch);
          totalVotes += points;
          pointsD += points;
          if (pointsD > max) {
            strcpy(winner,"D");
            max = pointsD;
          }
        }
        printf("%s\n", pch);
        pch = strtok(NULL, " ");
        internal_count ++;
      }

      printf("\n");
    }

    count++;
  }  

  printf("Winner %s\n", winner);
  printf("Total Votes %d\n", totalVotes);
  printf("Max Votes %d\n", max);
  printf("Percent: %f", ((double)max/totalVotes) * 100);

  return 0;
}