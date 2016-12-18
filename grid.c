#include "grid.h"
#include "main.h"
#include "settings.h"
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
 * Stelt een positie voor: elke positie heeft een x- en een y-coordinaat.
 */
struct Coordinate {
	int x, y;
};



/*
ALLOCATE GRID
*/

struct Cell ***allocate_grid(int grid_width, int grid_height){
// http://stackoverflow.com/questions/3275381/how-to-implement-a-2-dimensional-array-of-struct-in-c
// http://stackoverflow.com/questions/26454022/storing-and-accessing-a-2d-array-in-a-struct

struct Cell*** grid = (struct Cell***) malloc(sizeof(struct Cell**) * grid_width * grid_height);
for(int i = 0; i < grid_width; i++) {
	grid[i] = (struct Cell**) malloc(sizeof(struct Cell*) * grid_height);
	for(int j = 0; j < grid_height; j++) {
    grid[i][j] = (struct Cell*)  malloc(sizeof(struct Cell));
	}
 }
 return grid;
}

/*
DEALLOCATE GRID
*/

void deallocate_grid(int grid_width, int grid_height){

	for(int i = 0 ; i < grid_width; i++){
		for(int j = 0 ; j < grid_height; j++){

		free(grid[i][j]);

	}
		free(grid[i]);
}
free(grid);
}

// APPLE

void initialize_apple(){
	generate_random_apple();
	place_apple_in_grid();
}

void generate_random_apple(){
	apple_point.x = rand() % GRID_WIDTH;
	apple_point.y = rand() % GRID_HEIGHT;
}

void place_apple_in_grid(){
	int x;
	int y;
	x = apple_point.x;
	y = apple_point.y;
	get_cell(x, y)->state = APPLE;
}

// COLLISION

void check_collision(){
	int head_x;
	int head_y;

	int apple_x;
	int apple_y;

 head_x = get_part(0)->x;
 head_y = get_part(0)->y;
 apple_x = apple_point.x;
 apple_y = apple_point.y;

	 /* Check for collision. */
 if (head_x == apple_x && head_y == apple_y){
	  initialize_apple();
		get_cell(apple_x, apple_y)->state = EMPTY;
		grow_snake();
 }

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialize_grid(int grid_width, int grid_height) {
	grid = allocate_grid(grid_width, grid_height);
	  initialize_apple();
	/*struct Coordinate *mines_coordinates = generate_random_mines(grid_width, grid_height, nr_of_mines);
	place_mines(mines_coordinates, nr_of_mines);
	compute_neighbouring_mines(mines_coordinates, grid_width, grid_height, nr_of_mines);
	free(mines_coordinates);
	nr_of_flags = NR_OF_MINES; // Zet variabele goed.*/
}
