#include "grid.h"
#include "main.h"
#include "settings.h"
#include "snake.h"


static struct Cell*** grid;

struct Cell *get_cell(int x, int y) {
	return grid[x][y];
}

struct Coordinate {
	int x, y;
};





  ///////////////
 //    GRID   //
///////////////


/*
ALLOCATE GRID
*/

// BRONNEN:
// http://stackoverflow.com/questions/3275381/how-to-implement-a-2-dimensional-array-of-struct-in-c
// http://stackoverflow.com/questions/26454022/storing-and-accessing-a-2d-array-in-a-struct

struct Cell ***allocate_grid(int grid_width, int grid_height){
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
//free(grid);
}





  ////////////////
 //    APPLE   //
////////////////

void initialize_apple(){
	generate_random_apple();
	place_apple_in_grid();
}

void generate_random_apple(){
	apple_point.x = rand() % GRID_WIDTH;
	apple_point.y = rand() % GRID_HEIGHT;
}

void place_apple_in_grid(){
	int x = apple_point.x;
	int y = apple_point.y;

// Controle of de appel niet in een muur komt.
	if (get_cell(x, y)->state == WALL){
		initialize_apple();
	}

// Controle of de appel niet in de slang verschijnt.
		for(int i = 0; i =! snake_length; i++){
		if (get_part(i)->x == x && get_part(i)->y == y){
			initialize_apple();
		}
	}
			get_cell(x, y)->state = APPLE;

}

void remove_apple(){
	get_cell(apple_point.x, apple_point.y)->state == EMPTY;
  remove_from_screen(apple_point.x, apple_point.y);

}





  ////////////////
 //    CANDY   //
////////////////

void remove_candy(){
	get_cell(candy_point.x, candy_point.y)->state == EMPTY;
  remove_from_screen(candy_point.x, candy_point.y);

	candy_point.x = -1;
	candy_point.y = -1;
}


void initialize_candy(){
	generate_random_candy();
	place_candy_in_grid();
}

void generate_random_candy(){
	candy_point.x = rand() % GRID_WIDTH;
	candy_point.y = rand() % GRID_HEIGHT;
}

void place_candy_in_grid(){
	int x;
	int y;
	x = candy_point.x;
	y = candy_point.y;

// Controle of de candy niet in een muur komt.
	if (get_cell(x, y)->state == WALL){
		initialize_candy();
	}

// Controle of de candy niet in de slang verschijnt.
		for(int i = 0; i =! snake_length; i++){
		if (get_part(i)->x == x && get_part(i)->y == y){
			initialize_candy();
		}
	}
			get_cell(x, y)->state = CANDY;

}





  ///////////////
 //    WALL   //
///////////////

static struct Wall_part** walls;



struct Wall_part *get_wall(int i) {
	return walls[i];
}

// BRONNEN:
// http://stackoverflow.com/questions/3275381/how-to-implement-a-2-dimensional-array-of-struct-in-c
// http://stackoverflow.com/questions/26454022/storing-and-accessing-a-2d-array-in-a-struct

struct Wall_part **allocate_wall(){

struct Wall_part** walls = (struct Wall_part**) malloc(sizeof(struct Wall_part**) * NR_OF_WALL_BLOCKS);
for(int i = 0; i < NR_OF_WALL_BLOCKS; i++) {
	walls[i] = (struct Wall_part*) malloc(sizeof(struct Wall_part));
	}
 return walls;
}


void deallocate_wall(){
	for(int i = 0 ; i < NR_OF_WALL_BLOCKS; i++){
		free(walls[i]);
}
//free(walls);
}

void initialize_walls(){
	walls = allocate_wall(NR_OF_WALL_BLOCKS);
  place_walls_in_grid();
}


/* Voor het plaatsen van een muur op een bepaalde locatie. */

void place_wall(int n, int x, int y){

get_wall(n)->x = x;
get_wall(n)->y = y;
get_cell(x, y)->state = WALL;

}

/* Hierbinnen nieuwe muren definiëren. */

void place_walls_in_grid(){

	for (int i = 0; i < 5; i++){
	place_wall(i, 0, i);
	}

	for (int i = 0 + 5; i < 5 + 5; i++){
	place_wall(i, 6, i + 5);
	}

	for (int i = 0 + 10; i < 5 + 9; i++){
	place_wall(i, i + 2, 8);
}

place_wall(2, 4, 4);


}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialize_grid(int grid_width, int grid_height) {
	grid = allocate_grid(grid_width, grid_height);
	initialize_apple();
	initialize_walls();
}
