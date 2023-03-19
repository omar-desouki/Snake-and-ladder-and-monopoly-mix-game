#pragma once
#include "Card.h"
class CardFour :
	public Card
{
public:
	CardFour();
	CardFour(const CellPosition& pos); // A Constructor takes card position


	virtual void Apply(Grid* pGrid, Player* pPlayer);

	Card* Clone(CellPosition newPosition);



	virtual ~CardFour(); // A Virtual Destructor
};


