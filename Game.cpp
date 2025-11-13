/* Muhammad Somaan 2528404
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */
#include "Game.h"

Game::Game(char blankChar, Player* player1, Player* player2) : Playable(player1, player2)
{
	roundNumber = 0;
	player1Wins = 0;
	player2Wins = 0;
	
	this->blankChar = blankChar;

	isFinished = false;

	for (int i = 0; i < ROUNDS; i++)
		round[i] = new BigBoard(i + 1, blankChar, player1, player2);

	srand(time(NULL));
}

void Game::start()
{
	cout << "Starting Game" << endl<<endl;
	printPlayerWins();

	for (int i = P1; i <= P2; i = i == P1 ? P2 : P1)
	{
		cout << endl << "Round: " << roundNumber + 1 << endl;

		if (roundNumber < ROUNDS - 1) //1st 2nd Round
		{
			round[roundNumber]->print();
			cout << endl << getPlayer(PlayerNumber(i))->getPlayerName() << "'s Turn." << endl;

			int boardNumber = 0;
			int cellNumber = 0;

			bool valid = false;

			while (!valid)
			{
				try
				{
					inputPosition(boardNumber, cellNumber);
					round[roundNumber]->play(PlayerNumber(i), boardNumber, cellNumber);
					valid = true;
				}
				catch (Exception e) {
					printExceptionMessage(e);
				}
			}
		}
		else if (roundNumber == ROUNDS - 1) // 3rd Round
		{
			//random check for + or - of boards;
			int addBoard = randomNumber(0, 1);

			if (addBoard)
			{
				cout << "Adding the boards together." << endl << endl;
				*round[2] = *round[0] + *round[1];
			}
			else
			{
				cout << "Subtracting the boards together." << endl << endl;
				*round[2] = *round[0] - *round[1];
			}
		}
		else
		{
			cout << "Since 3rd round was a tie, selecting winner randomly." << endl;

			setWonBy(PlayerNumber(randomNumber(1, 2))); //1 for P1, 2 for P2;
			isFinished = true;
			break;
		}

		checkRoundWin();

		if (isFinished)
			break;
	}

	

	cout << "\n-------------------------------------" << endl;
	cout << getPlayer(getWonBy())->getPlayerName() << " won the game." << endl;
	cout << "-------------------------------------" << endl << endl;
	
}

void Game::reset()
{
	deleteMem();

	roundNumber = 0;
	player1Wins = 0;
	player2Wins = 0;

	isFinished = false;

	for (int i = 0; i < ROUNDS; i++)
		round[i] = new BigBoard(i + 1, blankChar, player1, player2);
}



void Game::inputPosition(int& boardNumber, int& cellNumber)
{
	int input = 0;
	cout << "Enter boardNumber and cellNumber: example. 23"<<endl;
	cin >> input;
	cout << endl;
		
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		throw INVALID_INPUT;
	}

	boardNumber = input / 10;
	cellNumber = input % 10;		
}

void Game::checkRoundWin()
{
	if (round[roundNumber]->getStatus() == P1_WON)
	{
		round[roundNumber]->print();

		player1Wins++;
		roundNumber++;

		cout << "-------------------------------------" << endl;
		cout << player1->getPlayerName()<< " won round number "<<roundNumber<<endl;
		cout << "-------------------------------------" << endl << endl;
	}
	else if (round[roundNumber]->getStatus() == P2_WON)
	{
		round[roundNumber]->print();

		player2Wins++;
		roundNumber++;

		cout << "-------------------------------------" << endl;
		cout << player2->getPlayerName() << " won round number " << roundNumber<<endl;
		cout << "-------------------------------------" << endl << endl;
	}
	else if (round[roundNumber]->getStatus() == DRAW)
	{
		round[roundNumber]->print();
		roundNumber++;

		cout << "-------------------------------------" << endl;
		cout << "Round number " << roundNumber<< " is a tie."<<endl;
		cout << "-------------------------------------" << endl << endl;
	}

	printPlayerWins();

	checkGameWin();	
}

void Game::checkGameWin()
{
	if (player1Wins == 2 || player2Wins == 2)
	{
		setWonBy( player1Wins == 2 ? P1 : P2 );
		isFinished = true;
	}
}

void Game::printPlayerWins()
{
	cout << player1->getPlayerName() << " (" << player1->getChar() << "): " << player1Wins << endl;
	cout << player2->getPlayerName() << " (" << player2->getChar() << "): " << player2Wins << endl;
}

int Game::randomNumber(int lowerLimit, int upperLimit)
{
	return lowerLimit + (rand() % (upperLimit - lowerLimit + 1));
}


void Game::deleteMem()
{
	for (int i = 0; i < ROUNDS; i++)
		delete round[i];
}
Game::~Game()
{
	deleteMem();
}