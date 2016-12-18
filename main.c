/****************************************************************
 *                            SNAKE                             *
 *                      By Senne Deproost                       *
 *        senne.deproost@vub.be - sennedeproost@hotmail.com     *
 ****************************************************************/

#include <stdlib.h>
#include <time.h>

#include "game.h"
#include "grid.h"
#include "GUI.h"
#include "main.h"
#include "settings.h"
#include "snake.h"


int main() {


	srand(time(NULL));

// INITIALIZATION
	initialize_grid(GRID_WIDTH, GRID_HEIGHT);
  initialize_snake(MAX_SNAKE_LENGTH);
	initialize_gui(GRID_WIDTH, GRID_HEIGHT);

// RUN GAME LOGIC
  run_game();
 }
