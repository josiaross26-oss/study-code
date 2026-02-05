#include <stdio.h>


int main() {
    float f_nummer1;
    float f_nummer2;
    char c_operator;

    printf("Gebe die erste Zahl ein: ");
    if (scanf("%f", &f_nummer1) != 1) {
        printf("Gebe eine Zahl ein");
        return 0;
    }
    printf("\nGebe die zweite Zahl ein: ");
    if (scanf("%f", &f_nummer2) != 1) {
        printf("Bitte gebe eine Zahl ein");
        return 0;
    }
    printf("\nGebe die Operation ein ('+', '-', '*','/'): ");
    scanf(" %c", &c_operator);

    switch (c_operator) {
        case '+':
            printf("Das Ergebnis von %.2f + %.2f = %.2f\n\n", f_nummer1, f_nummer2, f_nummer1+f_nummer2);
            break;

        case '-':
            printf("Das Ergebnis von %.2f - %.2f = %.2f\n\n", f_nummer1, f_nummer2, f_nummer1-f_nummer2);
            break;
        
        case '*':
            printf("Das Ergebnis von %.2f * %.2f = %.2f\n\n", f_nummer1, f_nummer2, f_nummer1*f_nummer2);
            break;

        case '/':
            printf("Das Ergebnis von %.2f / %.2f = %.2f\n\n", f_nummer1, f_nummer2, f_nummer1/f_nummer2);
            break;
        
        default: 
            printf("Keine Lösung, du darfst nicht durch 0 teilen!\n\n");
            break;
    }

    return 0;
}