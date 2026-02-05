#include <stdio.h>


int main() {
    float f_nummer1;
    float f_nummer2;
    char c_operator;

    printf("Gebe die erste Zahl ein: ");
    scanf("%f", &f_nummer1);
    printf("\nGebe die zweite Zahl ein: ");
    scanf("%f", &f_nummer2);
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