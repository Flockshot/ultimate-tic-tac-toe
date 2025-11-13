/* Muhammad Somaan 2528404
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */
#pragma once

#include "Board.h"
#include "Board.cpp"

#define SIZE 3

class SmallBoard : public Board<Player>
{
private:
	void calculateStatus();

public:
	SmallBoard(int boardNumber, char blankChar, Player* player1, Player* player2);
	SmallBoard(const SmallBoard& smallBoardVar);

	int operator!();
	SmallBoard& operator=(const SmallBoard& smallBoard);
	SmallBoard operator+(const SmallBoard& smallBoard);
	SmallBoard operator-(const SmallBoard& smallBoard);

	void play(PlayerNumber playerNum, int position);

	vector<string> calculatePrint() const;
};

