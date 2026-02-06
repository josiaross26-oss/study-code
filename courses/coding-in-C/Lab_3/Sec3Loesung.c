#include <stdio.h>

float einlesen1(float f_nummer1) {
    printf("Gebe die erste Zahl ein: ");
    if (scanf("%f", &f_nummer1) != 1) {
        printf("Gebe eine Zahl ein");
    }
    return f_nummer1;
}

float einlesen2(float f_nummer2) {
    printf("\nGebe die zweite Zahl ein: ");
    if (scanf("%f", &f_nummer2) != 1) {
        printf("Bitte gebe eine Zahl ein");
    }
    return f_nummer2;
}

char einlesenOp(char c_operator) {
    printf("\nGebe die Operation ein ('+', '-', '*','/'): ");
    scanf(" %c", &c_operator);
    return c_operator;
}

void rechnen(float f_nummer1, float f_nummer2, char c_operator) {
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
            if (f_nummer2 == 0) printf("Keine Lösung, du darfst nicht durch 0 teilen!\n\n");
            else printf("Das Ergebnis von %.2f / %.2f = %.2f\n\n", f_nummer1, f_nummer2, f_nummer1/f_nummer2);
            break;
        
        default: 
            printf("Bitte gebe einen gültigen Operator ein\n\n");
            break;
    }
}

int main() {
    float f_nummer1 = 0;
    float f_nummer2 = 0;
    char c_operator = 0;

    f_nummer1 = einlesen1(f_nummer1);
    f_nummer2 = einlesen2(f_nummer2);
    c_operator = einlesenOp(c_operator);
    rechnen(f_nummer1, f_nummer2, c_operator);

    return 0;
}