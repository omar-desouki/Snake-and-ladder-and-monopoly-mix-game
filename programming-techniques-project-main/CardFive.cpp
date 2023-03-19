#include "CardFive.h"
#include"Ladder.h"
#include"Snake.h"
#include "Player.h"

CardFive::CardFive()
{
	cardNumber = 5;
}

CardFive::CardFive(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number 
}

CardFive::~CardFive()
{
}



void CardFive
	::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid,pPlayer);


	int RolledNum=pPlayer->GetJustRolledDiceNum();
	CellPosition newPosition = pPlayer->GetCell()->GetCellPosition();
	newPosition.AddCellNum(-RolledNum);
	pGrid->UpdatePlayerCell(pPlayer, newPosition);

	if (pPlayer->GetCell()->GetGameObject() != NULL)
	{
		pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);
	}
}

Card* CardFive::Clone(CellPosition newPosition)
{
	Card* newCard = new CardFive(newPosition);
	return newCard;
}