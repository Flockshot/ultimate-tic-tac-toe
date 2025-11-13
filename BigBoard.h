/* Muhammad Somaan 2528404
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */
#pragma once

#include "SmallBoard.h"

#define SIZE 3

class BigBoard : public Board<SmallBoard>
{
private:

	void calculateStatus();
	void deleteMem();

public:

	BigBoard(int boardNumber, char blankChar, Player* player1, Player* player2);
	BigBoard(const BigBoard& bigBoardVar);

	BigBoard& operator=(const BigBoard& bigBoard);
	BigBoard operator+(const BigBoard& bigBoard);
	BigBoard operator-(const BigBoard& bigBoard);

	void play(PlayerNumber playerNum, int boardNumber, int position);

	vector<string> calculatePrint() const;
	
	~BigBoard();
};

