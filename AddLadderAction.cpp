#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();
	if (startPos.IsValidCell() == false)                     // Added this validation as in Phase 1 document
	{
		pOut->PrintMessage("Operation Cancelled : Invalid cell");
		return;
	}
	if (startPos.VCell() == 0)
	{
		pOut->PrintMessage("Operation Cancelled : Start cell can't be in the top row");
		return;
	}
	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	///TODO: Make the needed validations on the read parameters
	if (endPos.IsValidCell() == false)                     // Added this validation as in Phase 1 document
	{
		pOut->PrintMessage("Operation Cancelled : Invalid cell");
		return;
	}
	if (startPos.VCell() < endPos.VCell())
	{
		pOut->PrintMessage("end cell cannot be smaller than start cell");
		return;
	}

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Ladder object with the parameters read from the user
	Ladder* pLadder = new Ladder(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the card object to the GameObject of its Cell:
	if (pLadder->NotValid() == true)
	{
		delete pLadder;
		return;
	}

	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
