#include "InputDiceValue.h"
#include "Grid.h"
#include "Player.h"

InputDiceValue::InputDiceValue(ApplicationManager *pApp): Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}
void InputDiceValue::ReadActionParameters() //Not Done Yet
{
	//me : read dice number from user
	Grid* pGrid=pManager->GetGrid();	
	pIn=pGrid->GetInput();
	pOut=pGrid->GetOutput();
	pOut->ClearStatusBar();
		      //to read dice number from user
	//using class Grid to declare input and output pointers
	
	//pGrid->PrintErrorMessage("Please enter dice number,from grid");
	pOut->PrintMessage("Please enter dice number,from output");
	diceNumber=pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
}

void InputDiceValue::Execute() 
{
	ReadActionParameters();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action

	Grid *pGrid=pManager->GetGrid();
	if (pGrid->GetEndGame()==false)
	{
		// -- If not ended, do the following --:

		// 2- Get the "current" player from pGrid
		pGrid->GetCurrentPlayer();
		// 3- Move the currentPlayer using function Move of class player
		Player *player=pGrid->GetCurrentPlayer();
		player->Move(pGrid,diceNumber);

		// 4- Advance the current player number of pGrid
		pGrid->AdvanceCurrentPlayer();

		//me : print player's info
		string playersInfo;
		player->AppendPlayerInfo(playersInfo);

		// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
	}
}

InputDiceValue::~InputDiceValue(void)
{
}

