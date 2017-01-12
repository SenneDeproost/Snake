#include "savegame.h"
#include "snake.h"
#include "settings.h"
#include "grid.h"
#include "game.h"
#include "GUI.h"
#include <stdio.h>


// LOAD

void load_game(){

  FILE *fp = fopen("save.txt", "r");


  if (fp == NULL){
    printf("NO save.txt FILE EXISTS.\nPlease create a new one.\n");
    exit (1);
  }

else{
int a, b;

  remove_from_screen(apple_point.x, apple_point.y);
  for (int i = 0; i < snake_length - 1; i++){
    remove_from_screen(get_part(i)->x, get_part(i)->y);
  }

  fscanf(fp, "%i %i %i %i %i",
  &apple_point.x, &apple_point.y,
  &score,
  &get_part(0)->x,
  &get_part(0)->y
);

  get_cell(apple_point.x, apple_point.y)->state = EMPTY;
  for (int i = 0; i < snake_length - 1; i++){
    get_cell(get_part(i)->x, get_part(i)->y)->state = EMPTY;
  }



  draw_apple();
  draw_score();
}
  fclose(fp);

}

// SAVE

void save_game(){;

  FILE *fp = fopen("save.txt", "w+");

  fprintf(fp, "%i %i %i %i %i",
  apple_point.x, apple_point.y,
  score,
  get_part(0)->x,
  get_part(0)->y
);
  fclose(fp);

}
