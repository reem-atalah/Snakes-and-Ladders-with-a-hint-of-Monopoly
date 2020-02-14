#pragma once

#include "Action.h"



class OpenGridAction : public Action
{
	string FileName;
	CellPosition Storage_Cell;   //Cell used to find and store the position of the next gameobject
	CellPosition Storage_Cell_2;   //Cell used to find and store the position of the next gameobject
public:
	OpenGridAction(ApplicationManager* pApp);

	virtual void ReadActionParameters(); // Reads parameters required for action to execute 
										// (code depends on action type so virtual)

	virtual void Execute();  // Executes action (code depends on action type so virtual)
};

