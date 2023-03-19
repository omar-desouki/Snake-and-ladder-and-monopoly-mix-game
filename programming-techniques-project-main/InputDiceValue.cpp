#include "InputDiceValue.h"

#include "Grid.h"
#include "Player.h"

InputDiceValue::InputDiceValue(ApplicationManager *pApp) : Action(pApp)
{
}

void InputDiceValue::ReadActionParameters()
{
}

void InputDiceValue::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* po =pGrid->GetOutput();
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
		pGrid->GetOutput()->PrintMessage("ENTER A NUMBER BETWEEN 1 AND 6");
		int inputnum = (pGrid->GetInput()->GetInteger(po));
		while (inputnum < 1 || inputnum>6)
		{
			pGrid->GetOutput()->PrintMessage("PLEASE ENTER A NUMBER BETWEEN 1 AND 6");
		        inputnum = (pGrid->GetInput()->GetInteger(po));
		}
		if (cellnum + inputnum >= 100)
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
			pPlayer->Move(pGrid, inputnum);
			pPlayer->SetCell(pPlayer->GetCell());
			if (pPlayer->getUnrollNum() == 5)
			{
				pPlayer->setUnrollNum(0);
			}
			pGrid->AdvanceCurrentPlayer();
			return;
		}
		
		// 4- Move the currentPlayer using function Move of class player

		// 5- Advance the current player number of pGrid


		// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
	}
}

InputDiceValue::~InputDiceValue()
{
}

