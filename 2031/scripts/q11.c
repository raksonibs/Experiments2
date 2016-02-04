#include <stdio.h>
#include <string.h>

int main() {
  char string[200];
  int arr[10];
  int zero = 0;
  int one = 0;
  int two = 0;
  int three = 0;
  int four = 0;
  int five = 0;
  int six = 0;
  int seven = 0;
  int eight = 0;
  int nine = 0;

  // for (int j = ; j < 10; j++) {
  //   arr[i] = 0;
  // }

  scanf("%s", string);

  for (int i=0; i < strlen(string); i++) {
    if (string[i] == '1' && one == 0) {
      one++;
      printf("%c", string[i]);
    } else if (string[i] == '2' && two == 0) {
      two++;
      printf("%c", string[i]);
    } else if (string[i] == '0' && zero == 0) {
      zero++;
      printf("%c", string[i]);
    } else if (string[i] == '3' && three == 0) {
      three++;
      printf("%c", string[i]);
    } else if (string[i] == '4' && four == 0) {
      four++;
      printf("%c", string[i]);
    } else if (string[i] == '5' && five == 0) {
      five++;
      printf("%c", string[i]);
    } else if (string[i] == '6' && six == 0) {
      six++;
      printf("%c", string[i]);
    } else if (string[i] == '7' && seven == 0) {
      seven++;
      printf("%c", string[i]);
    } else if (string[i] == '8' && eight == 0) {
      eight++;
      printf("%c", string[i]);
    } else if (string[i] == '9' && nine == 0) {
      nine++;
      printf("%c", string[i]);
    }
  }

  printf("\n");

  return 0;
}