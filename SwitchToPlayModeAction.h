#pragma once

#include "Action.h"
#include "Grid.h"

class SwitchToPlayModeAction : public Action
{
	// No parameters for this action
public:
	SwitchToPlayModeAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Empty Function

	virtual void Execute(); // Switches to PlayMode


	virtual ~SwitchToPlayModeAction(); // Virtual Destructor
};

