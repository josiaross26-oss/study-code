/*
 * File: LoesungSec1.c
 * Description: Palindrom erkennen
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * @brief Funktion ließt ein Wort ein
 * @param[in] laenge Adresse einer Variable wird übergeben, in der die Länge des Arrays gespeichert wird
 * @param[in, out]  wort Array, in dem das eingegebene Wort gespeichert wird
 */
void einlesen(char wort[], int *p_laenge)
{
    printf("Gebe dein Wort ein\n");
    if (fgets(wort, 101, stdin) == 0)
    {
        printf("Gebe ein richtiges Wort ein");
        exit(1);
    }
    *p_laenge = strlen(wort)-2;
}

/**
 * @brief Wertet das eingegebene Wort aus und gibt an, ob es sich um ein Palindrom handelt oder nicht
 * @param[in]  wort Array, das das Wort enthält und analysiert wird
 * @param[in]  laenge Anzahl der Buchstaben im Wort
 */
void auswerten(char wort[], int laenge)
{
    int hilfsvariable = 0;

    while (wort[hilfsvariable] != '\0')
    {
        wort[hilfsvariable] = tolower(wort[hilfsvariable]);
        hilfsvariable++;
    }

    hilfsvariable = 0;

    while (wort[hilfsvariable] == wort[laenge])
    {
        if (hilfsvariable == laenge || hilfsvariable+1 == laenge)
        {
            printf("Dein Wort ist ein Palindrom");
            break;
        } 
        
        else 
        {
            hilfsvariable++;
            laenge--;
        }
    }
    if (wort[hilfsvariable] != wort[laenge]) 
    {
        printf("Dein Wort ist kein Palindrom");
    }
}

int main()
{
    char wort[101];
    int laenge = 0;
    einlesen(wort, &laenge);
    auswerten(wort, laenge);
    return 0;
}