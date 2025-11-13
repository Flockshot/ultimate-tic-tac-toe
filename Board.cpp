/* Muhammad Somaan 2528404
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */
#include "Board.h"

template<class T>
Board<T>::Board(int boardNumber, char blankChar, Player* player1, Player* player2) : Playable(player1, player2)
{
	this->blankChar = blankChar;

	this->boardNumber = boardNumber;
	this->status = IN_PROGRESS;	
	this->occupiedSlots = 0;
}

template<class T>
Board<T>::Board(const Board& boardVar) : Board(boardVar.boardNumber, boardVar.blankChar, boardVar.player1, boardVar.player2)
{
	this->status = boardVar.getStatus();
	this->occupiedSlots = boardVar.occupiedSlots;

	//Function of parent class.
	setWonBy(boardVar.getWonBy());	
}



template<class T>
void Board<T>::calculatePosition(int position, int& x, int& y)
{	
	if (position > SIZE * SIZE || position < 1)
		throw INVALID_POSITION;

	position--;
	x = std::floor(position / SIZE);
	y = position % SIZE;
}


template<class T>
void Board<T>::print() const
{
	vector<string> toPrint = calculatePrint();

	for (vector<string>::iterator i = toPrint.begin(); i != toPrint.end(); ++i)
		cout << *i << endl;
}


template<class T>
int Board<T>::getBoardNumber() const{
	return boardNumber;
}
template<class T>
void Board<T>::setBoardNumber(int boardNumber) {
	this->boardNumber = boardNumber;
}

template<class T>
int Board<T>::getOccupiedSlots() const{
	return occupiedSlots;
}
template<class T>
void Board<T>::setOccupiedSlots(int slots) {
	this->occupiedSlots = slots;
}

template<class T>
BoardStatus Board<T>::getStatus() const{
	return status;
}
template<class T>
void Board<T>::setStatus(BoardStatus status) {
	this->status = status;
}