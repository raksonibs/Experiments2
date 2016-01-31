#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(void) {
  int i = 0;
  char* words[200][21];
  char line[21];
  char* pch;
  char str1[21];
  int match = 0;
   
  FILE *file; 
  file = fopen("../../dictionary.txt", "r");
   
  while(fgets(line, sizeof line, file) != NULL) {
    pch = strtok (line, "\n");    
    strcpy(words[i], pch);    
    i++;
  }            

  while (scanf("%s", &str1) != EOF ) {  
    pch = strtok(str1, " ,\.\s\n\t");    
    while (pch != NULL)
    {
      match = 0;
      // lookForMatch(pch, str1, match, words);
      for (i = 0; i < 200; ++i)
      {
        if (strcmp(words[i], str1) == 0) {        
          match = 1;
          break;        
        }
      }

      if (match == 0) {
        printf("Error: %s\n", str1);
        break;
      } else {
        break;
      }
    }  
  }   

  fclose(file);
  return 0;
}
