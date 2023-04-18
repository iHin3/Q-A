// Main file for printResult header
// Isaac Hine

#include "printResult.h"
#include "Quiz.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::string printResult(int questions, int correct, int wrong) { // Builds stringstream to output results of the Quiz
    std::stringstream ss;
    ss << std::endl << "Number of questions: " << questions << std::endl;
    ss << "Number of correct answers: " << correct << std::endl;
    ss << "Number wrong answers: " << wrong << std::endl;
    ss << "Final score: " << Quiz::score << std::endl;
    return ss.str();
}