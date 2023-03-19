#include "PasteCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "ApplicationManager.h"
#include "AddCardAction.h"
#include "CopyCardAction.h"
#include "CutCardAction.h"
#include "Delete.h"


PasteCardAction::PasteCardAction(ApplicationManager* pApp) :Action(pApp)
{
}

void PasteCardAction::ReadActionParameters()
{
	Grid*pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
}

void PasteCardAction::Execute()
{
	ReadActionParameters();

	Grid*pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Click on the Cell Position you want to put the Card in"); //definition for the Cell position the user want to paste the Card in
	NewPos = (pGrid->GetInput())->GetCellClicked();
	Cell* pCell = pGrid->GetCellFromPosition(NewPos);
	if (pCell == NULL)
	{
		pOut->PrintMessage("Invalid Cell Clicked");
		return;
	}

	//cell is valid? another card in it? 
	//chech for snake, ladder and card

	if (pCell->HasCard() || pCell-> HasSnake() || pCell-> HasLadder())//is valid true -> if there is a game object
	{
		pGrid->PrintErrorMessage("The Cell you clicked on Already Has an Object");
		return;
	}
	Card* newCard = pGrid->GetClipboard()->Clone(NewPos);
	if (pGrid->AddObjectToCell(newCard));
		pOut->PrintMessage("Card Pasted Successfully");
}


PasteCardAction::~PasteCardAction()
{
}

