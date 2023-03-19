#include "CardEleven.h"
#include "ApplicationManager.h"
#include "RollDiceAction.h"
#include <fstream>

int CardEleven::CardPrice = 0;
int CardEleven::FeesToPay = 0;
bool CardEleven::Cardbought = false;
Player* CardEleven::Owner = false;
bool CardEleven::CardInitialized = NULL;

CardEleven::CardEleven()
{
	cardNumber = 11;
}

CardEleven::CardEleven(const CellPosition& Position) : Card(Position) // set the cell position of the card
{
	cardNumber = 11;   // set the inherited cardNumber data member with the card number
	CardPrice = 0;
	FeesToPay = 0;
	Cardbought = false;
	CardInitialized = false;
	Owner = NULL;
}

void CardEleven::SetCardbought(bool S)
{
	Cardbought = S;
}

void CardEleven::ReadCardParameters(Grid* pGrid)
{
	Input* pIn = pGrid->GetInput();   //Get Pointers to input and output
	Output* pOut = pGrid->GetOutput();


	if (CardInitialized != true)  //Initialize card values
	{
		pOut->PrintMessage("New CardEleven: Enter Card Price: ");
		CardPrice = pIn->GetInteger(pOut);
		pOut->PrintMessage("Enter Fees to pay by passing players: ");
		FeesToPay = pIn->GetInteger(pOut);
		CardInitialized = true;
	}


	while (FeesToPay < 0 || CardPrice < 0)  //Validaton (number enterd should be positive)
	{
		pGrid->PrintErrorMessage("Invalid! please enter a positive value ");
		pOut->PrintMessage("New CardEleven: Enter Card Price: ");
		CardPrice = pIn->GetInteger(pOut);
		pOut->PrintMessage("Enter Fees to pay by passing players: ");
		FeesToPay = pIn->GetInteger(pOut);
	}

	pOut->ClearStatusBar();  //clear status bar
}

void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{
	Input* pIn = pGrid->GetInput();   //Get Pointers to input and output
	Output* pOut = pGrid->GetOutput();

	if (Cardbought == true)
	{

		if (pPlayer != Owner)  //checks if the player is not the card owner
		{

			if (pPlayer->GetWallet() >= FeesToPay)  //checks if the player have enough money to pay fees
			{
				pPlayer->SetWallet(pPlayer->GetWallet() - FeesToPay);
				Owner->SetWallet(Owner->GetWallet() + FeesToPay);

				pGrid->PrintErrorMessage("Fees Paid");  //this function contains getpointclicked()

			}

			else
			{
				pGrid->PrintErrorMessage("You don't have enough money in your wallet to pay the fees!");
			}
		}
	}

	else
	{
		pOut->PrintMessage("Do you want to Buy the Card? Y/N");
		string C = pIn->GetString(pOut);

		if (C == "Y" || C == "y")
		{
			if (pPlayer->GetWallet() < CardPrice)  //checks if player have enough money to buy card
			{
				pGrid->PrintErrorMessage("You don't have enough money in your wallet to Buy the Card!");
			}
			else
			{
				Cardbought = true;
				pPlayer->SetWallet(pPlayer->GetWallet() - CardPrice);
				pGrid->PrintErrorMessage("Card Bought");

				Owner = pPlayer;  //Owner pointer now points towards current player
			}
		}
	}

}
void CardEleven::Load(ifstream& Infile)
{
	Card::Load(Infile);
	Infile >> CardPrice >> FeesToPay;
	CardInitialized = true;
}


void CardEleven::Save(ofstream& OutFile, GameObjectType type)
{
	if (type == CARD)
		OutFile << GetCardNumber() << " " << position.GetCellNum() << " " << CardPrice << " " << FeesToPay << endl;
}

Player* CardEleven::GetOwner()
{
	return Owner;
}


CardEleven::~CardEleven(void)
{
}

void CardEleven::SetOwner(Player* player)
{
	Owner = player;
}

int CardEleven::GetCellPrice()
{
	return CardPrice;
}

Card* CardEleven::Clone(CellPosition newPosition)
{
	Card* newCard = new CardEleven(newPosition);
	return newCard;
}
