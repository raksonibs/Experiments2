#include <stdio.h>
#include <string.h>

int getline(char line[]);

int main() {

  char line[2000];

  char currentFinal[10000] = "";
  int len;

  while ((len = getline(line)) > 0) {
    // if (stringmatch(line, match)) {
      strcat(currentFinal, line);
    // }
  }

  printf("%s", currentFinal);

  return 0;
}

int getline(char s[])
{
    int c, i;
    for (i=0; i < (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}