#include "Ladder.h"
#include <fstream>
#include "Player.h"

Ladder::Ladder()
{

}

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a ladder. Click to continue ...");

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	Cell* pCell = pGrid->GetCellFromPosition(endCellPos);
	if (pCell->GetGameObject() != NULL)
	{
		pCell->GetGameObject()->Apply(pGrid, pPlayer);
	}
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}
GameObjectType Ladder::GetType()
{
	return LADDER;
}

void Ladder::Save(ofstream& OutFile, GameObjectType type)
{
	if (type == LADDER)
		OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
}

void Ladder::Load(ifstream& Infile)
{
	int startCell, endCell;
	Infile >> startCell >> endCell;
	position = CellPosition(startCell);
	endCellPos = CellPosition(endCell);
}

bool Ladder::AreOverlapping(GameObject* Obj) const
{
	Ladder* newLadder = dynamic_cast<Ladder*> (Obj);
	if (newLadder)
	{
		int oldHcell = this->endCellPos.HCell();
		int newHcell = newLadder->endCellPos.HCell();
		if (newHcell == oldHcell) //first check if hcell are the same
		{
			int oldStartVcell = this->endCellPos.VCell(); //to get vcell of the old object start pos
			int oldEndVcell = this->position.VCell(); //to get vcell of the old object //end pos
			int newStartVcell = newLadder->endCellPos.VCell(); //to get vcell of the //new object start pos
			int newEndVcell = newLadder->position.VCell(); //to get vcell of the //new object //end pos
			for (int i = oldStartVcell; i <= oldEndVcell; i++)
			{
				for (int j = newStartVcell; j <= newEndVcell; j++)
				{
					if (i == j) //if this condition happens then they overlapped
						return true;
				}
			}
		}
	}
	return false;
	
}  



Ladder::~Ladder()
{
}
