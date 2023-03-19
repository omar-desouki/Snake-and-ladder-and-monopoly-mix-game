#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager* pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	int x, y;
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (pGrid->GetEndGame())
	{
		return;
	}
	// -- If not ended, do the following --:

	// 2- Generate a random number from 1 to 6 --> This step is done for you
	else
	{
		srand((int)time(NULL)); // time is for different seed each run
		int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed

		// 3- Get the "current" player from pGrid
		Player* pPlayer = pGrid->GetCurrentPlayer();
		Cell* pCell = pPlayer->GetCell();
		if (pPlayer->getUnrollNum() != 0 && pPlayer->getUnrollNum() != 5)
		{
			pPlayer->Move(pGrid, 0);
			pPlayer->setUnrollNum(pPlayer->getUnrollNum() - 1);
			pGrid->AdvanceCurrentPlayer();
			return;
		}
		CellPosition cellpositin = pCell->GetCellPosition();
		int cellnum = cellpositin.GetCellNum();
		if (cellnum + diceNumber >= 100)
		{
			switch (pPlayer->getPlayerNum())
			{
			case 0:
			{
				pGrid->GetOutput()->PrintMessage("WINNER IS PLAYER 0 , Click anywhere to end...");
				pGrid->GetInput()->GetPointClicked(x, y);
				pGrid->SetEndGame(true);
				pGrid->GetOutput()->ClearStatusBar();
				pManager->ExecuteAction(EXIT);
				return;
			}
			case 1:
			{
				pGrid->GetOutput()->PrintMessage("WINNER IS PLAYER 1, Click anywhere to end...");
				pGrid->GetInput()->GetPointClicked(x, y);
				pGrid->SetEndGame(true);
				pGrid->GetOutput()->ClearStatusBar();
				pManager->ExecuteAction(EXIT);
				return;
			}
			case 2:
			{
				pGrid->GetOutput()->PrintMessage("WINNER IS PLAYER 2, Click anywhere to end...");
				pGrid->GetInput()->GetPointClicked(x, y);
				pGrid->SetEndGame(true);
				pGrid->GetOutput()->ClearStatusBar();
				pManager->ExecuteAction(EXIT);
				return;
			}
			case 3:
			{
				pGrid->GetOutput()->PrintMessage("WINNER IS PLAYER 3, Click anywhere to end...");
				pGrid->GetInput()->GetPointClicked(x, y);
				pGrid->SetEndGame(true);
				pGrid->GetOutput()->ClearStatusBar();
				pManager->ExecuteAction(EXIT);
				return;
			}

			}
		}
		else
		{
			pPlayer->Move(pGrid, diceNumber);
			pPlayer->SetCell(pPlayer->GetCell());
			if (pPlayer->getUnrollNum() == 5)
			{
				pPlayer->setUnrollNum(0);
			}
			pGrid->AdvanceCurrentPlayer();
		}
		// 4- Move the currentPlayer using function Move of class player

		// 5- Advance the current player number of pGrid


		// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
	}
}

RollDiceAction::~RollDiceAction()
{
}
