#include "snake.h"
#include "settings.h"
#include "GUI.h"


// Variabelen
int snake_length;
snake_length = 2; // initieel is een slang een head en een tail, dus heeft lengte = 2.


static struct Snake_part** snake;


struct Snake_part *get_part(int i) {
	return snake[i];
}

/*
ALLOCATE SNAKE
*/

struct Snake_part **allocate_snake(){
// BRONNEN:
// http://stackoverflow.com/questions/3275381/how-to-implement-a-2-dimensional-array-of-struct-in-c
// http://stackoverflow.com/questions/26454022/storing-and-accessing-a-2d-array-in-a-struct

struct Snake_part** snake = (struct Snake_part**) malloc(sizeof(struct Snake_part**) * MAX_SNAKE_LENGTH);
for(int i = 0; i < MAX_SNAKE_LENGTH; i++) {
	snake[i] = (struct Snake_part*) malloc(sizeof(struct Snake_part));
	}
 return snake;
}

/*
DEALLOCATE SNAKE
*/

void deallocate_snake(){

	for(int i = 0 ; i < MAX_SNAKE_LENGTH; i++){
		free(snake[i]);
}
//free(snake);
}

/*
MOVE SNAKE_H_
*/
// Laat de slang 1 stap bewegen in de richting die gelijk is aan direction van de head.
void move_snake(){

// Variabelen die gebruikt woren om de vorige x en y waarden van een part bij te houden
int prev_x;
int prev_y;

// TAIL
last_tail_x = get_part(snake_length - 1)->x;
last_tail_y = get_part(snake_length - 1)->y;


for (int i = 0; i != snake_length; i++){



	// HEAD
	if (get_part(i)->part == HEAD){


				prev_x = get_part(i)->x;
				prev_y = get_part(i)->y;

    // Wanneer de kop zich binnen het veld bevindt.
			if (get_part(i)->direction == UP){
				get_part(i)->y--;
			}
			else if (get_part(i)->direction == DOWN){
				get_part(i)->y++;
			}
			else if (get_part(i)->direction == LEFT){
				get_part(i)->x--;
			}
			else if (get_part(i)->direction == RIGHT){
				get_part(i)->x++;
			}

		// Wanneer de kop het veld heeft verlaten, moet er langs de andere kant van
		// het veld terug tevoorschijn komen.

    /* BOVENSTE RAND */
		if (get_part(i)->y < 0){
			get_part(i)->y = get_part(i)->y + GRID_HEIGHT;
		}
		/* ONDERSTE RAND */
		else if (get_part(i)->y > (GRID_HEIGHT - 1)){
			get_part(i)->y = 0;
		}
		/* LINKSE RAND */
		else if (get_part(i)->x < 0){
			get_part(i)->x = get_part(i)->x + GRID_WIDTH;
		}
		/* RECHTSE RAND */
		else if (get_part(i)->x > (GRID_WIDTH - 1)){
			get_part(i)->x = 0;
		}


		}


	else{
  // REST
		/* Zet de x en y waarden juist. Dit wordt gedaan door de part te zetten op de
		positie van de voorgaande block. */
		int buffer_x;
		int buffer_y;
		buffer_x = get_part(i)->x;
		buffer_y = get_part(i)->y;
		get_part(i)->x = prev_x;
		get_part(i)->y = prev_y;
		prev_x = buffer_x;
		prev_y = buffer_y;
  	}


	}
}

// GROW
void grow_snake(){
	get_part(snake_length - 1)->part = BODY; /* Het laatste stuk van slang wordt body */
	get_part(snake_length)->part = TAIL; /* Voeg een stuk toe die de nieuwe tail wordt van de slang.  */
	snake_length = snake_length + 1;

}




void initialize_snake(int start_x, int start_y) {
	snake = allocate_snake();

  // Zet in het midden van het veld de kop van de slang.
  int a;
  int b;
  a = start_x;
  b = start_y;
  get_part(0)->part = HEAD; // Eerste stuk van de slang is de head.
  get_part(1)->part = TAIL; // Tweede stuk van de slang is de tail.

// Zet het hoofd en de tail in het midden van het scherm.
  get_part(0)->x = a;
  get_part(0)->y = b;
  get_part(1)->x = a - 1;
  get_part(1)->y = b;

  // Zet de direction initieel op right.
  get_part(0)->direction = RIGHT;

}
