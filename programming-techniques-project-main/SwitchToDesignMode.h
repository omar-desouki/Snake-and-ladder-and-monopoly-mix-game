#pragma once
#include "Action.h"
#include "Grid.h"

class SwitchToDesignMode:public Action
{
public:
	SwitchToDesignMode(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~SwitchToDesignMode();

};

