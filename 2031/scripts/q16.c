#include <stdio.h>
#include <string.h>

int main() {
  char input[200];
  int totalPoints = 0;

  int points = 0;
  int second_num = 0;

  fgets(input, sizeof(input), stdin);

  for (int i=0; i < strlen(input); i++) {

    points = 0;

    printf("current letter: %c\n", input[i]);
    printf("next letter: %c\n", input[i + 1]);
    if (second_num == 0 ){
      printf("using second number\n");
      if (input[i] == 'I' && input[i + 1] == 'V') {
        points = 4;
        second_num = 1;
      } 

      if (input[i] == 'I' && input[i + 1] == 'X') {
        points = 9;
        second_num = 1;
      }

      if (input[i] == 'X' && input[i + 1] == 'L') {
        points = 40;
        second_num = 1;
      }

      if (input[i] == 'X' && input[i + 1] == 'C') {
        points = 90;
        second_num = 1;
      }

      if (input[i] == 'C' && input[i + 1] == 'D') {
        points = 400;
        second_num = 1;
      }

      if (input[i] == 'C' && input[i + 1] == 'M') {
        points  = 900;
        second_num = 1;
      }
    }
    printf("points: %d\n", points);
    printf("Should see this twice if points 0\n");

    if (points == 0) {
      printf("resetting second number\n");
      if (second_num != 1) {
        if (input[i] == 'I') {
          points = 1;
        } else if (input[i] == 'V') {
          points = 5;
        } else if (input[i] == 'X') {
          points = 10;
        } else if (input[i] == 'L') {
          points = 50;
        } else if (input[i] == 'C') {
          points = 100;
        } else if (input[i] == 'D') {
          points = 500;
        } else if (input[i] == 'M') {
          points = 1000;
        }
      }

      second_num = 0;

    }

    totalPoints += points;
  }

  printf("%d", totalPoints);

  return 0;
}