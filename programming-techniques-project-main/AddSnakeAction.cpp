#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();



	///TODO: Make the needed validations on the read parameters
	if (startPos.HCell() != endPos.HCell())
	{
		pGrid->PrintErrorMessage("Error: Snake's Start Cell and End Cell aren't in the Same Column! Click to continue...");
		return;
	}

	if (startPos.GetCellNum() == endPos.GetCellNum())
	{
		pGrid->PrintErrorMessage("Error: Snake's Start Cell and End Cell can't be the same  ! Click to continue... !");
		return;
	}	

	if (startPos.VCell() > endPos.VCell())
	{
		pGrid->PrintErrorMessage("Error: Snake's Start Cell must is above its End cell ! Click to continue...");
		return;
	}
	//there is an extra validation in the Excute fn


	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnakeAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Snake object with the parameters read from the user
	Snake * pSnake = new Snake(startPos, endPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager


	bool Snakesoverlapping = pGrid->AreGameObjectsOverlapping(pSnake); // check overlapping
	if (Snakesoverlapping)
	{
		pGrid->PrintErrorMessage("Error: there are two Snakes which are overlapping  ! Click to continue ...");
		return;
	}

	bool StartIsEnd = pGrid->IsSnakeStartSameASLadderEnd(endPos); 	// Check that the Snake's end is start of another Objects
	if (StartIsEnd)
	{
		pGrid->PrintErrorMessage("Error:Snakes's End cell of added Object can't be a start of another Ladder or Snake ! Click to continue ...");
		return;
	}


	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pSnake);

	// if the GameObject cannot be added
	if (! added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the Snake is created and added to the GameObject of its Cell, so we finished executing the AddSnakeAction

}
