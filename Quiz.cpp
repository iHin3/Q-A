// Main file for Quiz header
// Isaac Hine

#include "Quiz.h"

// Initial Score Value
int Quiz::score = 0;

// Get Functions

int Quiz::getScore() {
    return score;
}
std::string Quiz::getQuestion() {
    return question;
}
std::string Quiz::getAnswer() {
    return answer;
}

// Update Score Function

void Quiz::updateScore(int val) { 
    if(val > 0) { // Updates score by 1 if val is any positive number
        score += val;
    }
    else if(val < 0) { // Updates score by -1 if val is any negative number
        if(score != 0) { // Makes sure score does not go lower than 0
            score--;
        }
    }
}

// Default and constructors
Quiz::Quiz() {
    question = "";
    answer = "";
}
Quiz::Quiz(std::string q, std::string a) {
    question = q;
    answer = a;
}
