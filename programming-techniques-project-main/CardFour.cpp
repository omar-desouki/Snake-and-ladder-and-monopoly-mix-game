#include "CardFour.h"

CardFour::CardFour()
{
	cardNumber = 4;
}

CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4;
}

CardFour::~CardFour(void)
{
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	if (pPlayer->getUnrollNum() == 0)
	{
		pPlayer->setUnrollNum(1);
	}
}

Card* CardFour::Clone(CellPosition newPosition)
{
	Card* newCard = new CardFour(newPosition);
	return newCard;
}
