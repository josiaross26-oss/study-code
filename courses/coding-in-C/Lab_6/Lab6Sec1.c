#include <stdio.h>

//WICHTIG LAUT PAUL: BEI JEDEM FEHLER CHECK EIN FCLOSE REINMACHEN!!!
//FEHLER BENENNEN -> FINDET MAN EINFACHER
//WÜRDE SICH LOHNEN NICHT RETURN, SONDERN EXIT ZU NEHMEN



int main() {
    //fprintf
    FILE *schreiben1 = fopen("versuch.txt", "w");
    
    if (schreiben1 == NULL)
    {
        printf("Fehler");
        return 1; 
    }
    
    if (fprintf(schreiben1, "%d %d %d", 42, 12, 11) < 0) 
    {
        printf("Fehler");
    }

    if (fclose(schreiben1) != 0)
    {
        printf("Fehler");
    }


    //fscanf
    FILE *lesen1 = fopen("versuch.txt", "r");

    if (lesen1 == NULL)
    {
        printf("Fehler");
        return 1; 
    }

    int zahl[3] = {0};
    
    if (fscanf(lesen1, "%d %d %d", &zahl[0], &zahl[1], &zahl[2]) != 3) //3, weil 3 Werte gelesen werden müssen
    {
        printf("Fehler");
    }
    
    printf("%d %d %d", zahl[0], zahl[1], zahl[2]);
    
    if (fclose(lesen1) != 0)
    {
        printf("Fehler");
    }





    printf("\n");





    //fputc
    FILE *schreiben2 = fopen("versuch.txt", "w");

    if (schreiben2 == NULL)
    {
        printf("Fehler");
        return 1; 
    }

    if (fputc('J', schreiben2) == EOF) 
    {
        printf("Fehler");
    }

    if (fclose(schreiben2) != 0)
    {
        printf("Fehler");
    }


    //fgetc
    FILE *lesen2 = fopen("versuch.txt", "r");
    
    if (lesen2 == NULL)
    {
        printf("Fehler");
        return 1; 
    }

    int buchstabe = fgetc(lesen2);

    if (buchstabe == EOF) 
    {
        if (feof(lesen2)) 
        {
            printf("Dateiende erreicht\n");
        }
        
        else 
        {
            printf("Fehler beim Lesen\n");
        }
    }

    else
    {
    printf("%c", buchstabe);
    }

    if (fclose(lesen2) != 0)
    {
        printf("Fehler");
    }





    printf("\n");

    //fputs
    FILE *schreiben3 = fopen("versuch.txt", "w");
    
    if (schreiben3 == NULL)
    {
        printf("Fehler");
        return 1; 
    }

    char satz_schreiben[] = "Ich bin Josia\n";

    if (fputs(satz_schreiben, schreiben3) == EOF)
    {
        printf("Fehler");
    }

    if (fputs("Ich bin schon alt\n", schreiben3) == EOF)
    {
        printf("Fehler");
    }

    if (fclose(schreiben3) != 0)
    {
        printf("Fehler");
    }

    //fgets
    FILE *lesen3 = fopen("versuch.txt", "r");

    if (lesen3 == NULL)
    {
        printf("Fehler");
        return 1; 
    }

    char satz_lesen1[50];
    char satz_lesen2[50];
    
    if (fgets(satz_lesen1, sizeof(satz_lesen1), lesen3) == NULL)
    {
        printf("Fehler");
    }

    if (fgets(satz_lesen2, sizeof(satz_lesen2), lesen3)  == NULL)
    {
        printf("Fehler");
    }

    printf("%s", satz_lesen1);
    printf("%s", satz_lesen2);

    if (fclose(lesen3) != 0)
    {
        printf("Fehler");
    }

    return 0;
}