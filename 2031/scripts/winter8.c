#include <stdio.h>
#include <string.h>

main() {
  FILE * file;

  file = fopen("grades.txt", "r");

  char line[2000];
  int i = 0;

  struct student {
    char first_name[2000];
    char last_name[2000];
    char email[2000];
    float test_1;
  };

  struct student *students;

  char * pch;

  students = (struct student*)malloc(20000);

  printf("test\n");

  while(fgets(line, sizeof(line), file) != NULL) {
    if (i > 0) {
      
    }
    i++;
  }
}