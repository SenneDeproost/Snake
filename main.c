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


/*
 * Initialiseert eerst het veld, via de functie initialize_grid uit grid.c, en roept daarna de functie
 * run_game uit game.c aan om het spel effectief te starten.
 */
int main() { // Volgorde van de argumenten: W, H, nr of mines


	srand(time(NULL));


	/*
	 * Initialiseert het speelveld met als dimensies de breedte en de hoogte die gedefinieerd zijn in settings.h,
	 * en met het aantal mijnen gelijk aan NR_OF_MINES uit settings.h.
	 */

	initialize_grid(GRID_WIDTH, GRID_HEIGHT);


	initialize_gui(GRID_WIDTH, GRID_HEIGHT);

	run_game();
 }
