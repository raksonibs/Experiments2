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
        } else if (internal_count == 4) {
          test_score = atof(pch);
          students[i].test_2 = test_score;
        } else if (internal_count == 5) {
          test_score = atof(pch);
          students[i].test_3 = test_score;
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

  printf("please output a command!\n");
  char input[2000];

  char c;
  int j =0;
  int test_number = 0;
  char first_arg[4];
  char second_arg[200];
  scanf("%s %s", first_arg, second_arg);
  printf("Searching now!\n");
  if (first_arg[0] == 'T') {
    // turn char into c
    test_number = first_arg[1] - '0';

    for (j=0; j < sizeof(students); j++) {
      if (strcmp(students[j].last_name, second_arg) == 0) {
        if (test_number == 1) {
          printf("First test score %f\n", students[j].test_1);
        } else if (test_number == 2) {
          printf("First test score %f\n", students[j].test_2);
        } else if (test_number == 3) {
          printf("First test score %f\n", students[j].test_3);
        }
      }
    }
  } else if (first_arg[0] == 'A') {
    // average for student, pretty easy find last name get all scores
  } else {
    // class average for certain test. Pretty easy, loop through all and get test
  }

  // while ( (c = getchar()) != EOF ) {
  //   if (c == '\n') {
  //     printf("Full command: %s", input);

  //     pch = strtok(input, " ");

  //     while (pch != NULL) {
  //       if (pch.getchar(0) == "T") {
  //         test_number = atoi(pch.getchar(1));


  //       }
  //     }
  //     j = 0;
  //   }
  //   printf("%c\n", c);
  //   input[j] = c;
  //   j++;

  // }
  
}