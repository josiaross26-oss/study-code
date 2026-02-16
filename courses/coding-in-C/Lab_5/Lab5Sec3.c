#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {

    //Initialisierungen
    int zahlenfolge[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int *p_zahlenfolge = zahlenfolge;
    int speicher_array[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int *p_speicher_array = speicher_array;
    int anzahl_timesteps = 10;

    //Start des Timers
    srand(time(NULL));

    //Einstellung des Startzustandes
    for (int i=2; i<7; i=i+2){
        zahlenfolge[i] = 1;
    }

    //Printen des Startzustandes
    printf("Time 0: ");

    for (int i=0; i<10; i++) {
        printf("%d ", zahlenfolge[i]);
    }

    printf("\n\n");

    for (int j=1; j<anzahl_timesteps; j++) { //Anzahl an Timesteps festlegen

        for (int i=0; i<10; i++) { //Schleife, um alle Stellen druchzugehen
            int zufall = rand() % 2; //Um zu ermitteln, ob eine 1 nach links oder nach rechts rücken soll
            if (p_zahlenfolge[i] == 1) { //Um nur Einsen zu verschieben
                if (zufall == 0) { //Wenn eine 0 ermittelt wurde, dann verschiebung der 1 nach links
                    if (i != 0) { //Wenn die 1 schon ganz links ist, dann soll sie nicht verschoben werden
                        if (p_zahlenfolge[i-1] == 1 || p_speicher_array[i-1] == 1) { //wenn an der Stelle, an die sie geschoben wird, schon eine 1 steht
                            printf("Kollision an Stelle %d\n\n", i); //dann soll angezeigt werden, dass sie kollidieren
                        }
                        p_speicher_array[i-1] = 1; //Eins wird nach links verschoben
                    }
                    else {
                        p_speicher_array[i] = 1; //Wenn eine 1 ganz links steht, dann soll die da bleiben
                    }
                } 
                else { //Wenn eine 1 ermittelt wurde, dann Verschiebung nach rechts
                    if (i != 9) { //Wenn die 1 schon ganz rechts ist, dann soll sie nicht verschoben werden
                        if (p_zahlenfolge[i+1] == 1 || p_speicher_array[i+1] == 1) { //Wenn an der Stelle rechts schon eine 1 steht, dann kommt es zu einer Kollision
                            printf("Kollision an Stelle %d\n\n", i+1); //Hierdurch wird sie angezeigt
                        }
                        p_speicher_array[i+1] = 1; //1 nach rechts verschieben
                    }
                    else {
                        p_speicher_array[i] = 1; //Wenn eine 1 ganz rechts steht, dann soll die da bleiben
                    }
                }
            }
        }

        for (int i=0; i<10; i++) {
            p_zahlenfolge[i] = p_speicher_array[i]; //Übertragung vom Temporären Array in das finale Array
        }

        for (int i=0; i<10; i++) {
            p_speicher_array[i] = 0; //Zurücksetzen des Temporären Arrays
        }

        //Printen des Timesteps mit finalem Array
        printf("Time %d: ", j);

        for (int i=0; i<10; i++) {
            printf("%d ", zahlenfolge[i]);
        }

        printf("\n\n");
    }
    return 0;
}