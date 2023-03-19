#include "SwitchToDesignMode.h"

SwitchToDesignMode::SwitchToDesignMode(ApplicationManager* pApp):Action(pApp)
{
}

void SwitchToDesignMode::ReadActionParameters()
{
	// No parameters
}

void SwitchToDesignMode::Execute()
{
	Grid* pGrid = pManager->GetGrid();   //Get a Pointer to the Output and Grid
	Output* pOut = pGrid->GetOutput();

	pOut->CreateDesignModeToolBar(); 
	pManager->ExecuteAction(START_GAME);
}

SwitchToDesignMode::~SwitchToDesignMode()
{
}
