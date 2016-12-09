#include "printer.h"
/*
 * In dit bestand kan je de functie print_grid uit printer.h implementeren.
 */

 void print_grid(){

  // Variabelen voor de werking van de for loop.
   int width_counter;
   int height_counter;

   // Variabelen voor de nummering van kolommen en rijen.
   int a;
   int b;

   a = 0; // Wordt gebruikt om het juiste cijfer bij de juiste kolom weer te geven.

 /* Print aantal resterende vlaggen */
   printf("Aantal resterende vlaggen: %d \n", nr_of_flags);

 /* Print de bovenste rij cijfers */
   printf("  ");
   while(a<=( WIDTH - 1)) // Print over de geheele breedte van het veld cijfers af.
   {
   printf("%d", a); // Print nummer kolom.
   printf("  ");
   ++a; // Verhoog a.
   }

   printf("\n");

 /* Print de rest van het raster */
   height_counter=0;
   b = 0; // Wordt gebruikt om het juiste cijfer bij elke rij te zetten.
   while(height_counter<=(HEIGHT - 1)) // Terwijl de height_counter kleiner of gelijk is aan dan de hoogte - 1, wordt de rij genummerd en worden de juiste elementen in de rij geprint.
 {
   width_counter=0;
   printf("%d", b); // Print nummer rij.
   while(width_counter<=(WIDTH - 1)) // Terwijl de width_counter kleiner of gelijk is aan WIDTH - 1, worden de elementen van de rij geprint.
     {
       /* Wanneer de cel een flag heeft */
       if (get_cell(width_counter, height_counter)->state  == FLAGGED)
       {
         printf("|F|");
       }

       /* Wanneer de cel een mijn is en een mijn ontploft is (en de speler dus dood is) */
       else if ((get_cell(width_counter, height_counter)->is_mine == 1) && (dead == 1))
       {
       printf("|M|");
       }

       /* Wanneer de cel uncovered is */
       else if (get_cell(width_counter, height_counter)->state  == UNCOVERED)
       {
         printf("|%d|",(get_cell(width_counter, height_counter)->neighbouring_mines));
       }

       /* Wanner de cel covered is */
       else
       {
         printf("| |");
       }
       width_counter++; // Ga verder in de rij.
     }

     printf("\n");
     height_counter++; // Ga naar de volgende kolom.
     b++; // Verhoog b
 }
   printf("\n");
 }
