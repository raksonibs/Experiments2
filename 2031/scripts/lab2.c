#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() {
 
 char buffer[50];
 FILE *stream;
 stream = fopen("input_1.txt" , "rb");
 char * pch;
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
 char streak_string[4];
 while (fgets(buffer, sizeof buffer, stream) != NULL)
 {   
  count = 0;  
  
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
      streak = atoi (pch);    
    pch = strtok (NULL, " ");
    count ++;
  }          

  number_games_played = number_of_games_won + number_of_games_lost + number_of_games_tied;  

  if (number_of_games_won > 0 && number_of_games_tied > 0 && number_of_games_lost > 0 && number_games_played < 99) {    

    teams_points = (3 * number_of_games_won) + number_of_games_tied;    
    if (streak > longest_wins) {
      longest_wins = streak;
    }

    if (teams_points > max_points) {
      max_points = teams_points;
    }

    if (streak > 0) {
      sprintf(streak_string, "+%d", streak);
    } else {
      sprintf(streak_string, "%d", streak);
    }

    printf("%s\t %d\t %s\n", team_name, teams_points, streak_string );
  } else {    
    if (number_of_games_won < 0 || number_of_games_tied < 0 || number_of_games_lost < 0) {
      printf("%s\tnegative number of games\n", team_name);
    }
    else {
      printf("%s\tgames played are more than 99\n", team_name);
    }
  }
  
 }
 if (feof(stream))
 {     
 }
 else
 {   
  printf("File error\n");
 }
 printf("The maximum points by any team is %5i\n", max_points);
 printf("The longest winning streak is %5i\n", longest_wins); 

 return 0;
}