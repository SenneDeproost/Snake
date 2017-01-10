#ifndef HIGHSCORE_H_
#define HIGHSCORE_H_

#include <stdio.h>

typedef struct {
  char name[20];
  int score;
}Player;

void addToScoreboard(int n);

#endif /* HIGHSCORE_H_ */
