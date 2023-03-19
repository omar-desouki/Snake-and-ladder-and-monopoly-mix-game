#include "SwitchToPlayMode.h"

SwitchToPlayMode::SwitchToPlayMode(ApplicationManager* pApp):Action(pApp)
{
}

void SwitchToPlayMode::ReadActionParameters()
{
	//No parameters
}

void SwitchToPlayMode::Execute()
{

	Grid* pGrid = pManager->GetGrid();    //Get a Pointer to the Output and Grid
	Output* pOut = pGrid->GetOutput();

	pOut->CreatePlayModeToolBar();
	pManager->ExecuteAction(START_GAME);

}

SwitchToPlayMode::~SwitchToPlayMode()
{
}
