
  #include "game.h"
  #include "main.h"
  #include "GUI.h"

/****************************************************************************************************
 *				          			     	  		TE IMPLEMENTEREN FUNCTIES:			                 			  			*
 ****************************************************************************************************/
// Zet variabelen goed.
 dead = 0;
 nr_of_flagged_mines = 0;

/*
 * Deze functie wordt aangeroepen als de gebruiker een vlag wil plaatsten op het vakje met positie (x,y)
 * in het veld.
 */
void flag_coordinate(int x, int y){


// UNFLAG //
if (get_cell(x, y)->state == FLAGGED) { // Is vakje gevlagd?
  get_cell(x, y)->state = COVERED; // Zet status van vakje terug op covered.
  nr_of_flags++; // Verhoog aantal vlaggen.

  if (get_cell (x, y)->is_mine == 1){ // Als het onderliggend vakje een mijn was, dan wordt nr_of_flagged_mines verminderd.
  nr_of_flagged_mines--;
    }
  }

  // FLAG //
  else if (nr_of_flags != 0){ // Als de vlaggen niet op zijn, kan de cel van status veranderen.
  get_cell(x, y)->state = FLAGGED;  // Verader de status van de cel naar FLAGGED (= 2)
  nr_of_flags--; // Verminder het aantal vlaggen dat de speler ter beschikking nog heeft

  if (get_cell(x, y)->is_mine == 1){
    nr_of_flagged_mines++; // Verminder het aantal flagged mines.
    }

    if (nr_of_flagged_mines == NR_OF_MINES){
      printf("YOU WON!\n");
      update_stats();
      show_stats();
      exit(0); // Programma wordt afgesloten met code 0 = succes.
    }

  }

  // Het aantal vlaggen is op
  else
  {
    printf("NO MORE FLAGS\n"); // Komt op het scherm al er geen vlggen meer zijn.
  }
}


/*
 * Deze functie wordt aangeroepen als de gebruiker het vakje met positie (x,y) in het veld wil onthullen.
 */

void reveal_coordinate(int x, int y) {
/* Als een cel een mijn bevat, dan is de speler dood*/
if (get_cell(x, y)->is_mine == 1 )
{
    printf("MINE EXPLODED\n");
    dead = 1;
    print_grid();
    draw_grid();
    update_stats();
    show_stats(); // MOET ONDERAAN GEPRINT WORDEN !! 2 BE DEBUG
    //exit(0);
}

/* Als de cel geen mijn is, verander dan zijn staat van covered naar uncovered. */
else {
    // Zet de status van het vakje op UNCOVERED.
    get_cell(x, y)->state = UNCOVERED;

  // Test of het vakje geen naburige mijnen heeft.
  if (get_cell(x, y)->neighbouring_mines == 0)
  {

    // Als het 0 naburige vakjes heeft, moeten al zijn buren bekeken worden of zij een mijn in de buurt hebben.

    for (int i = -1; i < 2; i++) // Begin bij de cel aan de linkse kant (vandaar de -1).
      {
        for (int j = -1; j < 2; j++) // Begin bij de cel aan de rechtse kant.
        {
          if ((x + i) < WIDTH && (x + i)  >= 0 && (y + j) < HEIGHT && (y + j) >= 0) // Controle of een buurcel van de mijn zich niet buiten de randen van het veld bevindt.
          {
            if (get_cell(x + i, y + j)->state == COVERED)
            {
          reveal_coordinate(x + i, y + j); // Recursieve oproep op de naburige cellen.
            }
          }
        }
      }
    }
  }
}




/*
 * Deze functie wordt aangeroepen om het hele, onthulde, veld te printen.
 */



/*
 * Deze functie wordt in het begin, eens het veld geïnitialiseerd is, aangeroepen.
 * Eens deze functie is aangeroepen moet het spel in beurten verdergaan tot de speler gewonnen of verloren heeft.
 * Na elke beurt moet het hele veld automatisch geprint worden, via de functie print_grid uit printer.h,
 * en moet er geprint worden hoeveel vlaggen nog beschikbaar zijn voor de speler.
 */
