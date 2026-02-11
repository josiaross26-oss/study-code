/*
 * File: LoesungSec1.c
 * Description: Palindrom erkennen
 */
#include <stdio.h>

void einlesen(char wort[])
{
    printf("Gebe dein Wort ein\n");
    fgets(wort, 101, stdin);
}

void auswerten(char wort[], int laenge)
{
    int hilfsvariable = 0;
    while (wort[hilfsvariable] == wort[laenge])
    {
        hilfsvariable++;
        laenge--;
        if (hilfsvariable == laenge || hilfsvariable+1 == laenge)
        {
            printf("Dein Wort ist ein Palindrom");
        }
    }
    if (hilfsvariable != laenge) 
        {
            printf("Dein Wort ist kein Palindrom");
        }
}

int main()
{
    char wort[101];
    einlesen(wort);
    int laenge = 0;
    laenge = sizeof(wort);
    auswerten(wort, laenge);
    printf("%s", wort);
    return 0;
}
