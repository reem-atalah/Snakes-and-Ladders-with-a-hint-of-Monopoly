#include "PasteCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"

PasteCardAction::PasteCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

PasteCardAction::~PasteCardAction()
{
}

void PasteCardAction::ReadActionParameters() 
{	
	// 1- Get a Pointer to the Input / Output Interfaces

	Grid* pGrid=pManager->GetGrid();		//using class Grid to declare input and output pointers
	Input* pIn=pGrid->GetInput();
	Output* pOut=pGrid->GetOutput();
	// Read the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage("click cell to paste the card in..");		//asking the user to click on the cell to place the card and setting member cardPosition to it
	cardPosition=pIn->GetCellClicked();
	pCard=pGrid->HasCard(cardPosition);
}
void PasteCardAction::Execute() 
{
	ReadActionParameters();

	pCard = NULL; // will point to the card object type
	// A- We get a pointer to the Grid from the ApplicationManager

	Grid* pGrid = pManager->GetGrid();		//using class Grid to declare pCard  and pOut pointers
	Output* pOut=pGrid->GetOutput();

	if(pGrid->HasCard(cardPosition)==NULL)                      	//check if there is card in this position  or not
	{		
		pCard=pGrid->GetClipboard();            //get the clipboard copied which was copied 

		pOut->PrintMessage("The card is pasted.");  //tell the user that it is done

		pCard->setPosition(cardPosition);       //put the copied card in its new position

		pGrid->AddObjectToCell(pCard);
	}
	else 		
		pGrid->PrintErrorMessage("There is arleady a card here,press to continue.");  //print error message if there is no card

	// Clear status bar

	pOut->ClearStatusBar();
	// Here, the card is pasted to the GameObject of its Cell, so we finished executing the PasteCardAction

}
