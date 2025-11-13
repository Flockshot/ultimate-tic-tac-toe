/* Muhammad Somaan 2528404
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */
#pragma once

enum Exception {

	PLACE_TAKEN,
	BOARD_FINISHED,
	INVALID_POSITION,
	INVALID_INPUT
};

void printExceptionMessage(Exception e);