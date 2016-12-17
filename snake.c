#include "snake.h"
#include "settings.h"

/*
 * Stelt het twee-dimensionale veld voor. grid is een tweedimensionale array van pointers naar Cellen.
 * Jullie moeten deze variabele zelf niet gebruiken: in de plaats kan je gebruik maken van de functie get_cell hieronder.
 */
static struct Snake_part** snake;

/*
 * Geeft een pointer terug naar de Cell die zich bevindt op positie (x,y) in het veld.
 * Let op: deze functie gaat ervan uit dat het coördinaat dat werd meegegeven correct is, en dus niet buiten
 * de grenzen van het veld valt.
 */
struct Snake_part *get_part(int i) {
	return snake[i];
}

/*
ALLOCATE SNAKE
*/

struct Snake_part **allocate_snake(int snake_length){
// BRONNEN:
// http://stackoverflow.com/questions/3275381/how-to-implement-a-2-dimensional-array-of-struct-in-c
// http://stackoverflow.com/questions/26454022/storing-and-accessing-a-2d-array-in-a-struct

struct Snake_part** snake = (struct Snake_part**) malloc(sizeof(struct Snake_part**) * snake_length);
for(int i = 0; i < snake_length; i++) {
	snake[i] = (struct Snake_part*) malloc(sizeof(struct Snake_part));
	}
 return snake;
}

/*
DEALLOCATE SNAKE
*/

void deallocate_snake(int snake_length){

	for(int i = 0 ; i < snake_length; i++){
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

  // Zet in het midden van het veld de kop van de slang.
  int a;
  int b;
  a = GRID_WIDTH / 2;
  b = GRID_HEIGHT / 2;
  get_part(0)->part = HEAD; // Eerste stuk van de slang is de head.
  get_part(1)->part = TAIL; // Tweede stuk van de slang is de tail.

// Zet het hoofd en de tail in het midden van het scherm.
  get_part(0)->x = a;
  get_part(0)->y = b;
  get_part(1)->x = a - 1;
  get_part(1)->y = b;

  // Zet de direction initieel op right.
  get_part(0)->direction = RIGHT;
  get_part(1)->direction = RIGHT;


}
