#ifndef GAME_H_
#define GAME_H_

#include <stdio.h>
#include "SDL/SDL.h"

#include "grid.h"

int score;

void run_game(void);

// PAUSE

int pause;
void pause_game(void);

// COLLISION

void check_collision(void);

#endif /* GAME_H_ */
