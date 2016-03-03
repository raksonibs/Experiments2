#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main() {
  // assumption 1: read from file.
    // attempt 2, not read from file, but line by line?


  FILE * file;
  file = fopen("grades.txt", "r");

  char line[2000];
  int count = -1;
  int internal_count = 0;
  char * pch;

  struct student {
    char first_name[200];
    char last_name[200];
    char email[200];
    float test_1;
    float test_2;
    float test_3;
  };

  struct student *students;

  float test_score;

  students = (struct student*)malloc(2000);

  while (fgets(line, sizeof(line), file) != NULL) {
    if (count > -1) {
      pch = strtok(line, " ");

      while (pch != NULL) {
        printf("PCH: %s\n", pch);
        if (internal_count == 0) {
          strcpy(students[count].first_name, pch);
        } else if (internal_count == 1) {
          strcpy(students[count].last_name, pch);
        } else if (internal_count == 2) {
          strcpy(students[count].email, pch);
        } else if (internal_count == 3) {
          test_score = atof(pch);
          // printf("Test Score: %d\n", test_score);
          students[count].test_1 = test_score;
        } else if (internal_count == 4) {
          test_score = atof(pch);
          students[count].test_2 = test_score;
        } else if (internal_count == 5) {
          test_score = atof(pch);
          students[count].test_3 = test_score;
        }

        internal_count++;
        pch = strtok(NULL, " ");
      }

      internal_count = 0;
    }

    printf("%s\n", students[count].first_name);
    printf("%s\n", students[count].last_name);
    printf("%s\n", students[count].email);
    printf("%f\n", students[count].test_1);
    printf("%f\n", students[count].test_2);
    printf("%f\n", students[count].test_3);

    count++;
  }

  char test_number;

  char input[2000];

  char first_argument[200];

  char second_argument[200];
  // make array of arguments
  printf("Input a command: \n");

  int j=0;
  float avg_tests;

  float totalTests;
  float totalTests1;
  float totalTests2;
  float totalTests3;

  while(scanf("%s %s", first_argument, second_argument) != EOF) {
    printf("First argument is %s\n", first_argument);
    if (first_argument[0] == 'T') {
      //test score for student
      test_number = first_argument[1];
      for (j=0; j<=count ;j++) {
        if (strcmp(students[j].last_name, second_argument) == 0) {
          if (test_number == '1') {
            printf("Test number %c for %s with a score of %f\n", test_number, second_argument, students[j].test_1);
          } else if (test_number == '2') {
            printf("Test number %c for %s with a score of %f\n", test_number, second_argument, students[j].test_2);
          } else {
            printf("Test number %c for %s with a score of %f\n", test_number, second_argument, students[j].test_3);
          }
        }
      }
      
    } else if (first_argument[0] == 'A') {
      for (j=0; j<=count ;j++) {
        if (strcmp(students[j].last_name, second_argument) == 0) {
          avg_tests = (students[j].test_1 + students[j].test_2 + students[j].test_3)/3.0;
          printf("Average tests for %s with a score of %.2f\n", second_argument, avg_tests);
        }
      }
      // avg of three tests for student
    } else if (first_argument[0] == 'C' && strcmp(second_argument,"\n") != 0) {
      //class average for tests
      test_number = first_argument[1];
      for (j=0; j<=count ;j++) {
        if (test_number == '1') {
          totalTests += students[j].test_1;
        } else if (test_number == '2') {
          totalTests += students[j].test_2;
        } else {
          totalTests += students[j].test_3;
        }
      }

      printf("AVG for test %c at %.2f\n", first_argument[1], totalTests/count);
    } else if (strcmp(second_argument,"\n") == 0) {
      totalTests1 += students[j].test_1;
      totalTests2 += students[j].test_2;
      totalTests3 += students[j].test_3;

      printf("AVG 1: %.2f, AVG 2: %.2f, AVG 3: %2.f", totalTests1/count, totalTests2/count, totalTests3/count);
    }
  }



  printf("Done\n");
}