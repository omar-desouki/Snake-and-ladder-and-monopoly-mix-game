#include "Delete.h"

#include "Input.h"
#include "Output.h"
#include "GameObject.h"

Delete::Delete(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}
Delete::~Delete()
{

}
void Delete::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the GameObjCell parameter
	pOut->PrintMessage("Deleting GameObject");
	GameObjCell = pIn->GetCellClicked();
	///Make the needed validations on the read parameters
	if (GameObjCell.IsValidCell() == 0 )
	{
		pGrid->PrintErrorMessage("Error: Invalid Cell/ Cell does not have game object...");
		return;
	}
	pOut->ClearStatusBar();
}
void Delete::Execute()
{

	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid(); 
	pGrid->RemoveObjectFromCell(GameObjCell);
	pGrid->UpdateInterface();
}