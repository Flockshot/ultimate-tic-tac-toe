/* Muhammad Somaan 2528404
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */
#pragma once

#include<time.h>

#include "BigBoard.h"

#define ROUNDS 3

class Game : public Playable
{
private:
	int player1Wins;
	int player2Wins;

	int roundNumber;
	
	char blankChar;

	bool isFinished;

	BigBoard *round[ROUNDS];

	int randomNumber(int lowerLimit, int upperLimit);


public:
	Game(char blankChar, Player* player1, Player* player2);

	void start();
	void reset();

	void inputPosition(int& boardNumber, int& cellNumber);
	void checkRoundWin();
	void checkGameWin();

	void printPlayerWins();

	void deleteMem();
	~Game();
	
};

