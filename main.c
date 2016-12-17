/****************************************************************
 *                          MINESWEEPER                         *
 *                      By Senne Deproost                       *
 *        senne.deproost@vub.be - sennedeproost@hotmail.com     *
 ****************************************************************/

#include <stdlib.h>
#include <time.h>

#include "game.h"
#include "grid.h"
#include "GUI.h"
#include "main.h"


/*
 * Initialiseert eerst het veld, via de functie initialize_grid uit grid.c, en roept daarna de functie
 * run_game uit game.c aan om het spel effectief te starten.
 */
int main(int argc, char *argv[]) { // Volgorde van de argumenten: W, H, nr of mines

	// Controle of aantal parameters klopt.
	if (argc != 4){
		printf ("Ongeldig aantal parameters.\n");
	}
	else{

	/*
	 * Naar deze statement hoef je nu niet te kijken.
	 */
	srand(time(NULL));


// http://stackoverflow.com/questions/12585398/how-to-pass-arguments-from-terminal-to-a-function
	WIDTH = atoi(argv[1]);
	HEIGHT = atoi(argv[2]);
	NR_OF_MINES = atoi(argv[3]);

	/*
	 * Initialiseert het speelveld met als dimensies de breedte en de hoogte die gedefinieerd zijn in settings.h,
	 * en met het aantal mijnen gelijk aan NR_OF_MINES uit settings.h.
	 */

	initialize_grid(WIDTH, HEIGHT, NR_OF_MINES);

	print_grid(); // Print grid voor de eerste keer

	initialize_gui(WIDTH, HEIGHT);

	run_game();
 }
}
