#include "CardSeven.h"
#include "Output.h"
#include "Grid.h"
#include "Player.h" 
#include "CellPosition.h"

CardSeven::CardSeven()
{
	cardNumber = 7;
}

CardSeven::CardSeven(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number (1 here)
}

Card* CardSeven::Clone(CellPosition newPosition)
{
	Card* newCard = new CardSeven(newPosition);
	return newCard;
}

CardSeven::~CardSeven()
{
}



void CardSeven :: Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	int count=0;
	CellPosition CurrPlayerCell = ((pGrid->GetCurrentPlayer())->GetCell())->GetCellPosition();
	int CurrPlayercellnum = CellPosition::GetCellNumFromPosition(CurrPlayerCell);
	int min = 9999;
	Player* pPlayer2;

	for (int i=0; i<MaxPlayerCount-1; i++)
	{
		pGrid->SetCurrPlayerNum(i);

		CellPosition pos = pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition();

		int TempCellNum = CellPosition::GetCellNumFromPosition(pos);


		if (TempCellNum > CurrPlayercellnum)
		{
			if (TempCellNum < min)
			{
				min=TempCellNum;
				pPlayer2 = pGrid->GetCurrentPlayer();
				count = count+1;
			}
		}

	}
	if (count > 0 )
	{
		CellPosition O(8, 0);
		pGrid -> UpdatePlayerCell(pPlayer2,O);
		pPlayer2->setUnrollNum(0);
	}
	else
	{
		Output* pOut = pGrid->GetOutput();
		pOut->PrintMessage("There is no Player Positioned after the Player that stepped on Card no.7");
	}
}