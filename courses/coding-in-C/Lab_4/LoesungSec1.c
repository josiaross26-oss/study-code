/*
 * File: LoesungSec1.c
 * Description: Zusammenhang zwischen Pointer und Arrays lernen
 */
#include <stdio.h>

/**
 * @brief ließt einen String ein
 * @param[out] param2 zu verändernder String
 */
void string_uebergeben(char *p_satz)
{
    p_satz[1] = 'c';
}


int main()
{
    char satz[28] = "Curly bird catches the worm";
    int groesse_satz = 28;
    char *p_satz = satz;

    /*
    for (int i=0; i<groesse_satz; i++)
    {
        printf("%c", satz[i]);
    }

    printf("\n");

    for (int i = 0; i<groesse_satz; i++)
    {
    printf("%c", *(p_satz+i));
    }
    */

    printf("%s", satz);
    printf("\n%s", p_satz);

    p_satz[0] = 'E';
    p_satz[1] = 'a';

    printf("\n%s", satz);

    string_uebergeben(satz);

    char satz2[30] = "AAtions speak louder than words";

    string_uebergeben(satz2);

    printf("\n%s", satz2);

    return 0;
}