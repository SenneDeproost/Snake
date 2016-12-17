#include "snake.h"

/*
 * Stelt het twee-dimensionale veld voor. grid is een tweedimensionale array van pointers naar Cellen.
 * Jullie moeten deze variabele zelf niet gebruiken: in de plaats kan je gebruik maken van de functie get_cell hieronder.
 */
static struct Cell*** grid;

/*
 * Geeft een pointer terug naar de Cell die zich bevindt op positie (x,y) in het veld.
 * Let op: deze functie gaat ervan uit dat het coördinaat dat werd meegegeven correct is, en dus niet buiten
 * de grenzen van het veld valt.
 */
struct Cell *get_cell(int x, int y) {
	return grid[x][y];
}

/*
ALLOCATE SNAKE
*/

struct Part **allocate_snake(int snake_length){
// http://stackoverflow.com/questions/3275381/how-to-implement-a-2-dimensional-array-of-struct-in-c
// http://stackoverflow.com/questions/26454022/storing-and-accessing-a-2d-array-in-a-struct

struct Part** snake = (struct Partl**) malloc(sizeof(struct Part**) * snake_length);
for(int i = 0; i < snake_length; i++) {
	snake[i] = (struct Cell**) malloc(sizeof(struct Cell*) * grid_height);
	}
 }
 return grid;
}

/*
DEALLOCATE SNAKE
*/

void deallocate_snake(int snake_length){

	for(int i = 0 ; i < grid_width; i++){
		free(snake[i]);
}
free(snake);
}

void initialize_snake(int snake_length) {
	snake = allocate_snake(snake_length);
	/*struct Coordinate *mines_coordinates = generate_random_mines(grid_width, grid_height, nr_of_mines);
	place_mines(mines_coordinates, nr_of_mines);
	compute_neighbouring_mines(mines_coordinates, grid_width, grid_height, nr_of_mines);
	free(mines_coordinates);
	nr_of_flags = NR_OF_MINES; // Zet variabele goed.*/
}
