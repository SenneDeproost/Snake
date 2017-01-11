  #include "game.h"
  #include "main.h"
  #include "GUI.h"
  #include "grid.h"
  #include "snake.h"
  #include "highscores.h"
  #include "SDL/SDL.h"

  #define head 0

  pause = 0; /* Zet pause initieel op 0. */
  score = 0; /* Zet score initieel op 0. */

  gametime = 0;
  int candytime = 0;


  ///////////////
 //    LOOP   //
///////////////

void run_game(){

  draw_score();

  void gameloop(){
  read_GUI_input();
  gametime++;
  candytime++;
  printf("%d\n", gametime );

  check_collision();

  move_snake();

  if (candytime == 40)
  {
    initialize_candy();
    draw_candy();
  }

  if (candytime == 70){
    if (candy_point.x > -1){
      /* Eerst controleren of de candy niet al eerst buiten
       * scherm is geplaatst door een botsing met de slang */
      remove_candy();
    }
    candytime = 0;
  }

  draw_snake();
  draw_grid();


  SDL_Delay(250); /* Als het spel sneller moet, deze waarde dan veranderen (in ms). */
  gameloop();
}
gameloop();
}

  ///////////////
 //   PAUSE   //
///////////////

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

  ///////////////
 // COLLISION //
///////////////

void check_collision(){

 int head_x = get_part(head)->x;
 int head_y = get_part(head)->y;
 int apple_x = apple_point.x;
 int apple_y = apple_point.y;
 int candy_x = candy_point.x;
 int candy_y = candy_point.y;

	 /* Check for collision APPLE and HEAD. */
 if (head_x == apple_x && head_y == apple_y){
	  initialize_apple();
		get_cell(apple_x, apple_y)->state = EMPTY;
		grow_snake();
    score = score + 50;
    draw_score();
    draw_grid();
    draw_snake();
 }

 /* Check for collision CANDY and HEAD. */
if (head_x == candy_x && head_y == candy_y){
  remove_candy();
  grow_snake();
  score = score + 100;
  draw_score();
}

  /* Check for collision HEAD and BODY. */
  for (int i = 1; i != snake_length; i++){
    if (head_x == get_part(i)->x && head_y == get_part(i)->y){
      game_over();
    }
  }

  /* Check for collision HEAD and WALL */
  for (int i = 1; i < NR_OF_WALL_BLOCKS; i++){
    if (get_wall(i)->x == get_part(head)->x && get_wall(i)->y == get_part(head)->y){
      game_over();
    }
  }


}

  ///////////////
 // GAME OVER //
///////////////

void game_over(){
  clear_screen();
  printf("%s\n","GAME OVER");
  printf("Score: %i\n", score);
  addToScoreboard(score);
  deallocate_wall();
  deallocate_snake();
  deallocate_grid();
  exit(0);
}
