#pragma once

#include "Action.h"
#include"Player.h"

class NewGameAction :	public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]
	// Has noparameteers

public:

	NewGameAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads NewGameAction action parameter (PostitionToDelete)

	virtual void Execute(); // Resets the game 


	virtual ~NewGameAction(); // Virtual Destructor
};

