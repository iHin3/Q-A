// Main file for project2 Quiz Game
// Isaac Hine

#include "Quiz.h"
#include "printResult.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <algorithm>


int main(int argc, char const *argv[]) {

srand(unsigned(time(0)));
std::string userAnswer;
int ques = 0; // Number of questions
int wAnswers; // Number of wrong Answers
int cAnswers; // Number of correct Answers
std::fstream quiz; // Name to read in file opening
quiz.open(argv[1]); // Reads in .txt file from command
std::vector<Quiz> quizVector; // Create vector to get question and answers as objects
while(!(quiz.eof())) { // Loops in questions and answers until end of .txt file line
    std::string question;
    std::string answer;
    
    getline(quiz, question); // Reads in question lines
    getline(quiz, answer); // Reads in answer lines
    question.erase(0,3); // Deletes Q: 
    answer.erase(0,3); // Deletes A:

    Quiz quizNow(question, answer);

    quizVector.push_back(quizNow); // Puts questions and answers gained as objects in vector
}

std::random_shuffle(quizVector.begin(), quizVector.end()); // Randomly Shuffles Question and Answers in Vector

for(auto n : quizVector) {
    int temp = 0; // Variable to store points in score
    std::cout << n.getQuestion() << std::endl;
    getline(std::cin, userAnswer);
    ques += 1; // Update number of questions
    if(userAnswer == n.getAnswer()) {
        temp += 1;
        cAnswers += 1; // Updates correct answers
        n.updateScore(temp); // Takes variable holding points into updateScore function
        std::cout << "Correct!" << std::endl;
        std::cout << "CurrentScore: " << n.getScore() << std::endl;
    }
    else {
        temp -= 1;
        wAnswers += 1; // Updates wrong answers
        n.updateScore(temp); // Takes variable holding points into updateScore function
        std::cout << "Wrong! Correct Answer: " << n.getAnswer() << std::endl;
        std::cout << "Current score: " << n.getScore() << std::endl;
    }
}

std::cout << printResult(ques, cAnswers, wAnswers) << std::endl; // Read in printResult function

    return 0;
}