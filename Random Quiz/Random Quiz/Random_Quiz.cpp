#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int random_generator(vector<string>& questions) {
	srand((unsigned)time(0));
	int random_integer = rand() % questions.size();
	return random_integer;
}

int main() {
	ifstream ifs;
	string name;
	string line;
	string answer;
	int numb;
	int score = 50;
	vector<string> questions;
	vector<string> answers;
	vector<int> solved;
	bool game_over = false;

	/*
	get lines of Questions and Answers from a text file and stores it in vector
	*/
	ifs.open("C:\\Users\\geonw\\Desktop\\List_of_Questions.txt");
	if (!ifs) {
		cout << "Error: The file cannot be openned" << endl;
		exit(1);
	}
	while (getline(ifs, line)) {
		questions.push_back(line);
	}
	ifs.close();

	ifs.open("C:\\Users\\geonw\\Desktop\\List_of_Answers.txt");
	if (!ifs) {
		cout << "Error: The file cannot be openned" << endl;
		exit(1);
	}
	while (getline(ifs, line)) {
		answers.push_back(line);
	}
	ifs.close();
	/*
	getting user name and introducing the game rule
	*/
	cout << "Hello old sports! What is your name?: ";
	cin >> name;
	cout << "Nice to meet you " << name << "! So, you came to play Rand Quiz right?" << endl;
	cout << "Of course you did! So, here is the rule, I'll give you 50 points to start with." << endl;
	cout << "If you lose too many points, like below 0, you'll lose!" << endl << "But if you gain more than 100 points, " << endl;
	cout << "the victory is yours!" << endl;
	cout << "Simple? Right? Now, lets begin the game!" << endl << endl;
	/*
	generate random integers to be used for questions
	*/
	while (game_over == false) {
		numb = random_generator(questions);
		if (find(solved.begin(), solved.end(), numb) == solved.end()) {
			cout << questions[numb];
			cin >> answer;
			if (answer == answers[numb]) {
				score = score + 5;
				cout << "Well done " << name << ", that is verily corect! You gained 5 points." << endl;
				cout << "Now, you have " << score << " points." << endl;
				solved.push_back(numb);
			}
			else if (score < 0) {
				cout << "That is wrong...I'm sorry old sports but you lost too many points..but good luck next time!" << endl;
				game_over = true;
			}
			else {
				score = score - 5;
				cout << "That is wrong " << name << "! You lost 5 points." << endl << "Now, you have " << score << " points." << endl;
				solved.push_back(numb);
			}
		}
	}
	return 0;
}