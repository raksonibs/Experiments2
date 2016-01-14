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
  int sum_1;
  int sum_2;
  char team_1; 
  char team_2; 
  int tot;
  return 0;
}