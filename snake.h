#ifndef SNAKE_H_
#define SNAKE_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "main.h"

// Variabelen
int snake_length;

// SNAKE

enum Part {
	HEAD,
	BODY,
	TAIL
};

enum Direction{
  UP,
  RIGHT,
  DOWN,
  LEFT
};

struct Snake_part {
	enum Part part;
  int x;
  int y;
  /*Direction geeft weer naar welke kant een blok zich zal verplaatsen bij de volgende
  stap van de slang.*/
  enum Direction direction;

};


// Alloceer een array voor de slang.

struct Snake_part **allocate_snake(int max_snake_length);



/*
 * Initialiseert het veld: maakt het veld aan, plaatst mijnen op random posities
 * en zorgt er voor dat de 'neighbouring_mines' waarde voor elk vakje juist staat.
 */
void initialize_snake(int max_snake_length, int start_x, int start_y);

/*
 * Geeft een pointer terug naar de Cell die zich bevindt op positie (x,y) in het veld.
 */
struct Snake_part *get_part(int i);


void move_snake();


#endif /* SNAKE_H_ */
