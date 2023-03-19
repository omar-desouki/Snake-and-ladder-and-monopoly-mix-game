#pragma once
#include <fstream>
#include "Action.h"

class SaveGridAction :
	public Action
{
	string fileName;

public:
	SaveGridAction(ApplicationManager * pApp);
	void Execute();
	void ReadActionParameters();
};

