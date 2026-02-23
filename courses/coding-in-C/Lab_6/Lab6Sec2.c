#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float fuel_level;
    float max_fuel_level; 
    char model[20];
} car; 

void refuel(car *auto1, float fuel_neu)
{
    if (auto1->fuel_level + fuel_neu <= auto1->max_fuel_level)
    {
        auto1->fuel_level = auto1->fuel_level + fuel_neu;
    }
}

void ausgeben(car auto1) 
{
    printf("%.2f ", auto1.fuel_level);
    printf("%.2f", auto1.max_fuel_level);
    printf(" %s", auto1.model);
    printf("\n\n");
}


int main() 
{
    car auto1 = {1.5, 60.0, "Mercedes-Benz"};
    ausgeben(auto1);
    float fuel_neu = 60;
    refuel(&auto1, fuel_neu);
    ausgeben(auto1);
   
   
   



    return 0;
}