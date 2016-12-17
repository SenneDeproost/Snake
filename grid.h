#ifndef GRID_H_
#define GRID_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Stelt de status van een vakje voor: bedekt, onthuld of afgevlagd.
 */
enum State {
	COVERED,
	UNCOVERED,
	FLAGGED
};

/*
 * Stelt een vakje voor: elk vakje heeft een status 'state' (bedekt, onthuld of afgevlagd),
 * een integer 'is_mine' die aangeeft of het vakje een mijn bevat of niet (de intiger is gelijk aan 1 indien ja, 0 indien nee)
 * en een integer 'neighbouring_mines' die aangeeft hoeveel van max. 8 naburige vakjes een mijn bevatten.
 */
struct Cell {
	enum State state;
	int neighbouring_mines;
	int is_mine;
};


/*
 * De functie om de tweedimensionale array die het veld zal voorstellen aan te maken.
 * De functie neemt twee integers als argument: grid_width stelt de breedte van het veld voor
 * (t.t.z. het max x-coordinaat + 1), grid_height de hoogte (t.t.z. het max y-coordinaat + 1).
 */
struct Cell ***allocate_grid(int grid_width, int grid_height);



/*
 * Initialiseert het veld: maakt het veld aan, plaatst mijnen op random posities
 * en zorgt er voor dat de 'neighbouring_mines' waarde voor elk vakje juist staat.
 */
void initialize_grid(int grid_width, int grid_height);

/*
 * Geeft een pointer terug naar de Cell die zich bevindt op positie (x,y) in het veld.
 */
struct Cell *get_cell(int x, int y);


#endif /* GRID_H_ */
