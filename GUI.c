#include "GUI.h"
#include "main.h"
#include "grid.h"
#include "game.h"
#include "settings.h"
#include "snake.h"
#include "highscores.h"
#include "savegame.h"

#include <stdio.h>



int last_tail_x = 0;
int last_tail_y = 0;

int window_WIDTH;
int window_HEIGHT;

/* Variabelen voor SDL */

TTF_Font *font;
SDL_Surface *text;
SDL_Color text_color = {255, 255, 255};


/*
 * Dit is het venster dat getoond zal worden en waarin het speelveld weergegeven wordt.
 * Dit venster wordt aangemaakt bij het initialiseren van de GUI en wordt weer afgebroken
 * wanneer het spel eindigt.
 */
static SDL_Surface *window;

SDL_Surface* images[12];


/*
 * Maakt het hele venster blanco: deze functie kan je eventueel aanroepen voor
 * je iets begint te tekenen in het venster, zodat alle afbeeldingen die eerder
 * in het venster getekend waren verwijderd worden.
 * Aan deze functie hoef je normaal niets aan te passen.
 */
void clear_screen() {
	SDL_FillRect(window, NULL, 0x00000000);
	SDL_Flip(window);
}

// Hulpprocedure om elementen op het scherm te tekenen. (BRON: http://lazyfoo.net/SDL_tutorials/lesson02/index.php)

void draw_on_screen( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;

		//Blit the surface
SDL_BlitSurface( source, NULL, destination, &offset );
}


void draw_grid(){

// Teken elementen.
draw_walls();
draw_apple();

}

void draw_snake(){

	for(int i = 0; i != snake_length - 1; i++){

		draw_on_screen(
			(get_part(i)->x) * IMAGE_WIDTH,
			(get_part(i)->y) * IMAGE_HEIGHT,
			images[snakepart],
			window
		);

	}

remove_tail();

SDL_Flip(window);

}


void remove_tail(){

	draw_on_screen(
		last_tail_x * IMAGE_WIDTH,
		last_tail_y * IMAGE_HEIGHT,
		images[background],
		window
	);

}

void draw_walls(){

	for(int i = 0; i != NR_OF_WALL_BLOCKS; i++){
		draw_on_screen(
			get_wall(i)->x * IMAGE_WIDTH,
			get_wall(i)->y * IMAGE_HEIGHT,
			images[wall],
			window
		);

	}

SDL_Flip(window);
}


void draw_apple(){

	draw_on_screen(
		apple_point.x * IMAGE_WIDTH,
		apple_point.y * IMAGE_HEIGHT,
		images[apple],
		window
	);

}

void draw_candy(){

	draw_on_screen(
		candy_point.x * IMAGE_WIDTH,
		candy_point.y * IMAGE_HEIGHT,
		images[candy],
		window
	);

}

void remove_from_screen(int x, int y){
	draw_on_screen(
	x * IMAGE_WIDTH,
	y * IMAGE_HEIGHT,
	images[background],
	window
);
}


void read_GUI_input() {

	SDL_Event event;

	int mouse_x;
	int mouse_y;

// Voor de click events.
	int a;
	int b;


	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:

		deallocate_wall();
		deallocate_snake();
		deallocate_grid();
		exit(0);

		// Bediening van de slang met de pijltjestoetsen.
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {

			/* If test voorkomt dat de slang in tegengestelde richting gaat. */

			/* BOVEN */
			case SDLK_UP:

			if (get_part(0)->direction != DOWN){
			get_part(0)->direction = UP;
		  }
				break;

			/* ONDER */
	  	case SDLK_DOWN:

			if (get_part(0)->direction != UP){
			get_part(0)->direction = DOWN;
		  }
	  		break;

	  	/* LINKS */
  		case SDLK_LEFT:

			if (get_part(0)->direction != RIGHT){
			get_part(0)->direction = LEFT;
		  }
  			break;

	  	/* RECHTS */
	  	case SDLK_RIGHT:

			if (get_part(0)->direction != LEFT){
			get_part(0)->direction = RIGHT;
		  }
	  		break;

				/* Toetsen om andere spelfuncties aan te sturen */

				/* PAUSE */
		  	case SDLK_p:

				if (pause == 0){
				pause = 1;
				pause_game();
			  }
				else{
					pause = 0;
				}
		  		break;

	  		/* LOAD */
	  		case SDLK_l:
	  		load_game();
	  			break;

				/* SAVE */
				case SDLK_s:
				save_game();
					break;

			}
			break;


		}
	}
}


void stop_gui() {
	SDL_Quit();
}

/*
 * Laadt de afbeeldingen die getoond moeten worden in. Alle afbeeldingen worden samen bijgehouden
 * in een array 'images'.
 */
void initialize_figures() {
	images[background] = SDL_LoadBMP("Images/background.bmp");
	images[wall] = SDL_LoadBMP("Images/wall.bmp");
	images[snakepart] = SDL_LoadBMP("Images/snake.bmp");
	images[apple] = SDL_LoadBMP("Images/apple.bmp");
	images[candy] = SDL_LoadBMP("Images/candy.bmp");
	images[info_bar] = SDL_LoadBMP("Images/bar.bmp");
}

/*
 * Initialiseer het venster.
 */
void initialize_window(char *title, int grid_width, int grid_height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }



		// Initialize SDL_ttf library
    if (TTF_Init() != 0)
    {
       SDL_Quit();
       exit(1);
    }

    // Load a font
    //TTF_Font *font;
    font = TTF_OpenFont("arial.ttf", 24);
    if (font == NULL)
    {
       TTF_Quit();
       SDL_Quit();
       exit(1);
    }



    int window_width = grid_width * IMAGE_WIDTH;
    int window_height = grid_height * IMAGE_HEIGHT + 50;
		window_HEIGHT = window_height;
		window_WIDTH = window_width;
    window = SDL_SetVideoMode(window_width, window_height, 0, SDL_HWPALETTE | SDL_DOUBLEBUF);
    if (window == NULL) {
        printf("Couldn't set screen mode to required dimensions: %s\n", SDL_GetError());
        exit(1);
    }

    /* Set the screen title */
    SDL_WM_SetCaption(title, NULL);


}



void draw_score(){
char str[15];

   sprintf(str, "%d", score);

	text = TTF_RenderText_Solid(font,
					str,
			    text_color);

			    if (text == NULL)
			    {

			       TTF_Quit();
			       SDL_Quit();
			       exit(1);
			    }


	 // Teken onderste balk van het scherm.
	 draw_on_screen(
	 	0,
	 	window_HEIGHT - 40,
	 	images[info_bar],
	 	window
	 );

draw_on_screen(window_WIDTH / 2, window_HEIGHT - 40, text, window);

}


/*
 * Initialiseer de GUI. De functie krijgt de breedte en de hoogte van het speelveld mee als argumenten.
 */

void initialize_gui(int grid_width, int grid_height) {
	initialize_window("Snake", grid_width, grid_height);
	initialize_figures();
	atexit(stop_gui);
}
