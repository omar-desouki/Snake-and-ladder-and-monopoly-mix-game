#include "Card.h"
#include <fstream>
#include <iostream>


Card::Card()
{
}

Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
}

void Card::SetCardNumber(int cnum)
{
	if(cnum < 12  && cnum > 0)
		cardNumber = cnum; // needs validation
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{
	pOut->DrawCell(position, cardNumber);


	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"


}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}
 GameObjectType Card ::GetType()
{
	 return CARD;
}
 void Card::Load(ifstream& Infile)
 { 
	 int cellNum;
	 Infile >> cellNum;
	 position = CellPosition(cellNum);

 }

 void Card::Save(ofstream& OutFile, GameObjectType type) 
 {
	 if (type == CARD)
		 OutFile << GetCardNumber() << " " << position.GetCellNum() << endl;
 }

Card::~Card()
{
}
