#pragma once
#include <iostream>
#include <string>
#include <cmath>

enum Chess_Pieces { P, R, KN, B, Q, K, Empty };
enum Player_Color { White, Black, None };

using namespace std;

class Square {
	Chess_Pieces piece;
	Player_Color color;
	int x, y;

public:

	Square(int _x, int _y, Chess_Pieces p, Player_Color c): piece(p), color(c) {};
	Square(int _x, int _y) : x(_x), y(_y), piece(Empty), color(None) {};
	Square() {};
	int getValueX() {
		return x;
	}
	void printMe() {
		if (piece == KN) {
			cout << "A fearsome knight at " << getValueX() << ", " << y << endl;
		}
	};

};

class Board {
	Square board[8][8];

public:
	bool game_end() {
		return false;
	}
	Square * getSquare(int x, int y) {
		return &board[x][y];
	}
	void setSquare(Square* s, int x, int y) {
		board[x][y] = *s;
	}
};
