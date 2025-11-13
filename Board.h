/* Muhammad Somaan 2528404
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */
#pragma once

#include <vector>
#include "string"

#include "BoardStatus.h"
#include "Playable.h"
#include "Exception.h"

#define SIZE 3

template<class T>
class Board : public Playable
{
private:
	int boardNumber;

	BoardStatus status;
	int occupiedSlots;

protected:	
	char blankChar;

	T* board[SIZE][SIZE];		

	void setBoardNumber(int boardNumber);
	void setStatus(BoardStatus status);
	void setOccupiedSlots(int slots);

	void calculatePosition(int position, int& x, int& y);

	virtual void calculateStatus() = 0;

public:
	Board(int boardNumber, char blankChar, Player* player1, Player* player2);
	Board(const Board& boardVar);

	virtual vector<string> calculatePrint() const = 0;
	void print() const;	

	int getBoardNumber() const;
	BoardStatus getStatus() const;
	int getOccupiedSlots() const;


};
