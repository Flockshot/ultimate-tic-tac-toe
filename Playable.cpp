/* Muhammad Somaan 2528404
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */
#include "Playable.h"

Playable::Playable(Player* player1, Player* player2)
{
	this->player1 = player1;
	this->player2 = player2;
	wonBy = NONE;
}

Player* Playable::getPlayer(PlayerNumber playerNum)
{
	if (playerNum == P1)
		return player1;

	return player2;
}

PlayerNumber Playable::getWonBy() const{
	return wonBy;
}
void Playable::setWonBy(PlayerNumber wonBy) {
	this->wonBy = wonBy;
}