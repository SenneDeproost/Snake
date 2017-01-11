#ifndef HIGHSCORES_H_
#define HIGHSCORES_H_

#include <stdio.h>

typedef struct {
  char name[50];
  int score;
}Player;

void addToScoreboard(int score);

#endif /* HIGHSCORES_H_ */
