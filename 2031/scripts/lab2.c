#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int prompt_and_read(const char *prompt, float *value)
{
    printf("%s", prompt);
    if (scanf("%f", value) != 1)
        return -1;
    return 0;
}

main() {
  float value;
  float sum = 0.0;
  int   num = 0;

  char *buffer = NULL;
  int read;
  unsigned int len;

  read = getline(&buffer, &len, stdin);
  if (-1 != read)
      puts(buffer);
  else
      printf("No line read...\n");
  printf("Size read: %d\n Len: %d\n", read, len);
  free(buffer);
  return 0;

  // while (prompt_and_read("\tNext number please.\n", &value) == 0)
  // {
  //     sum += value;
  //     num++;
  // }

  // if (num > 0)
  // {
  //     printf("You entered %d numbers\n", num);
  //     printf("Your sum     is %f\n", sum);
  //     printf("Your average is %f\n", sum / num);
  // }

  // return 0;
}