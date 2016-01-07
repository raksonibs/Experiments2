#include <stdio.h>

main() {
  // because of amiguity in question first will do an array with a negative number and then input
  // part 1
  int numbers[] = {1,2,3,4,-3,5};
  int size = sizeof(numbers);
  int sum = 0;

  for (int j = 0; j<size; j++) {
    int currentNum = numbers[j];
    if (currentNum > 0) {
      sum = sum + currentNum;
    } else {
      break;
    }
  }
  char string[15];
  sprintf(string, "%d", sum);

  printf("%-10s", string);
}