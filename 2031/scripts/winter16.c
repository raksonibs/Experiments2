#include <string.h>
#include <stdio.h>
#include <stdlib.h>

main() {
  FILE * file;
  fopen("grades.txt", "r");

  char line[2000];
  struct student {

  };

  char * pch;
  struct student *students;
  internal_count = 0;
  students = (struct student*)malloc(20000);
  while (fgets(line, sizeof(line), file)) {
    pch = strtok(line, " ");
  }
}