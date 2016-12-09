#include "GUI.h"
#include "main.h"
#include "grid.h"
#include "game.h"



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

/*
 * Deze array bevat de 12 afbeeldingen die gebruikt worden tijdens het spel:
 * images[0]: de afbeelding die een onthuld vak met 0 mijnen als buur voorstelt
 * images[1]: de afbeelding die een onthuld vak met 1 mijn als buur voorstelt
 * images[2]: de afbeelding die een onthuld vak met 2 mijnen als buur voorstelt
 * images[3]: de afbeelding die een onthuld vak met 3 mijnen als buur voorstelt
 * images[4]: de afbeelding die een onthuld vak met 4 mijnen als buur voorstelt
 * images[5]: de afbeelding die een onthuld vak met 5 mijnen als buur voorstelt
 * images[6]: de afbeelding die een onthuld vak met 6 mijnen als buur voorstelt
 * images[7]: de afbeelding die een onthuld vak met 7 mijnen als buur voorstelt
 * images[8]: de afbeelding die een onthuld vak met 8 mijnen als buur voorstelt
 * images[9]: de afbeelding die een vak met een vlag voorstelt
 * images[10]: de afbeelding die een niet-onthuld vak voorstelt
 * images[11]: de afbeelding die een vak met een mijn voorstelt
 */
SDL_Surface* images[12];

/*
 * Maakt het hele venster blanco: deze functie kan je eventueel aanroepen voor
 * je iets begint te tekenen in het venster, zodat alle afbeeldingen die eerder
 * in het venster getekend waren verwijderd worden.
 * Aan deze functie hoef je normaal niets aan te passen.
 */
void clear_screen() {
	SDL_FillRect(window, NULL, 0xFFFFFFFF);
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


/*
 * Deze functie moet je zelf vervolledigen: je mag alles aan deze functie
 * (inclusief return-type en argumenten) aanpassen, indien nodig.
 */
void draw_grid() {

// Teken de vakjes in de GUI.
for (int i = 0; i <= (WIDTH - 1); i++){
	for (int j = 0; j <= (HEIGHT - 1); j++){
		int a;

		// Wanneer cell uncovered of flagged is, mag het geprint

		if(get_cell(i, j)->state == UNCOVERED){
		a = get_cell(i, j)->neighbouring_mines;
		draw_on_screen(i * IMAGE_WIDTH, j * IMAGE_WIDTH, images[a], window);
		}

		// Vakje is FLAGGED.
		else if (get_cell(i, j)->state == FLAGGED){
			draw_on_screen(i * IMAGE_WIDTH, j * IMAGE_HEIGHT, images[9], window);
		}



		// Uncovered vakje.
		else{
			draw_on_screen(i * IMAGE_WIDTH, j * IMAGE_HEIGHT, images[10], window);
			}

		// Vakje bevat een mijn en de speler is dood.
		if((get_cell(i, j)->is_mine == 1) && dead == 1){
		draw_on_screen(i * IMAGE_WIDTH, j * IMAGE_HEIGHT, images[11], window);
			}
		}
	}
//SDL_BlitSurface(images[0], NULL, window, NULL);



	/*
	 * Onderstaande code moet zeker worden uitgevoerd op het einde van deze functie.
	 * Wanneer je iets tekent in het venster wordt dit venster nl. niet meteen aangepast.
	 * Via de SDL_Flip functie wordt het venster correct geupdatet.
	 */
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

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_p:
				print_grid();
				draw_grid();
				break;
			}
			break;

		case SDL_MOUSEBUTTONDOWN:
			/*
			 * De speler heeft met de muis geklikt: met de onderstaande lijn worden de coördinaten in het
			 * het speelveld waar de speler geklikt heeft bewaard in de variabelen mouse_x en mouse_y.
			 */
			SDL_GetMouseState(&mouse_x, &mouse_y);
			a = (mouse_x / IMAGE_WIDTH);
			b = (mouse_y/ IMAGE_HEIGHT);
			switch (event.button.button) {
			case SDL_BUTTON_LEFT:
				reveal_coordinate(a, b);
				draw_grid();
				print_grid();
				break;
			case SDL_BUTTON_RIGHT:
				flag_coordinate(a, b);
				draw_grid();
				print_grid();
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
	images[0] = SDL_LoadBMP("Images/0.bmp");
	images[1] = SDL_LoadBMP("Images/1.bmp");
	images[2] = SDL_LoadBMP("Images/2.bmp");
	images[3] = SDL_LoadBMP("Images/3.bmp");
	images[4] = SDL_LoadBMP("Images/4.bmp");
	images[5] = SDL_LoadBMP("Images/5.bmp");
	images[6] = SDL_LoadBMP("Images/6.bmp");
	images[7] = SDL_LoadBMP("Images/7.bmp");
	images[8] = SDL_LoadBMP("Images/8.bmp");
	images[9] = SDL_LoadBMP("Images/flagged.bmp");
	images[10] = SDL_LoadBMP("Images/covered.bmp");
	images[11] = SDL_LoadBMP("Images/mine.bmp");
}

/*
 * Initialiseer het venster.
 */
void initialize_window(char *title, int grid_width, int grid_height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    int window_width = grid_width * IMAGE_WIDTH;
    int window_height = grid_height * IMAGE_HEIGHT;
    window = SDL_SetVideoMode(window_width, window_height, 0, SDL_HWPALETTE | SDL_DOUBLEBUF);
    if (window == NULL) {
        printf("Couldn't set screen mode to required dimensions: %s\n", SDL_GetError());
        exit(1);
    }
    /* Set the screen title */
    SDL_WM_SetCaption(title, NULL);
}

/*
 * Initialiseer de GUI. De functie krijgt de breedte en de hoogte van het speelveld mee als argumenten.
 */


void initialize_gui(int grid_width, int grid_height) {
	initialize_window("Minesweeper", grid_width, grid_height);
	initialize_figures();
	draw_grid();
	while (1) {  // 1 = GUI, 0 = TERMINAL
		read_GUI_input();
		sleep(0,0001); // Voorkomt dat de CPU te druk bezig is met het programma.
	}
	atexit(stop_gui);
}

/*
int main(int argc, char *argv[]) {
	initialize_gui(10, 10);
	while (1) { read_input(); }
	return 0;
}
*/
