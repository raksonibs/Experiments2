#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() {
 
 char buffer[50];
 FILE *stream;
 stream = fopen("input_1.txt" , "rb");
 char * pch;
 const char *a[2];
 int max_points = 0;
 int longest_wins = 0;
 char team_name[31];
 int count;
 int number_of_games_won;
 int number_of_games_lost;
 int number_of_games_tied;
 int streak;
 while (fgets(buffer, sizeof buffer, stream) != NULL)
 {
   // process buffer
  count = 0;
  printf(buffer);
  
  pch = strtok (buffer," ,.-");
  if (count == 0)
      strcpy(team_name, pch);
  while (pch != NULL)
  {
    if (count == 1)
      number_of_games_won = atoi (pch);
    else if (count == 2)
      number_of_games_lost = atoi (pch);
    else if (count == 3)
      number_of_games_tied = atoi (pch);
    else
      streak = atoi (pch);
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-");
    count ++;
  }
  printf("Team name %s\n", team_name);
  printf("Games won %i\n", number_of_games_won);
  printf("Games tied %i\n", number_of_games_tied);
  printf("Games lost %i\n", number_of_games_lost);
  printf("Streak %i\n", streak);
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