#ifndef HIGHSCORE_H_
#define HIGHSCORE_H_

#include <stdio.h>

typedef struct {
  char name[50];
  int score;
}Player;

void addToScoreboard(int score);

#endif /* HIGHSCORE_H_ */
