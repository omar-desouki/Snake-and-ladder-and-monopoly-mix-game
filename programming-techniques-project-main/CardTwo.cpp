#include "CardTwo.h"
#include <iostream>
#include "Ladder.h"
using namespace std;


CardTwo::CardTwo()
{
	cardNumber = 2;
}

CardTwo::CardTwo(CellPosition position): Card(position)
{
	cardNumber = 2;
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Ladder* pLadder = pGrid->GetNextLadder(position);
	if (pLadder != NULL) {
		pGrid->UpdatePlayerCell(pPlayer, pLadder->GetPosition());
		pLadder->Apply(pGrid, pPlayer);
	}
}

Card* CardTwo::Clone(CellPosition newPosition)
{
	CardTwo* newCard = new CardTwo(newPosition);
	return newCard;
}