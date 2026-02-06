#include <stdio.h>


int main() {
    float f_nummer1 = 0;
    float f_nummer2 = 0;
    char c_operator = 0;

    printf("Gebe die erste Zahl ein: ");
    if (scanf("%f", &f_nummer1) != 1) {
        printf("Bitte gebe eine Zahl ein!");
        return 0;
    }
    printf("\nGebe die zweite Zahl ein: ");
    if (scanf("%f", &f_nummer2) != 1) {
        printf("Bitte gebe eine Zahl ein!");
        return 0;
    }
    printf("\nGebe die Operation ein ('+', '-', '*','/'): ");
    scanf(" %c", &c_operator);

    if (c_operator == '+')  {
        printf("Das Ergebnis von %.2f + %.2f = %.2f", f_nummer1, f_nummer2, f_nummer1+f_nummer2);
    }

    else if (c_operator == '-')  {
        printf("Das Ergebnis von %.2f - %.2f = %.2f", f_nummer1, f_nummer2, f_nummer1-f_nummer2);
    }

    else if (c_operator == '*')  {
        printf("Das Ergebnis von %.2f * %.2f = %.2f", f_nummer1, f_nummer2, f_nummer1*f_nummer2);
    }

    else if (c_operator == '/' && f_nummer2 != 0)  {
        printf("Das Ergebnis von %.2f / %.2f = %.2f", f_nummer1, f_nummer2, f_nummer1/f_nummer2);
    }

    else if (c_operator == '/' && f_nummer2 == 0)  {
        printf("Keine Lösung, du darfst nicht durch 0 teilen!");
    }

    else {
        printf("Du hast leider den falschen Operator gewählt, starte das Programm erneut");
    }

    return 0;
}