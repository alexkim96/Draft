#include <iostream>
#include <string>
#include "chess.h"

using namespace std;


int main(int argc, char* const argv[]) {
	Board b;
	string s;
	Square knight( 2, 1, KN, White );
	Square d;
	bool game_end = false;
	while (game_end == false) {
		b.setSquare(&knight, 2, 1);
		knight.printMe();
		b.getSquare(2, 1)->printMe();
		cout << "Ready for next move?" << endl;
		cin >> s;
		if (b.game_end()) {
			cout << "Do you want to start a new game? Type 'yes' if you would like to play a new game." << endl;
			cin >> s;
			if (s != "yes") {
				game_end = true;
			}
		}
		
	}

}