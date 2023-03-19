#pragma once
#include "Card.h"
#include <time.h>
#include "Action.h"
class CardThree :public Card
{
   
	public:
		CardThree();
		CardThree(const CellPosition& pos); // A Constructor takes card position

		virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

		virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
		Card* Clone(CellPosition newPosition);
														  // by decrementing the player's wallet by the walletAmount data member

		virtual ~CardThree(); // A Virtual Destructor
};

