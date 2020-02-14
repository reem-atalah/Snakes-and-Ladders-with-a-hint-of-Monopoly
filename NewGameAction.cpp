#include "NewGameAction.h"

#include "Input.h"
#include "Output.h"
#include "GameObject.h" //Not sure if I should add this

NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

NewGameAction::~NewGameAction()
{
}

void NewGameAction::ReadActionParameters()
{

	// Get a Pointer to print a message
	Grid* pGrid = pManager->GetGrid();
	pGrid->PrintErrorMessage("Reset the game ...");

}
// Execute the action
void NewGameAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	Output* pOut = pGrid->GetOutput();
	Player *player =pGrid->GetCurrentPlayer();  //Get the current player from grid
	player->resetGame(pGrid);                       // resets all parameters of players
	pGrid->UpdateInterface();                  // Update interface with the new values
}