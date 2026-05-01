/*
* File: Lab1Sec3.cpp
* Description: Programm das dir deinen Status anzeigt
*/

#include <iostream>
#include <cstdint>
#include <limits>

namespace validation 
{
    const std::uint16_t MAX_KID = 17;
    const std::uint16_t MAX_ADULT = 60;

    /**
     * @brief Prüft, ob der Nutzer erwachsen ist
     * 
     * @param[in] age  Alter das geprüft werden soll
     * @return         true wenn der Nutzer erwachsen ist, false wenn nicht
     */
    bool isAdult(std::uint16_t age)
    {
        if (age > MAX_KID && age < MAX_ADULT)
        {
            return true;
        }

        return false;
    }

    /**
     * @brief Prüft, ob der Nutzer Opa ist
     * 
     * @param[in] age  Alter das geprüft werden soll
     * @return         true wenn der Nutzer OPA ist, false wenn nicht
     */
    bool isSenior(std::uint16_t age)
    {
        if (age > MAX_ADULT -1)
        {
            return true;
        }

        return false;
    }
}

int main()
{
    const std::uint8_t MAX_ALTER = 120;
    std::uint16_t alter = 0;
    bool zustand = false; 

    std::cout << "Gebe dein Alter ein:" << std::endl;
    
    while (zustand == false)
    {
        if (!(std::cin >> alter))
        {
            std::cout << "Bitte gebe ein realistisches Alter ein!" << std::endl; //prüft, ob das einlesen geklappt hat, da uint8_t verwendet wurde, klappt das einlesen nur, wenn auch eine Zahl eingegeben wurde -> Buchstaben werden abgelehnt
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            zustand = false;
        }

        else if (alter > MAX_ALTER)
        {
            std::cout << "Bitte gebe ein realistisches Alter ein!\n";
            zustand = false;
        }

        else
        {
            zustand = true; 
        }
    }

    if (validation::isAdult(alter) == true)
    {
        std::cout << "Du bist " << alter << " Jahre alt.\nDas heißt, du bist ein Erwachsener.\n";
    }
    
    else if (validation::isSenior(alter) == true)
    {
        std::cout << "Du bist " << alter << " Jahre alt.\nDas heißt, du bist ein Opa.\n";
    }

    else 
    {
        std::cout << "Du bist " << alter << " Jahre alt.\nDas heißt, du bist ein Kind.\n";
    }

    return 0; 
}