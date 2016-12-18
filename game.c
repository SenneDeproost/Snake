
  #include "game.h"
  #include "main.h"
  #include "GUI.h"
  #include "grid.h"
  #include "snake.h"
  #include "SDL/SDL.h"

void run_game(){
  clear_screen();
  check_collision();
  read_GUI_input();
  move_snake();
  draw_grid();
  draw_snake();
  SDL_Delay(250);
  run_game();
}
