#pragma once
#include "card.h"
class CardFive : public Card
{
public:
	CardFive();
	CardFive(const CellPosition & pos); // A Constructor takes card position

	//it doesn't have parameters so it doesn't have read card parameters fn

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	Card* Clone(CellPosition newPosition);
	                                                  // by decrementing the player's wallet by the walletAmount data member
	
	virtual ~CardFive(); // A Virtual Destructor
};

