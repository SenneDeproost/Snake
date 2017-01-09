
  #include "game.h"
  #include "main.h"
  #include "GUI.h"
  #include "grid.h"
  #include "snake.h"
  #include "SDL/SDL.h"

  #define head 0

  pause = 0; /* Zet pause initieel op 0. */
  score = 0;



void run_game(){
  //clear_screen();
  read_GUI_input();

  check_collision();

  move_snake();

  draw_grid();
  draw_snake();
  draw_walls();

  //test();


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

 head_x = get_part(head)->x;
 head_y = get_part(head)->y;
 apple_x = apple_point.x;
 apple_y = apple_point.y;

	 /* Check for collision APPLE and HEAD. */
 if (head_x == apple_x && head_y == apple_y){
	  initialize_apple();
		get_cell(apple_x, apple_y)->state = EMPTY;
		grow_snake();
    score = score + 50;
    clear_screen();
    draw_score();
    draw_grid();
    draw_snake();
    draw_walls();
 }

  /* Check for collision HEAD and BODY. */
  for (int i = 1; i != snake_length; i++){
    if (head_x == get_part(i)->x && head_y == get_part(i)->y){
      printf("%s\n","GAME OVER");
      exit(0);
    }
  }

  /* Check for collision HEAD and WALL */
  for (int i = 1; i < NR_OF_WALL_BLOCKS; i++){
    if (get_wall(i)->x == get_part(head)->x && get_wall(i)->y == get_part(head)->y){
      printf("%s\n","GAME OVER");
      exit(0);
    }
  }


}
