#include <iostream>
#include <cstdint>
#include <string>
#include <limits> 
#include "header.h"

void readScore(const std::string& text, std::uint_fast16_t& score)
{
    const int MAX_SCORE = 100;

    while (true)
    {
        std::cout << text;

        if (!(std::cin >> score))
        {
            std::cout << "Fehler: Das war keine Zahl!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (score <= MAX_SCORE)
        {
            break;
        }

        std::cout << "Maximale Punktzahl überschritten\n";
    }
}

void readStudentData(std::string& name, std::uint_fast16_t& homework, std::uint_fast16_t& midterm, std::uint_fast16_t& finalExam)
{
    std::cout << "Gebe deinen Namen ein:\n";
    
    std::cin >> std::ws;
    if (!(std::getline(std::cin, name)))
    {
        std::cout << "Fehler beim einlesen des Namens\n";
    }

    readScore("Gebe die Note für Homework ein:\n", homework);
    readScore("Gebe die Note für Midterm ein:\n", midterm);
    readScore("Gebe die Note für Final exam ein:\n", finalExam);
}
