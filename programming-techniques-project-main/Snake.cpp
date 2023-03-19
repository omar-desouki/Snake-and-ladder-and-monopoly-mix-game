#include "Snake.h"
#include <fstream>
#include "Card.h"

Snake::Snake()
{
}

Snake::Snake(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{

	if (startCellPos.GetCellNum() > endCellPos.GetCellNum() && startCellPos.HCell() == endCellPos.HCell())
	{
		this->endCellPos = endCellPos;
	}

	///TODO: Do the needed validation
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position,endCellPos); //inverted
}

void Snake::Apply(Grid* pGrid, Player* pPlayer) 
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a Snake. Click to continue ..." and wait mouse click

	pGrid->PrintErrorMessage("You have reached a Snake. Click to continue ...");

	// 2- Apply the ladder's effect by moving the player to the endCellPos

	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	Cell* pCell = pGrid->GetCellFromPosition(endCellPos);
	if (pCell->GetGameObject() != NULL)
	{
		pCell->GetGameObject()->Apply(pGrid, pPlayer);
	}

	//    Review the "pGrid" functions and decide which function can be used for that

}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

GameObjectType Snake::GetType()
{
	return SNAKE;
}

void Snake::Save(ofstream& OutFile, GameObjectType type)
{
	if (type == SNAKE)
		OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
}

void Snake::Load(ifstream& Infile)
{
	int startCell, endCell;
	Infile >> startCell >> endCell;
	position = CellPosition(startCell);
	endCellPos = CellPosition(endCell);
}


bool Snake::AreOverlapping(GameObject* Obj) const
{
	Snake* newSnake = dynamic_cast<Snake*> (Obj);
	if (newSnake)
	{
		int oldHcell = this->endCellPos.HCell();
		int newHcell = newSnake->endCellPos.HCell();
		if (newHcell == oldHcell)
		{
			int oldStartVcell = this->endCellPos.VCell();
			int oldEndVcell = this->position.VCell();
			int newStartVcell = newSnake->endCellPos.VCell();
			int newEndVcell = newSnake->position.VCell();
			for (int i = oldEndVcell; i <= oldStartVcell; i++)//for loops anre inverted in the snake file compared to the ladder file
			{
				for (int j = newEndVcell; j <= newStartVcell; j++)
				{
					if (i == j)
						return true;
				}
			}
		}
	}

	return false;
}

Snake::~Snake()
{
}
