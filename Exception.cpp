/* Muhammad Somaan 2528404
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */
#include "Exception.h"
#include <iostream>

void printExceptionMessage(Exception e)
{
	switch (e)
	{
		case PLACE_TAKEN:
			std::cout << "That place is already occupied, try again!\n";
			break;
		case BOARD_FINISHED:
			std::cout << "That board has already concluded, try again!\n";
			break;
		case INVALID_POSITION:
			std::cout << "Position cannot be less than 1 or greater than 9, please try again!\n";
			break;
		case INVALID_INPUT:
			std::cout << "Position must be an integer, please try again!\n";
			break;
	}	
}