#include <iostream>
#include <string>
#include <cstdint>
#include "header.h"


int main()
{
    std::string name;
    std::uint_fast16_t homework = 0;
    std::uint_fast16_t midterm = 0;
    std::uint_fast16_t finalExam = 0;
    readStudentData(name, homework, midterm, finalExam);

    return 0;
}