#include "SaveGridAction.h"
#include "Grid.h"
#include "GameObject.h"
#include <fstream>

SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void SaveGridAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Save Grid: Enter File Name ...");
	FileName = pIn->GetSrting(pOut);

	// Clear messages
	pOut->ClearStatusBar();
}

void SaveGridAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	// declare an object of ofstream and open the file for writing in it
	ofstream SaveFile(FileName + ".txt");
	SaveFile << pGrid->getNumberOfLadders() << endl; //Check that it doesn't break class responsiblilties
	pGrid->SaveAll(SaveFile, LaddersType);
	SaveFile << pGrid->getNumberOfSnakes() << endl; //Check that it doesn't break class responsiblilties
	pGrid->SaveAll(SaveFile, SnakesType);
	SaveFile << pGrid->getNumberOfCards() << endl; //Check that it doesn't break class responsiblilties
	pGrid->SaveAll(SaveFile, CardsType);
	SaveFile.close();
}