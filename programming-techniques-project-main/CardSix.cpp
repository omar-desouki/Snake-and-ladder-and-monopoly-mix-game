#include "CardSix.h"
#include "Output.h"
#include <fstream>

CardSix::CardSix()
{
	cardNumber = 6;
}

CardSix::CardSix(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number (1 here)
}

CardSix::~CardSix()
{
}

void CardSix::ReadCardParameters(Grid * pGrid)
{
    Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("New CardSix: Enter Cell Num To Go to : ");
	CellToGoTo = pGrid->GetInput()->GetInteger(pOut);
	pOut->ClearStatusBar();
}

void CardSix
	::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid,pPlayer);

	pGrid->UpdatePlayerCell(pPlayer,CellToGoTo);
	Cell* pCell = pGrid->GetCellFromPosition(CellToGoTo);
	if (pCell->GetGameObject() != NULL)
	{
		pCell->GetGameObject()->Apply(pGrid, pPlayer);
	}

	
}
void CardSix::Load(ifstream& Infile)
{
	Card::Load(Infile);
	Infile >> CellToGoTo;
}


void CardSix::Save(ofstream& OutFile, GameObjectType type)
{
	if (type == CARD)
		OutFile << GetCardNumber() << " " << position.GetCellNum() << " " << CellToGoTo << endl;
}

Card* CardSix::Clone(CellPosition newPosition)
{
	CardSix* newCard = new CardSix(newPosition);
	newCard->SetCellToGoTo(CellToGoTo);
	return newCard;
}

void CardSix::SetCellToGoTo(int cellNum)
{
	CellToGoTo = cellNum;
}
