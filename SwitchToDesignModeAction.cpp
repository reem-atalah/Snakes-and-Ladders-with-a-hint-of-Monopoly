#include "SwitchToDesignModeAction.h"
#include "Input.h"
#include "Output.h"
#include"Player.h"
SwitchToDesignModeAction::SwitchToDesignModeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

SwitchToDesignModeAction::~SwitchToDesignModeAction()
{

}
void SwitchToDesignModeAction::ReadActionParameters()
{
	// no parameters to read from user
}
void SwitchToDesignModeAction::Execute()
{
	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	Output* pOut = pGrid->GetOutput();
	Player *pPlayer =pGrid->GetCurrentPlayer();
	pOut->CreateDesignModeToolBar();
	//Resets the players' parameters
	pPlayer->resetGame(pGrid);
	//Update interface with the changes
	pGrid->UpdateInterface();
}
