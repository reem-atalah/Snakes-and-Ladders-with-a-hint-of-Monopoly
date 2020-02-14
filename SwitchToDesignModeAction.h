#pragma once

#include "Action.h"
#include "Grid.h"

class SwitchToDesignModeAction : public Action
{
	// No parameters for this action
public:
	SwitchToDesignModeAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Empty Function

	virtual void Execute(); // Switches to PlayMode


	virtual ~SwitchToDesignModeAction(); // Virtual Destructor
};

