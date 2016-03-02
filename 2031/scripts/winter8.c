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

  int internal_count = 0;

  while(fgets(line, sizeof(line), file) != NULL) {
    // wants to reallocate memory after five, would just use realloc on the table!
    if (i > 0) {
      // can i use scanf or some strcpy here to grab them all in one go?
      pch = strtok(line, " ");
      while (pch != NULL) {
        if (internal_count == 0) {
          strcpy(students[i].first_name, pch);          
        }
        internal_count++;
        pch = strtok(NULL, " ");
      } 

      internal_count = 0;     
    }

    i++;
  }
  int k=0;
  for (k=0; k < 12;k++) {
    printf("%s\n", students[k].first_name);
  }
}