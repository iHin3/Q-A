// Header file for Quiz class
// Isaac Hine

#ifndef QUIZ_H_
#define QUIZ_H_

#include <string>
#include <iostream>

class Quiz {
	private:
		std::string question{""}; // Defaults to empty string
		std::string answer{""}; // Defaults to empty string
		static int score;

	public:
		Quiz();
		Quiz(std::string q, std::string a);
		std::string getQuestion();
		std::string getAnswer();
		static int getScore();
		static void updateScore(int val);


		friend std::string printResult(int question, int correct, int wrong); // Friend of Quiz function to gain access to variable score needed
};

#endif