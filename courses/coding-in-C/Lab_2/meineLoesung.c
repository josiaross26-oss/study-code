#include <stdio.h>

char buchstaben[8] = {'A', 'B', 'C', 'D', 'E', 'F','G', 'H'};
int groesse = 8;

/*
int main() {
    
    for(int j = 0; j<8; j++) {
        for(int i = 0; i<8; i++) {
            printf("%c%d ", buchstaben[i], 8-j);
        }
        printf("\n");
    }
    

    return 0;
}


int main() {
    printf("    ");
    for (int i=0; i<8; i++) {
        printf("%-4c", buchstaben[i]);
    }
    printf("\n");
    for(int j = 0; j<8; j++) {
        printf("  +---+---+---+---+---+---+---+---+\n");           
        printf("%d ", 8-j);    
            if (j%2==0){
                printf("|###|   |###|   |###|   |###|   |");
            } else printf("|   |###|   |###|   |###|   |###|");
        printf(" %d\n", 8-j); 
        }
    printf("  +---+---+---+---+---+---+---+---+\n    ");
    for (int i=0; i<8; i++) {
        printf("%-4c", buchstaben[i]);
    }
    printf("\n");
}

*/


int main() {
    printf("    ");
    for (int i=0; i<groesse; i++) { //so oft wie Anzahl Spalten
        printf("%-4c", buchstaben[i]);  //Buchstaben A-H mit Abstand -4 -> Abstand nach der Zahl
    }
    printf("\n"); //neue Zeile

    for (int i=0; i<groesse; i++) { //so oft wie Anzahl Reihen
        printf("  +"); //erstes +, weil Anzahl + ungerade

        for(int j=0; j<groesse; j++) { //so oft wie Anzahl Spalten
            printf("---+");
        }
        printf("\n%d ",groesse-i); //neue Zeile und Nummerrierung Zeile
        for(int j=0; j<groesse; j++) { //so oft wie Anzahl Zeilen
            if (i%2==0 && j%2==0) printf("|###"); //wenn i und j(=Buchstabe A-H) gerade dann ###
            else if (i%2!=0 && j%2!=0) printf("|###"); ///wenn i und j ungerade dann ###
            else printf("|   "); //ansonsten leer
        }
        printf("| %d\n",groesse-i); //letzter Rahmen, da ungerade und Nummerrierung
    }
    printf("  +"); //Abschluss Rahmen unten da Anzahl ungerade
    for(int j=0; j<groesse; j++) { //so oft wie Anzahl Spalten
            printf("---+"); //Abschluss Rahmen unten
        }
    printf("\n    "); //neue Zeile + Leerzeichen
    for (int i=0; i<groesse; i++) { //Anzahl Spalten
        printf("%-4c", buchstaben[i]); //Nummerrierung Spalte mit Abstand -4 -> nach der Zahl
    }
    printf("\n"); //neue Zeile für Optik
}