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
  FILE *scoreboardFile = fopen("scoreboard.txt", "r+");

  char name[50];

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

//  rewind(scoreboardFile);
  //fscanf(scoreboardFile,"%s %i", name1, &score1);
  //printf("%s %i",name1, score1);
  fscanf(scoreboardFile,"%s %i %s %i %s %i",
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
//printf("%s\n", name3);

  /* Sorteer scores */

  Player p[SIZE]={
  {"A", 1},
  {"B", 2},
  {"C", 3},
  {"D", 4},
  {"E", 5},
  {"F", 6},
  {"G", 7},
  {"H", 8},
  {"I", 9},
  {"J", 10}

  //Player p[SIZE] = malloc(SIZE * sizeof(Player));
//  {name, score}
  };
  printf("%s\n", "*" );
  strncpy(p[1].name, name2, 50);
  p[1].score = score2;
  printf("%s\n", p[1].name);
  printf("%i\n", p[1].score);
  printf("%s\n", "*" );

strncpy(p[0].name, name1, 50);
p[0].score = score1;

strncpy(p[1].name, name2, 50);
p[1].score = score2;

strncpy(p[2].name, name3, 50);
p[2].score = score3;

strncpy(p[3].name, name4, 50);
p[3].score = score4;

strncpy(p[4].name, name5, 50);
p[4].score = score5;

strncpy(p[5].name, name6, 50);
p[5].score = score6;

strncpy(p[6].name, name7, 50);
p[6].score = score7;

strncpy(p[7].name, name8, 50);
p[7].score = score8;

strncpy(p[8].name, name9, 50);
p[8].score = score9;

strncpy(p[9].name, name10, 50);
p[9].score = score10;

//printf("//////////%s\n", score7);
//printf("//////////%s\n", p[6].score);
  Player p1[SIZE]={
  {"Abbey",187},
  {"Dane", 19},
  {"Christene", 190}
  /*{"Zack", 210},
  {"Mary", 208}*/};


  int i, j;
  int temp;
  int index[SIZE + 1];

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
/*printf("");
printf("///");
printf("%i\n", index[4]);
printf("---");*/
int g = index[1];
printf("//");
printf("%i\n", p[g].score);
/*
printf("///");*/

  printf("%s %i %s %i %s %i",
  p[index[0]].name, p[index[0]].score,
  p[index[1]].name, p[index[1]].score,
  p[index[2]].name, p[index[2]].score,
  p[index[3]].name, p[index[3]].score,
  p[index[4]].name, p[index[4]].score,
  p[index[5]].name, p[index[5]].score,
  p[index[6]].name, p[index[6]].score,
  p[index[7]].name, p[index[7]].score,
  p[index[8]].name, p[index[8]].score,
  p[index[9]].name, p[index[9]].score
);

  fclose(scoreboardFile);

}
