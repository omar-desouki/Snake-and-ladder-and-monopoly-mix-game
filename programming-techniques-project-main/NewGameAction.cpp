#include "NewGameAction.h"

#include "Input.h"
#include "Output.h"
#include "ApplicationManager.h"
#include "Grid.h"
#include "Card.h"
#include"Player.h"
#include "Action.h"
#include "GameObject.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"


NewGameAction::NewGameAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

NewGameAction::~NewGameAction()
{

}

void NewGameAction::ReadActionParameters() 
{	

}


// Execute the action
void NewGameAction::Execute() 
{
	CellPosition O(8, 0);
	Grid* pGrid = pManager->GetGrid();
	if(pGrid->GetEndGame())  //Check if game has already ended
	{
	}
	else
	{


		for (int i = 0; i < MaxPlayerCount; i++)
		{
			// Update player's position to the fisrt tile
			pGrid->SetCurrPlayerNum(i);
			Player* CurrPlayer = pGrid->GetCurrentPlayer();
			pGrid->UpdatePlayerCell(CurrPlayer, O);
			Card * pCard;

			CurrPlayer->SetTurnCount(0);  
			CurrPlayer->SetStepCount(0);
			CurrPlayer->SetWallet(100); // Initially wallet with 100 coins
			pGrid->AdvanceCurrentPlayer();
		}
		pGrid->SetCurrPlayerNum(0);
		CardNine::SetCardbought(false);
		CardTen::SetCardbought(false);
		CardEleven::SetCardbought(false);
		CardNine::SetOwner(NULL);
		CardTen::SetOwner(NULL);
		CardEleven::SetOwner(NULL);
	}

}




