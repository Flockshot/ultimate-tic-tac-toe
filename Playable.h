/* Muhammad Somaan 2528404
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */
#pragma once

#include "Player.h"
#include "PlayerNumber.h"

class Playable
{
private:
	PlayerNumber wonBy;

protected:
	Player* player1;
	Player* player2;	

	void setWonBy(PlayerNumber wonBy);
	Player* getPlayer(PlayerNumber playerNum);

public:
	Playable(Player* player1, Player* player2);

	PlayerNumber getWonBy() const;
};