void run_game()
{

/*
 * Leest de input van de gebruiker via de console in, en roept daarna de juiste functie op.
 * De gebruiker kan 3 soorten inputs geven:*/
 handle_input();

 /*
 *
 * 1)
 * F x y
 * Wordt gebruikt om een vlag te plaatsen op positie (x,y) in het veld. X en y zijn hier integers.
 * handle_input roept hierna de functie flag_coordinate op.
 *
 * 2)
 * R x y
 * Wordt gebruikt om het vakje met positie (x,y) te onthullen. X en y zijn hier integers.
 * handle_input roept hierna de functie reveal_coordinate op.
 *
 * 3)
 * P
 * Print het hele, onthulde veld.
 * handle_input roept hierna de functie print_grid_uncovered op.
 *
 *
 * Elk van deze functies (flag_coordinate, reveal_coordinate en print_grid_uncovered) moeten
 * nog door jullie geïmplementeerd worden.
 *
 */
 run_game();
 }


// Pas de statisteken aan in de da.ta file.
 void update_stats()
{
  int nr_of_games;
  int nr_of_games_won;
  FILE * fp;
  FILE * fptr;

  fp = fopen ("da.ta", "r+");

// Maak een file aan als deze nog niet bestaat.
  if (fp == NULL){
    fptr = fopen ("da.ta", "wb");
    fprintf(fptr, "0 0");
    fclose(fptr);
  }

  fp = fopen ("da.ta", "r+");

  fscanf(fp, "%d %d", &nr_of_games, &nr_of_games_won);

  // Controle of spel gewonnen was.
  if (dead == 0){
  nr_of_games_won++;
   }
  nr_of_games++;

// Clear de file van data
  fclose(fp);
  fp = fopen ("da.ta", "w");
  fprintf(fp, "");
  fclose(fp);
  fp = fopen("da.ta", "r+");


  fprintf(fp, "%d %d", nr_of_games, nr_of_games_won); // Schrijf naar de file

  fclose(fp);

  return(0);
}


// Display de stats

void show_stats(){
  FILE * fp;
  int nr_of_games;
  int nr_of_games_won;
  fp = fopen ("da.ta", "r+");
  fscanf(fp, "%d %d", &nr_of_games, &nr_of_games_won);
  printf("Aantal gespeelde spelletjes: %d\n", nr_of_games);
  printf("Aantal gewonnen spelletjes: %d\n", nr_of_games_won);
  fclose(fp);
}



void handle_input() {
	char command;
	int x, y;
	char input_buffer[20];
	/* Lees het commando van de gebruiker in */
	fgets(input_buffer, 20, stdin);
	sscanf(input_buffer, "%c %i %i", &command, &x, &y);

  switch (command) {
	case 'F': // Flag
   if (((x < 0) || (x > WIDTH) || (y < 0) || (y > HEIGHT))){ // Chack voor geldige input.
    printf("Invalid input.\n");
    }
    else {
		flag_coordinate(x, y);
    }
		break;
	case 'R': // Reveal
   if (((x < 0) || (x > WIDTH) || (y < 0) || (y > HEIGHT))){ // Chack voor geldige input.
    printf("Invalid input.\n");
    }
    else {
		reveal_coordinate(x, y);
    }
		break;
	case 'P': // Print
		print_grid();
    draw_grid(); // DEBUG
		break;
  case 'E': // Exit
    update_stats();
    exit(0); // Programma wordt afgesloten met code 0 = succes.
    break;
  case 'B': // Boem! Alle mijnen ontploffen
    printf("BOEM! \n");
    dead = 1;
    print_grid();
    break;
	default:
		/* De speler gaf een commando in dat niet begrepen werd door deze functie: probeer opnieuw. */
		printf("Command '%c' not understood, please try again.\n", command);
		handle_input();
	}
}
