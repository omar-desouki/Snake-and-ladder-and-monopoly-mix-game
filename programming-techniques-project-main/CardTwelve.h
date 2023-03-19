#pragma once
#include "Card.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"

class CardTwelve :
    public Card
{
public:
	CardTwelve();
	CardTwelve(CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);
	Card* Clone(CellPosition newPosition);
};

