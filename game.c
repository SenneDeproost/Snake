
  #include "game.h"
  #include "main.h"
  #include "GUI.h"
  #include "grid.h"
  #include "snake.h"
  #include "SDL/SDL.h"

void run_game(){
  read_GUI_input();
  move_snake();
  clear_screen();
  draw_snake();
  SDL_Delay(250);
  run_game();
}
