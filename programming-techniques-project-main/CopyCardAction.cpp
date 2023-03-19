#include "CopyCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"

CopyCardAction::CopyCardAction(ApplicationManager* pApp) :Action(pApp)
{
}

void CopyCardAction::ReadActionParameters()
{
	Grid*pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Click on the Card you want to Copy ");
}

void CopyCardAction::Execute()
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
	}

}


CopyCardAction::~CopyCardAction()
{
}







