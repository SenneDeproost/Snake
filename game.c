
  #include "game.h"
  #include "main.h"
  #include "GUI.h"
  #include "grid.h"
  #include "snake.h"

void run_game()
  {

    //read_GUI_input();
  //  read_GUI_input();
  //  sleep(0,0001); // Voorkomt dat de CPU te druk bezig is met het programma.
//printf("tik ");
	read_input();
  draw_grid();
  draw_snake();

   run_game();
   }


void read_input(){
  read_GUI_input();
  sleep(0);
	}
