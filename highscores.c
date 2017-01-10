  #include "highscores.h"
  #include "game.h"

#include <stdio.h>
#include <stdlib.h>

  #define SIZE 10

  // https://cboard.cprogramming.com/c-programming/135750-scoreboard-saved-txt-file.html

  void addToScoreboard(int n)
  {
    /*  FILE *scoreboardFile = fopen("scoreboard.txt", "a");
      char name[20];
      Player player;

      player.score = n;

      printf("\n\nGeef naam: ");
      scanf("%s", name);
      strcpy(player.name, name);

      fprintf(scoreboardFile, "%s %i\n",player.name, player.score);
      fclose(scoreboardFile);

      printf("Score: %i\n", score); */
      readtest();

  }


void readtest(){

  FILE *scoreboardFile = fopen("scoreboard.txt", "w+");

  char name[50]

  char name1[50];
  int score1;

  char name2[50];
  int score2;

  char name3[50];
  int score3;

  char name4[50];
  int score4;

  char name5[50];
  int score5;

  char name6[50];
  int score6;

  char name7[50];
  int score7;

  char name8[50];
  int score8;

  char name9[50];
  int score9;

  char name10[50];
  int score10;


  /* Voer naam in */
    printf("\n\nGeef naam: ");
    scanf("%s", name);


/* Lees scores */

  rewind(scoreboardFile);
  fscanf(scoreboardFile,"%i",score1);
  fscanf(scoreboardFile,"%s %i %s %i %s %i %s %i %s %i %s %i %s %i %s %i %s %i %s %i ",
  name1, &score1,
  name2, &score2,
  name3, &score3,
  name4, &score4,
  name5, &score5,
  name6, &score6,
  name7, &score7,
  name8, &score8,
  name9, &score9,
  name10, &score10
);

  /* Sorteer scores */

  Player p[SIZE + 1]={
  {name1, score1},
  {name2, score2},
  {name3, score3},
  {name4, score4},
  {name5, score5},
  {name6, score6},
  {name7, score7},
  {name8, score8},
  {name9, score9},
  {name10, score10},
  {name, score}
  };


  int i, j, temp;
  int index[SIZE + 1];


  printf("\n\n");

  for(i=0;i<SIZE;i++)  //simple initialization for the index array
    index[i] = i;

  //simple substitution sort, using the index
  for(i=0;i<SIZE;i++) {
    for(j=i+1;j<SIZE + 1;j++) {
      if(p[index[i]].score < p[index[j]].score) { //compare thru the index
        temp=index[i];    //and swap only the indices
        index[i] = index[j];
        index[j] = temp;
      }
    }
  }

  fscanf(scoreboardFile,"%s %i %s %i %s %i %s %i %s %i %s %i %s %i %s %i %s %i %s %i ",
  p[0].name, p[0].score,
  p[1].name, p[1].score,
  p[2].name, p[2].score,
  p[3].name, p[3].score,
  p[4].name, p[4].score,
  p[5].name, p[5].score,
  p[6].name, p[6].score,
  p[7].name, p[7].score,
  p[8].name, p[8].score,
  p[9].name, p[9].score
);


  fclose(scoreboardFile);

}



















void test(){

FILE *scoreboardFile = fopen("scoreboard.txt", "r");
char c[1000];
char e[1000];

fscanf(scoreboardFile,"%[^' ' ]", c);

printf("Data from the file:\n%s", c);

fscanf(scoreboardFile,"%[^' ' ]", e);

printf("Data from the file:\n%s", e);

fclose(scoreboardFile);

}





//https://cboard.cprogramming.com/c-programming/135750-scoreboard-saved-txt-file.html

/*  void addToScoreboard2(int n){
    sort_scores();

}

int sort_scores() {
  FILE *scoreboardFile = fopen("scoreboard.txt", "wb");

  int i, j, temp;
  int index[SIZE];


  printf("\n\n");

  for(i=0;i<SIZE;i++)  //simple initialization for the index array
    index[i] = i;

  //simple substitution sort, using the index
  for(i=0;i<SIZE-1;i++) {
    for(j=i+1;j<SIZE;j++) {
      if(p[index[i]].score < p[index[j]].score) { //compare thru the index
        temp=index[i];    //and swap only the indices
        index[i] = index[j];
        index[j] = temp;
      }
    }
  }

  //fclose(scoreboardFile);

  //show the sorted order of the data:

  for(i=0;i<SIZE;i++) {
    fprintf(scoreboardFile, "%s  %d  \n", p[index[i]].name,p[index[i]].score);
  }
  printf("\n\n\t\t\t     press enter when ready");
  (void) getchar();
  fclose(scoreboardFile);
  test();
  return 0;
}
*/

int kleinetest() {
  int i, j, temp;
  int index[SIZE];
  Player p[SIZE]={
  {"Abbey",187},
  {"Dane", 19},
  {"Christene", 190},
  {"Zack", 210},
  {"Mary", 208}};

  printf("\n\n");

  for(i=0;i<SIZE;i++)  //simple initialization for the index array
    index[i] = i;

  //simple substitution sort, using the index
  for(i=0;i<SIZE-1;i++) {
    for(j=i+1;j<SIZE;j++) {
      if(p[index[i]].score < p[index[j]].score) { //compare thru the index
        temp=index[i];    //and swap only the indices
        index[i] = index[j];
        index[j] = temp;
      }
    }
  }
  //show the order of the actual data:
  printf("Players in unsorted order: \n\n");
  for(i=0;i<SIZE;i++) {
    printf("%20s  %3d\n", p[i].name,p[i].score);
  }
  //show the sorted order of the data:
  printf("\nPlayers sorted by scores: \n\n");
  for(i=0;i<SIZE;i++) {
    printf("%20s  %3d\n", p[index[i]].name,p[index[i]].score);
  }
  printf("\n\n\t\t\t     press enter when ready");
  (void) getchar();
  return 0;
}
