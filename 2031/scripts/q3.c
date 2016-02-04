#include <stdio.h>
#include <string.h>

   /* count digits, white space, others */
 main()
 {
     int c, i, nwhite, nother;
     int ndigit[10];
     char * ch;

     char * total = "";

     int totalArr[200];
     int count;

     char * str[200][2];

     strcpy(str[0], "");

     nwhite = nother = 0;
     for (i = 0; i < 10; ++i) {
        ndigit[i] = 0;
     }


     while ((c = ch = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
          ndigit[c-'0']++;

          if (ndigit[c-'0'] == 1) {
            printf("This once: %c\n", c);
            printf("%s\n", ch);
            strcat(str, ch);
            printf("worked!\n");
          }
        }
     }

     printf("%s", str);

      // for (i = 0; i < 10; ++i)
      //      printf(" %d", ndigit[i]);

    // for (i = 0; i < sizeof(totalArr); ++i) {
    //   printf("%d", totalArr / 10);
    // }
         
 }