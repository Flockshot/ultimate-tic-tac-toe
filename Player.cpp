/* Muhammad Somaan 2528404
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */
#include "Player.h"

Player::Player(string playerName, char playerChar)
{
	this->playerName = playerName;
	this->playerChar = playerChar;
}


string Player::getPlayerName() {
	return playerName;
}
void Player::setChar(char playerChar) {
	this->playerChar = playerChar;
}

char Player::getChar() {
	return playerChar;
}
void Player::setPlayerName(string playerName) {
	this->playerName = playerName;
}








