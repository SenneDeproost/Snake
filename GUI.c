#include "GUI.h"
#include "main.h"
#include "grid.h"
#include "game.h"
#include "settings.h"
#include "snake.h"

#include <stdio.h>


#define background 0
#define wall 1
#define snake 2
#define apple 3

int last_tail_x = 0;
int last_tail_y = 0;

int window_WIDTH;
int window_HEIGHT;

TTF_Font *font;
SDL_Surface *text;
SDL_Color text_color = {255, 255, 255};


/*
 *
 * Op het internet kan je verschillende tutorials voor SDL vinden.
 * Zie bv. http://www.parallelrealities.co.uk/2011/09/basic-game-tutorial-1-opening-window.html
 * Of http://lazyfoo.net/SDL_tutorials/
 * Of https://wiki.libsdl.org/FrontPage (bevat documentatie voor de verschillende functies
 * en types die gebruikt worden in SDL)
 */

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

// Teken de vakjes in de GUI.
for (int i = 0; i <= (GRID_WIDTH - 1); i++){
	for (int j = 0; j <= (GRID_HEIGHT - 1); j++){

		// Als de cell een apple is.
		if (get_cell(i, j)->state == APPLE){
			draw_on_screen(i * IMAGE_WIDTH, j * IMAGE_WIDTH, images[3], window);
		}
	}
	SDL_Flip(window);
}

}

void draw_snake(){

	for(int i = 0; i != snake_length - 1; i++){

		draw_on_screen(
			(get_part(i)->x) * IMAGE_WIDTH,
			(get_part(i)->y) * IMAGE_HEIGHT,
			images[snake],
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
printf("%i %i\n",get_wall(i)->x, get_wall(i)->y );
		draw_on_screen(
			get_wall(i)->x * IMAGE_WIDTH,
			get_wall(i)->y * IMAGE_HEIGHT,
			images[wall],
			window
		);

	}

SDL_Flip(window);

}



/*
 * Vangt de input uit de GUI op. Deze functie is al deels geïmplementeerd, maar je moet die zelf
 * nog afwerken. Je mag opnieuw alles aanpassen aan deze functie, inclusies return-type en argumenten.
 */
void read_GUI_input() {

	SDL_Event event;

	int mouse_x;
	int mouse_y;

// Voor de click events.
	int a;
	int b;

	/*
	 * Handelt alle input uit de GUI af.
	 * Telkens de speler een input aan de GUI geeft (bv. een muisklik, muis bewegen, toets indrukken enz.)
	 * wordt er een 'event' (van het type SDL_Event) gegenereerd dat hier wordt afgehandeld.
	 *
	 * Let wel op: niet al deze events zijn relevant voor jou: als de muis bv. gewoon wordt bewogen, hoef
	 * je niet te reageren op dit event. Je zal dus (eventueel) een manier moeten vinden om alle niet-relevante
	 * events weg te filteren.
	 *
	 * Zie ook https://wiki.libsdl.org/SDL_PollEvent en http://www.parallelrealities.co.uk/2011_09_01_archive.html
	 */
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:

			exit(0);

		// Bediening van de slang met de pijltjestoetsen.
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {

			/* If test voorkomt dat de slang in tegengestelde richting gaat. */

			/* BOVEN */
			case SDLK_UP:
			printf("up\n");
			if (get_part(0)->direction != DOWN){
			get_part(0)->direction = UP;
		  }
				break;

			/* ONDER */
	  	case SDLK_DOWN:
			printf("down\n");
			if (get_part(0)->direction != UP){
			get_part(0)->direction = DOWN;
		  }
	  		break;

	  	/* LINKS */
  		case SDLK_LEFT:
			printf("left\n");
			if (get_part(0)->direction != RIGHT){
			get_part(0)->direction = LEFT;
		  }
  			break;

	  	/* RECHTS */
	  	case SDLK_RIGHT:
			printf("right\n");
			if (get_part(0)->direction != LEFT){
			get_part(0)->direction = RIGHT;
		  }
	  		break;

				/* Toetsen om andere spelfuncties aan te sturen */

				/* RECHTS */
		  	case SDLK_p:
				printf("pause\n");
				if (pause == 0){
				pause = 1;
				pause_game();
			  }
				else{
					pause = 0;
				}
		  		break;

			}
			break;

		case SDL_MOUSEBUTTONDOWN:
			/*
			 * De speler heeft met de muis geklikt: met de onderstaande lijn worden de coördinaten in het
			 * het speelveld waar de speler geklikt heeft bewaard in de variabelen mouse_x en mouse_y.
			 */
			SDL_GetMouseState(&mouse_x, &mouse_y);

			switch (event.button.button) {
			case SDL_BUTTON_LEFT:

				break;
			case SDL_BUTTON_RIGHT:

				break;
			}

		}
	}
}

/*
 * Met de code hieronder moet je niet echt rekening houden. Deze code hoef je enkel aan te passen
 * als je iets wil veranderen aan het initialiseren van de GUI.
 *
 * Let wel op, de functie initialize_gui moet aan de start van het programma zeker aangeroepen worden!
 *
 * De main-functie die helemaal onderaan gedefinieerd staat, moet je ook wel verwijderen. Deze functie
 * staat er enkel zodat je meteen kan controleren of de SDL library werkt op jouw computer, maar je
 * hebt deze functie niet nodig om je project te maken.
 */

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
	images[snake] = SDL_LoadBMP("Images/snake.bmp");
	images[apple] = SDL_LoadBMP("Images/apple.bmp");
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
int test =  sprintf(str, "%d", 5);

   sprintf(str, "%d", score);
  // puts(str);


	text = TTF_RenderText_Solid(font,
					str,
			    text_color);

			    if (text == NULL)
			    {

			       TTF_Quit();
			       SDL_Quit();
			       exit(1);
			    }

					draw_on_screen(window_WIDTH / 2, window_HEIGHT - 40, text, window);
					SDL_Flip(window);
}

/*
 * Initialiseer de GUI. De functie krijgt de breedte en de hoogte van het speelveld mee als argumenten.
 */

void initialize_gui(int grid_width, int grid_height) {
	initialize_window("Snake", grid_width, grid_height);
	initialize_figures();
	atexit(stop_gui);
}
