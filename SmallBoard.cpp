/* Muhammad Somaan 2528404
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */
#include "SmallBoard.h"


SmallBoard::SmallBoard(int boardNumber, char blankChar, Player* player1, Player* player2) : Board(boardNumber, blankChar, player1, player2)
{	
}

SmallBoard::SmallBoard(const SmallBoard& smallBoardVar) : Board(smallBoardVar)
{
	for (int x = 0; x < SIZE; x++)
		for (int y = 0; y < SIZE; y++)
			board[x][y] = smallBoardVar.board[x][y];
}



int SmallBoard::operator!()
{
	//p1 is X, and p2 is O.
	int p1 = 0;
	int p2 = 0;
	int position = 0;
	
	for (int x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < SIZE; y++)
		{
			position++;
			p1 += board[x][y] == player1 ? (position) : 0;
			p2 += board[x][y] == player2 ? (position) : 0;
		}
	}

	bool p1Won = p1 > p2;

	if (p1Won)
		setStatus(P1_WON);
	else
		setStatus(P2_WON);

	return p1Won;
}

SmallBoard& SmallBoard::operator=(const SmallBoard& smallBoard)
{
	if (this == &smallBoard)
		return *this;

	this->player1 = smallBoard.player1;
	this->player2 = smallBoard.player2;
	this->blankChar = smallBoard.blankChar;

	setBoardNumber(smallBoard.getBoardNumber());
	setStatus(smallBoard.getStatus());
	setWonBy(smallBoard.getWonBy());
	setOccupiedSlots(smallBoard.getOccupiedSlots());

	for (int x = 0; x < SIZE; x++)
		for (int y = 0; y < SIZE; y++)
			board[x][y] = smallBoard.board[x][y];
	
	return *this;
}

SmallBoard SmallBoard::operator+(const SmallBoard& smallBoard)
{
	SmallBoard newBoard(this->getBoardNumber(), blankChar, player1, player2);

	//P1 is X and P2 is O
	if (this->getWonBy() == P1 || smallBoard.getWonBy() == P1)
	{
		newBoard.setWonBy(P1);
		newBoard.setStatus(P1_WON);
	}
	else if (this->getWonBy() == P2 || smallBoard.getWonBy() == P2)
	{
		newBoard.setWonBy(P2);
		newBoard.setStatus(P2_WON);
	}
	//by default the won by is set to NONE, (in case of EMPTY and EMPTY)

	return newBoard;
}

SmallBoard SmallBoard::operator-(const SmallBoard& smallBoard)
{
	SmallBoard newBoard(this->getBoardNumber(), blankChar, player1, player2);

	//P1 is X and P2 is O
	if (this->getWonBy() == P2 || smallBoard.getWonBy() == P2)
	{
		newBoard.setWonBy(P2);
		newBoard.setStatus(P2_WON);
	}
	else if (this->getWonBy() == P1 || smallBoard.getWonBy() == P1)
	{
		newBoard.setWonBy(P1);
		newBoard.setStatus(P1_WON);
	}
	//by default the won by is set to NONE, (in case of EMPTY and EMPTY)

	return newBoard;
}



void SmallBoard::play(PlayerNumber playerNum, int position)
{
	if (getStatus() != IN_PROGRESS)
		throw BOARD_FINISHED;

	int x = 0;
	int y = 0;
	calculatePosition(position, x, y);
	
	if (board[x][y] == player1 || board[x][y] == player2)
		throw PLACE_TAKEN;

	board[x][y] = getPlayer(playerNum);
	setOccupiedSlots(getOccupiedSlots() + 1);
	calculateStatus();
}



vector<string> SmallBoard::calculatePrint() const
{
	vector<string> print;

	string heading = "Board " + to_string(getBoardNumber()) + ": " + boardStatusInText(getStatus());
	print.push_back(heading);

	for (int i = 0; i < SIZE; i++)
	{
		string y = "     ";
		for (int j = 0; j < SIZE; j++)
		{
			if (board[i][j] == player1 || board[i][j] == player2)
				y += board[i][j]->getChar();
			else
				y += blankChar;
			y += " ";
		}
		y += "     ";
		print.push_back(y);
	}

	return print;
}



void SmallBoard::calculateStatus()
{
	if (getStatus() != IN_PROGRESS)
		return;

	Player* playerWon = NULL;

	bool win = false;

	//Checks board horizontally
	for (int x = 0; x < SIZE; x++)
	{
		bool horizontal = true;
		Player *p = board[x][0];

		if (p == NULL)
			continue;

		for (int y = 0; y < SIZE; y++)
			horizontal = horizontal && p == board[x][y];

		if (horizontal)
		{			
			win = true;
			playerWon = p;
			break;
		}
	}

	//Checks board vertically
	for (int y = 0; y < SIZE; y++)
	{
		bool vertical = true;
		Player* p = board[0][y];

		if (p == NULL)
			continue;

		for (int x = 0; x < SIZE; x++)
			vertical = vertical && p == board[x][y];

		if (vertical)
		{			
			win = true;
			playerWon = p;
			break;
		}
	}

	//Checks board diagonally
	bool diagonal = true;
	bool diagonal1 = true;
	Player* p = board[(SIZE - 1) / 2][(SIZE - 1) / 2];

	if (p != NULL)
	{
		for (int x = 0; x < SIZE; x++)
			diagonal = diagonal && p == board[x][x];
		for (int x = 0, y = SIZE - 1; x < SIZE; x++, y--)
			diagonal1 = diagonal1 && p == board[x][y];

		if (diagonal || diagonal1)
		{
			win = true;
			playerWon = p;
		}
	}

	if (win)
	{
		
		if (playerWon == player1)
		{
			setStatus(P1_WON);
			setWonBy(P1);
		}			
		else if (playerWon == player2)
		{
			setStatus(P2_WON);
			setWonBy(P2);
		}
	}
	else if (getOccupiedSlots() == SIZE * SIZE)
		setStatus(DRAW);
	
}


