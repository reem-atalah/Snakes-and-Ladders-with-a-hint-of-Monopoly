#pragma once

#include "Action.h"

class DeleteGameObjectAction :	public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]
	CellPosition PostionToDelete; // The postion of the cell whose game object will be deleted
	// Note: This parameter should be read in ReadActionParameters()

public:

	DeleteGameObjectAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads DeleteGameObjectAction action parameter (PostitionToDelete)

	virtual void Execute(); // Deletes any gameobject if there's one in the chosen cell 


	virtual ~DeleteGameObjectAction(); // Virtual Destructor
};

