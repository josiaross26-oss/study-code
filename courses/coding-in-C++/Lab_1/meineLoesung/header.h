#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <cstdint>

void readStudentData(std::string& name, std::uint_fast16_t& homework, std::uint_fast16_t& midterm, std::uint_fast16_t& finalExam);

void readScore(const std::string& text, std::uint_fast16_t& score);



#endif