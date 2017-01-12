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


int main(int argc, char *argv[]) {


	srand(time(NULL));

	// INPUT
	if (argc != 3){
		printf ("Ongeldig aantal parameters.\n");
	}
	else{
		// BRON: http://stackoverflow.com/questions/12585398/how-to-pass-arguments-from-terminal-to-a-function
			GRID_WIDTH = atoi(argv[1]);
			GRID_HEIGHT = atoi(argv[2]);

	srand(time(NULL));



// INITIALIZATION
	initialize_grid(GRID_WIDTH, GRID_HEIGHT);
  initialize_snake((GRID_WIDTH / 2), (GRID_HEIGHT / 2));
	initialize_gui(GRID_WIDTH, GRID_HEIGHT);

// RUN GAME LOGIC
  run_game();
 }
 }
