
  #include "game.h"
  #include "main.h"
  #include "GUI.h"
  #include "grid.h"
  #include "snake.h"
  #include "SDL/SDL.h"

  pause = 0; /* Zet pause initieel op 0. */

void run_game(){
  clear_screen();
  read_GUI_input();
  move_snake();
  draw_grid();
  draw_snake();
  check_collision();
  SDL_Delay(250);
  run_game();
}

void pause_game(){
  pause == 1;
  draw_grid();
  draw_snake();
  while (pause){
  SDL_Delay(250);
  read_GUI_input();
  pause_game();
 }
 run_game();
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

	 /* Check for collision APPLE and HEAD. */
 if (head_x == apple_x && head_y == apple_y){
	  initialize_apple();
		get_cell(apple_x, apple_y)->state = EMPTY;
		grow_snake();
 }

  /* Check for collision HEAD and BODY. */
  for (int i = 1; i != snake_length; i++){
    if (head_x == get_part(i)->x && head_y == get_part(i)->y){
      printf("%s\n","GAME OVER");
      exit(0);
    }
  }

}
