#include "CardThree.h"
CardThree::CardThree()
{
	cardNumber = 3;
}
CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number (1 here)
}

CardThree::~CardThree(void)
{
}

void CardThree::ReadCardParameters(Grid* pGrid)
{

	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("New CardThree: Roll again :");
	pOut->ClearStatusBar();

}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);
	pGrid->AdvanceCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();
}

Card* CardThree::Clone(CellPosition newPosition)
{
	CardThree* newCard = new CardThree(newPosition);
	return newCard;
}
