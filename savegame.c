#include "savegame.h"
#include "snake.h"
#include "settings.h"

#include <stdio.h>

// LOAD

void load_game(){
  printf("LOAD\n");
  /* Reset snake */
/*  clear_screen();
  for(int i = 0; i != snake_length; i++){
    get_part(i)->x = -5;
    get_part(i)->y = -5;
    //get_part(i)->part = BODY;
    snake_length = 1;
    initialize_snake(MAX_SNAKE_LENGTH, 5, 5);
    draw_snake();

  }; */

  /* Load snake */

/*  FILE *fp = fopen("save.txt", "r");
  int x0, y0;

  fclose(fp);*/

}

// SAVE

void save_game(){
  printf("SAVE\n");
}
