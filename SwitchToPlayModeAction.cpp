#include "SwitchToPlayModeAction.h"
#include "Input.h"
#include "Output.h"


SwitchToPlayModeAction::SwitchToPlayModeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

SwitchToPlayModeAction::~SwitchToPlayModeAction()
{

}
void SwitchToPlayModeAction::ReadActionParameters()
{
	// no parameters to read from user
}
void SwitchToPlayModeAction::Execute()
{
	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	Output* pOut = pGrid->GetOutput();
	pOut->CreatePlayModeToolBar();

}


