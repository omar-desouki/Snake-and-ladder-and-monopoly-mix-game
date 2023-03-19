#include <fstream>
#include "SaveGridAction.h"
#include <iostream>
#include "ApplicationManager.h"
#include "Grid.h"
using namespace std;

SaveGridAction::SaveGridAction(ApplicationManager* pApp)
	:Action(pApp)
{
	
}

void SaveGridAction::Execute()
{
	ReadActionParameters();
	ofstream myfile;
	myfile.open(fileName);
	pManager->GetGrid()->SaveAll(myfile, LADDER);
	pManager->GetGrid()->SaveAll(myfile, SNAKE);
	pManager->GetGrid()->SaveAll(myfile, CARD);
	myfile.close();
	pManager->GetGrid()->GetOutput()->PrintMessage("Grid Saved");
}

void SaveGridAction::ReadActionParameters()
{
	pManager->GetGrid()->GetOutput()->PrintMessage("Please enter file name");
	fileName = pManager->GetGrid()->GetInput()->GetString(pManager->GetGrid()->GetOutput());
}
