#ifndef GRID_H_
#define GRID_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "settings.h"


enum State {
	EMPTY,
	WALL,
	APPLE,
	CANDY,
	SNAKE
};

struct Cell {
	enum State state;
};

// APPLE

struct Point{
	int x;
	int y;
};

struct Point apple_point;

// CANDY

struct Point candy_point;
void initialize_candy(void);
void remove_candy(void);



// WALL

struct Wall_part *get_wall(int i);


struct Wall_part {
  int x;
  int y;

};


//struct Point walls[NR_OF_WALL_BLOCKS];
struct Wall_part **allocate_wall();


/*
 * De functie om de tweedimensionale array die het veld zal voorstellen aan te maken.
 * De functie neemt twee integers als argument: grid_width stelt de breedte van het veld voor
 * (t.t.z. het max x-coordinaat + 1), grid_height de hoogte (t.t.z. het max y-coordinaat + 1).
 */
struct Cell ***allocate_grid(int grid_width, int grid_height);

void initialize_grid(int grid_width, int grid_height);

/*
 * Geeft een pointer terug naar de Cell die zich bevindt op positie (x,y) in het veld.
 */
struct Cell *get_cell(int x, int y);



#endif /* GRID_H_ */
