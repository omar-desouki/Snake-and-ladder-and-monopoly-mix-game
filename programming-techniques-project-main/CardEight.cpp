#include "CardEight.h"
#include "ApplicationManager.h"
#include "RollDiceAction.h"
#include <fstream>


CardEight::CardEight()
{
	cardNumber = 8;
}

CardEight::CardEight(const CellPosition& Position) : Card(Position) // set the cell position of the card
{
	cardNumber = 8; // set the inherited cardNumber data member with the card number
}

CardEight::~CardEight(void)
{
}

void CardEight::ReadCardParameters(Grid* pGrid)
{

	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("New CardEight: Enter Amount of coins to go out of prison : ");
	AmountOfCoins = pGrid->GetInput()->GetInteger(pOut);
	pOut->ClearStatusBar();
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	pGrid->GetOutput()->PrintMessage("Enter 1 to pay specific amount of coins to go out of the prison or Enter 2 stay in prison ");
	int Choice = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	switch (Choice)
	{
	case 1:

		pPlayer->SetWallet(pPlayer->GetWallet() - AmountOfCoins);
		pGrid->PrintErrorMessage("Prison Fees paid. Click to continue");
		return;

	case 2:

		if (pPlayer->getUnrollNum() == 0)
		{
			pPlayer->setUnrollNum(3);
		}
		pGrid->PrintErrorMessage("Player in prison. Click to continue");
		return;

	}
}
void CardEight::Load(ifstream& Infile)
{
	Card::Load(Infile);
	Infile >> AmountOfCoins;
}


void CardEight::Save(ofstream& OutFile, GameObjectType type)
{
	if (type == CARD)
		OutFile << GetCardNumber() << " " << position.GetCellNum() << " " << AmountOfCoins << endl;
}

void CardEight::SetAmountOfCoins(int amount)
{
	AmountOfCoins = amount;
}

Card* CardEight::Clone(CellPosition newPosition)
{
	CardEight* newCard = new CardEight(newPosition);
	newCard->SetAmountOfCoins(AmountOfCoins);
	return newCard;
}
