#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() {
 
 char buffer[50];
 FILE *stream;
 stream = fopen("input_1.txt" , "rb");
 char * pch;
 while (fgets(buffer, sizeof buffer, stream) != NULL)
 {
   // process buffer
  printf(buffer);
  pch = strtok (buffer," ,.-");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-");
  }
  printf("File not done\n");
 }
 if (feof(stream))
 {
   // hit end of file
  printf("File done\n");
 }
 else
 {
   // some other error interrupted the read
  printf("File error\n");
 }

 printf("Out of loop");

 return 0;
}