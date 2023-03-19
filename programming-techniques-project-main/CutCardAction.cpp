#include "CutCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"

CutCardAction::CutCardAction(ApplicationManager* pApp) :Action(pApp)
{
}

void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Click on the Card you want to Copy ");
}

void CutCardAction::Execute()
{
	ReadActionParameters();

	Grid*pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	CellPosition pos = (pGrid->GetInput())->GetCellClicked();
	Cell* pCell = pGrid->GetCellFromPosition(pos);
	if (pCell == NULL)
	{
		pOut->PrintMessage("Invalid Cell Clicked");
		return;
	}
	pcard =  pCell->HasCard();

	if (pcard == NULL)
	{
		pGrid->PrintErrorMessage("The Cell you clicked on doesn't have a Card");
	}

	else 
	{
		pGrid->SetClipboard(pcard);
		pGrid->PrintErrorMessage("Card is added to clipboard. Click to continue.");
		pGrid->RemoveObjectFromCell(pos);
		pGrid->UpdateInterface();
	}

}


CutCardAction::~CutCardAction()
{
}



