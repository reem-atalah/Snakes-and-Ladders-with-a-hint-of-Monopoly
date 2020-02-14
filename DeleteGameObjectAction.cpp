#include "DeleteGameObjectAction.h"

#include "Input.h"
#include "Output.h"
#include "GameObject.h" //Not sure if I should add this

DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

DeleteGameObjectAction::~DeleteGameObjectAction()
{
}

void DeleteGameObjectAction::ReadActionParameters()
{
	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the PostionToDelete parameter
	pOut->PrintMessage("Delete Object: Click on its Cell ...");
	PostionToDelete = pIn->GetCellClicked();

	// Clear messages
	pOut->ClearStatusBar();
	
}


// Execute the action
void DeleteGameObjectAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Remove the game object from its Cell:
	pGrid->RemoveObjectFromCell(PostionToDelete);
	pGrid->UpdateInterface();


}