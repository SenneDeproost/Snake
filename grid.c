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






// WALL

static struct Wall_part** walls;



struct Wall_part *get_wall(int i) {
	return walls[i];
}

struct Wall_part **allocate_wall(int nr_of_wall_blocks){
// BRONNEN:
// http://stackoverflow.com/questions/3275381/how-to-implement-a-2-dimensional-array-of-struct-in-c
// http://stackoverflow.com/questions/26454022/storing-and-accessing-a-2d-array-in-a-struct

struct Wall_part** walls = (struct Wall_part**) malloc(sizeof(struct Wall_part**) * nr_of_wall_blocks);
for(int i = 0; i < nr_of_wall_blocks; i++) {
	walls[i] = (struct Wall_part*) malloc(sizeof(struct Wall_part));
	}
 return walls;
}


void deallocate_wall(int nr_of_wall_blocks){

	for(int i = 0 ; i < nr_of_wall_blocks; i++){
		free(walls[i]);
}
free(walls);
}

void initialize_walls(){
	walls = allocate_wall(NR_OF_WALL_BLOCKS);
  place_walls_in_grid();
}


void place_walls_in_grid(){
	for (int i = 0; i < 5; i++){
		get_wall(i)->x = 0;
		get_wall(i)->y = i;
	}

	for (int i = 0 + 5; i < 5 + 5; i++){
		get_wall(i)->x = 6;
		get_wall(i)->y = i + 5;
	}

	for (int i = 0 + 10; i < 5 + 9; i++){
		get_wall(i)->x = i + 2;
		get_wall(i)->y = 8;
}

//get_wall(15)->x = 5;
//get_wall(15)->y = 6;


}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialize_grid(int grid_width, int grid_height) {
	grid = allocate_grid(grid_width, grid_height);
	initialize_apple();
	initialize_walls();
	/*struct Coordinate *mines_coordinates = generate_random_mines(grid_width, grid_height, nr_of_mines);
	place_mines(mines_coordinates, nr_of_mines);
	compute_neighbouring_mines(mines_coordinates, grid_width, grid_height, nr_of_mines);
	free(mines_coordinates);
	nr_of_flags = NR_OF_MINES; // Zet variabele goed.*/
}
