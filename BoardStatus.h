/* Muhammad Somaan 2528404
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */
#pragma once

enum BoardStatus
{
	IN_PROGRESS,
	DRAW,
	P1_WON,
	P2_WON
};

const char* boardStatusInText(BoardStatus status);