#include "CopyCardAction.h"

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

CopyCardAction::CopyCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CopyCardAction::~CopyCardAction()
{
}

void CopyCardAction::ReadActionParameters() 
{	

	// 1- Get a Pointer to the Input / Output Interfaces

	Grid* pGrid=pManager->GetGrid();		//using class Grid to declare input and output pointers
	Input* pIn=pGrid->GetInput();
	Output* pOut=pGrid->GetOutput();

	// 2- Read the "cardPosition" parameter (its cell position) and set its data member

	pOut->PrintMessage("Click card to be copied..");		//asking the user to click on the cell to copy the card and setting member cardPosition to it
	cardPosition=pIn->GetCellClicked();                     //Save the position of the card
	pCard=pGrid->HasCard(cardPosition);                    // Initiallize pCard pointer with the card in the saved position
	pCard = pCard->getCpy(cardPosition);
	// 4- Clear status bar

	pOut->ClearStatusBar();
}

void CopyCardAction::Execute() 
{

	// The first line of any Action Execution is to read its parameter first
	ReadActionParameters();

	//  We get a pointer to the Grid from the ApplicationManager

	Grid* pGrid=pManager->GetGrid();		//using class Grid to declare input and output pointers and to set the clipboard

	switch (pCard->GetCardNumber())
	{
	case 1:
		pCard = new CardOne(cardPosition);
		break;

		// A- Add the remaining cases
	case 2:
		pCard = new CardTwo(cardPosition);
		break;

	case 3:
		pCard = new CardThree(cardPosition);
		break;

	case 4:
		pCard = new CardFour(cardPosition);
		break;

	case 5:
		pCard = new CardFive(cardPosition);
		break;

	case 6:
		pCard = new CardSix(cardPosition);
		break;

	case 7:
		pCard = new CardSeven(cardPosition);
		break;

	case 8:
		pCard = new CardEight(cardPosition);
		break;

	case 9:
		pCard = new CardNine(cardPosition);
		break;

	case 10:
		pCard = new CardTen(cardPosition);
		break;

	case 11:
		pCard = new CardEleven(cardPosition);
		break;

	case 12:
		pCard = new CardTwelve(cardPosition);
		break;

	case 13:
		pCard = new CardThirteen(cardPosition);
		break;

	case 14:
		pCard = new CardFourteen(cardPosition);
		break;
	default:
		pGrid->PrintErrorMessage("You have entered an unknown card number, Click to continue ...");

	}

	Output* pOut=pGrid->GetOutput();

	if(pGrid->HasCard(cardPosition)==NULL)                      	//check if there is card in this position  or not
		pGrid->PrintErrorMessage("There is no card here,press to continue..");  //print error message if there is no card
	else
	{
		pOut->PrintMessage("The card is copied.");  //tell the user that it is done
		// copy the card object to the GameObject of its Cell using clipboard to save card's information

		pGrid->SetClipboard(pCard);

		// Here, the card is copied to the GameObject of its Cell, so we finished executing the CopyCardAction

	}
}
