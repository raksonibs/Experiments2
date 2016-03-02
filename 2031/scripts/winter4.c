#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main() {
  FILE *fp;

  char line[200];

  int read;

  fp = fopen("grades.txt", "r");

  float class_avg = 0;
  float num_students = 0;

  struct student {
    char first_name[20];
    char last_name[20];
    char email_address[200];
    float test_1;
    float test_2;
    float test_3;
  };

  char * pch;

  struct student *students;

  students = (struct student*)malloc(5*sizeof(struct student));
  int i = 0;
  int internal_count = 0;

  float test_score;
  while (fgets(line, sizeof line, fp) != NULL) {
    if (i > 0) {
      pch = strtok(line, " ");

      while (pch != NULL) {
        if (internal_count == 0) {
          strcpy(students[i].first_name, pch);
        } else if (internal_count == 1) {
          strcpy(students[i].last_name, pch);
        } else if (internal_count == 2) {
          strcpy(students[i].email_address, pch);
        } else if (internal_count == 3) {
          test_score = atof(pch);
          students[i].test_1 = test_score;
        }

        internal_count++;
        pch = strtok(NULL, " ");
      }
      internal_count = 0;
      printf("%s\n", students[i].first_name);
      printf("%s\n", students[i].last_name);
      printf("%s\n", students[i].email_address);
      printf("%f\n", students[i].test_1);
    }
    i++;


  }
}