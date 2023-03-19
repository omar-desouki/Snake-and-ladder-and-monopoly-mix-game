#pragma once
#include "card.h"
class CardSeven : public Card
{
public:
	CardSeven();
	CardSeven(const CellPosition & pos); // A Constructor takes card position

	//it doesn't have parameters so it doesn't have read card parameters fn

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	// by decrementing the player's wallet by the walletAmount data member

	Card* Clone(CellPosition newPosition);
	virtual ~CardSeven(); // A Virtual Destructor
};