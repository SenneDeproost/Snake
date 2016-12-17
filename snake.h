#ifndef SNAKE_H_
#define SNAKE_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// SNAKE

enum Part {
	HEAD,
	BODY,
	TAIL
};

struct Snake_part {
	enum Part part
};


// Alloceer een array voor de slang.

struct Part **allocate_snake(int snake_length);



/*
 * Initialiseert het veld: maakt het veld aan, plaatst mijnen op random posities
 * en zorgt er voor dat de 'neighbouring_mines' waarde voor elk vakje juist staat.
 */
void initialize_snake(int grid_width, int grid_height);

/*
 * Geeft een pointer terug naar de Cell die zich bevindt op positie (x,y) in het veld.
 */
struct Part *get_part(int i);


#endif /* SNAKE_H_ */
