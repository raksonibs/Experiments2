#include <stdio.h>

int main() {
  int sum = 0;
  for (int i = 0; i < 6;i++) {
    for (int j = 0; j < 6; j++) {
      printf(" i is %d\n", i);
      printf(" J is %d\n", j);
      sum = sum + (i * j);
      printf("%d\n", sum);
    }
  }

  return 0;
}