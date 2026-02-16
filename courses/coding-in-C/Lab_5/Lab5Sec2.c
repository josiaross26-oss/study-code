/*
 * File: main.c
 * Description: Informationen über Wörter innerhalb eines Satzes
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) 
{
    if (argc < 2) {
        printf("Falsch, mindestens zwei Arumgente einfügen");
        return 1;
    }

    for (int i = 1; i<argc; i++) {
        printf("%s ", argv[i]);
    }

    printf("\n");  

    for (int i = 1; i<argc; i++) {
        printf("%s ", *(argv+1));
    }

    printf("\n\n"); 

    for (int i=0; i<argc; i++) {
        printf("Das Argument %d an der Adresse %p hat den Inhalt: %s (Länge: %ld)\n", i, &argv[i], argv[i], strlen(argv[i]));
    }

    return 0;
}

