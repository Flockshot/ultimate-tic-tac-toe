/* Muhammad Somaan  2528404
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */
#include "BigBoard.h"

BigBoard::BigBoard(int boardNumber, char blankChar, Player* player1, Player* player2) : Board(boardNumber, blankChar, player1, player2)
{
	int smallBoardNumber = 0;
	for (int x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < SIZE; y++)
		{
			smallBoardNumber++;
			board[x][y] = new SmallBoard(smallBoardNumber, blankChar, player1, player2);
		}
	}
}

BigBoard::BigBoard(const BigBoard& bigBoardVar) : Board(bigBoardVar)
{
	for (int x = 0; x < SIZE; x++)
		for (int y = 0; y < SIZE; y++)
			board[x][y] = new SmallBoard(*bigBoardVar.board[x][y]);

}




BigBoard& BigBoard::operator=(const BigBoard& bigBoard)
{
	if (this == &bigBoard)
		return *this;

	deleteMem();

	this->player1 = bigBoard.player1;
	this->player2 = bigBoard.player2;
	this->blankChar = bigBoard.blankChar;

	setBoardNumber(bigBoard.getBoardNumber());
	setStatus(bigBoard.getStatus());
	setWonBy(bigBoard.getWonBy());
	setOccupiedSlots(bigBoard.getOccupiedSlots());

	for (int x = 0; x < SIZE; x++)
		for (int y = 0; y < SIZE; y++)
			board[x][y] = new SmallBoard(*bigBoard.board[x][y]);

	return *this;
}

BigBoard BigBoard::operator+(const BigBoard& bigBoard)
{
	BigBoard newBoard(this->getBoardNumber(), blankChar, player1, player2);

	for (int x = 0; x < SIZE; x++)
		for (int y = 0; y < SIZE; y++)
			*(newBoard.board[x][y]) = *(this->board[x][y]) + *(bigBoard.board[x][y]);
		
	newBoard.calculateStatus();

	return newBoard;
}

BigBoard BigBoard::operator-(const BigBoard& bigBoard)
{
	BigBoard newBoard(this->getBoardNumber(), blankChar, player1, player2);

	for (int x = 0; x < SIZE; x++)
		for (int y = 0; y < SIZE; y++)
			*(newBoard.board[x][y]) = *(this->board[x][y]) - *(bigBoard.board[x][y]);

	newBoard.calculateStatus();

	return newBoard;
}



void BigBoard::play(PlayerNumber playerNum, int boardNumber, int position)
{
	int x = 0;
	int y = 0;
	calculatePosition(boardNumber, x, y);

	board[x][y]->play(playerNum, position);

	if (board[x][y]->getStatus() == DRAW)
		!(*board[x][y]);

	if (board[x][y]->getStatus() != IN_PROGRESS)
		setOccupiedSlots(getOccupiedSlots() + 1);


	calculateStatus();
}



vector<string> BigBoard::calculatePrint() const
{
	vector<string> print;
	
	for (int x = 0; x < SIZE; x++)
	{
		vector<string> row = board[x][0]->calculatePrint();

		for (int y = 1; y < SIZE; y++)
		{
			vector<string> current = board[x][y]->calculatePrint();

			for (int i =0; i<row.size(); i++)
				row[i] = row[i] + "     " + current[i];
		}

		row.push_back(""); //Empty line for pretty printing
		for (int i = 0; i < row.size(); i++)
			print.push_back(row[i]);
	}

	return print;
}



void BigBoard::calculateStatus()
{
	if (getStatus() != IN_PROGRESS)
		return;

	PlayerNumber playerWon = NONE;

	bool win = false;


	//In case of addition and subtraction, 2 players can win simultaneously
	bool horizontalDifWins = false;
	PlayerNumber horizontalPlayer = NONE;
	bool verticalDifWins = false;
	PlayerNumber verticalPlayer = NONE;


	//Checks board horizontally		
	for (int x = 0; x < SIZE; x++)
	{
		bool horizontal = true;
		SmallBoard* sBoard = board[x][0];

		if (sBoard->getWonBy() == NONE)
			continue;

		for (int y = 0; y < SIZE; y++)
			horizontal = horizontal && sBoard->getWonBy() == board[x][y]->getWonBy();

		if (horizontal)
		{
			if (horizontalPlayer != NONE)
			{
				if (horizontalPlayer != sBoard->getWonBy())
					horizontalDifWins = true;
			}

			win = true;
			//if won, then make the same status of BigBoard as the SmallBoard, either P1_WON or P2_WON
			horizontalPlayer = sBoard->getWonBy();
			playerWon = sBoard->getWonBy();
		}
	}

	//Checks board vertically		
	for (int y = 0; y < SIZE; y++)
	{
		bool vertical = true;
		SmallBoard* sBoard = board[0][y];

		if (sBoard->getWonBy() == NONE)
			continue;

		for (int x = 0; x < SIZE; x++)
			vertical = vertical && sBoard->getWonBy() == board[x][y]->getWonBy();

		if (vertical)
		{
			if (verticalPlayer != NONE)
			{
				if (verticalPlayer != sBoard->getWonBy())
					verticalDifWins = true;
			}

			win = true;
			verticalPlayer = sBoard->getWonBy();
			playerWon = sBoard->getWonBy();
		}
	}

	//Checks board diagonally
	bool diagonal = true;
	bool diagonal1 = true;
	SmallBoard* sBoard = board[(SIZE - 1) / 2][(SIZE - 1) / 2];

	if (sBoard->getWonBy() != NONE)
	{
		for (int x = 0; x < SIZE; x++)
			diagonal = diagonal && sBoard->getWonBy() == board[x][x]->getWonBy();
		for (int x = 0, y = SIZE - 1; x < SIZE; x++, y--)
			diagonal1 = diagonal1 && sBoard->getWonBy() == board[x][y]->getWonBy();

		if (diagonal || diagonal1)
		{
			win = true;
			playerWon = sBoard->getWonBy();
		}
	}
	
	if (horizontalDifWins || verticalDifWins)
	{
		setStatus(DRAW);
		return;
	}

	if (win)
	{
		setWonBy(playerWon);
		setStatus(playerWon == P1 ? P1_WON : P2_WON);
	}
	else if (getOccupiedSlots() == SIZE * SIZE)
		setStatus(DRAW);
}




void BigBoard::deleteMem()
{
	for (int x = 0; x < SIZE; x++)
		for (int y = 0; y < SIZE; y++)
			delete board[x][y];
}

BigBoard::~BigBoard() {
	deleteMem();
}

