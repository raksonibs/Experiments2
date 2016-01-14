#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() {
 
 char buffer[50];
 FILE *stream;
 stream = fopen("input_2.txt" , "rb");
 char * pch;
 const char *a[2];
 int max_points = 0;
 int longest_wins = 0;
 char team_name[31];
 int count;
 int number_of_games_won;
 int number_of_games_lost;
 int number_of_games_tied;
 int teams_points;
 int streak;
 int number_games_played;
 while (fgets(buffer, sizeof buffer, stream) != NULL)
 {
   // process buffer
  count = 0;
  // printf(buffer);
  
  pch = strtok (buffer," ");
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
      // printf("%s\n", pch);
      streak = atoi (pch);
    // printf ("%s\n",pch);
    pch = strtok (NULL, " ");
    count ++;
  }
  printf("Team name %s\n", team_name);
  printf("Games won %i\n", number_of_games_won);
  printf("Games tied %i\n", number_of_games_tied);
  printf("Games lost %i\n", number_of_games_lost);
  printf("Streak %i\n", streak);

  number_games_played = number_of_games_won + number_of_games_lost + number_of_games_tied;
  printf("number_games_played %i\n", number_games_played);

  if (number_of_games_won > 0 && number_of_games_tied > 0 && number_of_games_lost > 0 && number_games_played < 99)

    teams_points = (3 * number_of_games_won) + number_of_games_tied;
    printf("teams_points %i\n", teams_points);
    if (streak > longest_wins)
      longest_wins = streak;

    if (teams_points > max_points)
      max_points = teams_points;
  else
    if (number_games_played > 99)
      printf("%s games played are more than 99\n", team_name);
    else
      printf("%s negative number of games\n", team_name);

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
 printf("The maximum points by any team is %i\n", max_points);
 printf("The longest winning streak is %i\n", longest_wins);
 printf("Out of loop");

 return 0;
}