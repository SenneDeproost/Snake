#ifndef GUI_H_
#define GUI_H_

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"


#define background 0
#define wall 1
#define snakepart 2
#define apple 3
#define candy 4
#define info_bar 5

/*
 * De hoogte en breedte (in pixels) van de afbeeldingen die getoond worden.
 * Als je andere afbeelding wil gebruiken in je GUI, zorg er dan voor dat deze
 * dimensies ook aangepast worden.
 */

/*
 * Initialiseert onder andere het venster waarin het speelveld getoond zal worden.
 * Deze functie moet dus aangeroepen worden aan het begin van het spel, vooraleer je
 * het speeldveld begint te tekenen.
 *
 * De functie neemt als argumenten ook de breedte en de hoogte van het speelveld.
 */
void initialize_gui(int grid_width, int grid_height);

void clear_screen();

int last_tail_x;
int last_tail_y;

/*
 * Tekent het huidige veld in het venster. Deze functie moeten jullie dus zelf implementeren.
 */
void draw_grid(void);

void draw_snake(void);

void draw_walls(void);

void remove_candy_from_screen(void);

void draw_rectangle(void);

// SCORE

void draw_score(void);




#endif /* GUI_H_ */
