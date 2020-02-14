#include "CutCardAction.h"

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

CutCardAction::CutCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CutCardAction::~CutCardAction()
{
}

void CutCardAction::ReadActionParameters() 
{	

	// 1- Get a Pointer to the Input / Output Interfaces

	Grid* pGrid=pManager->GetGrid();		
	Input* pIn=pGrid->GetInput();
	Output* pOut=pGrid->GetOutput();

	// Read the PostionToDelete parameter
	pOut->PrintMessage("Delete Card: Click on its Cell ...");
	cardPosition= pIn->GetCellClicked();

	// Clear messages
	pOut->ClearStatusBar();

}

void CutCardAction::Execute() 
{

	// The first line of any Action Execution is to read its parameter first
	ReadActionParameters();

	//  We get a pointer to the Grid from the ApplicationManager

	Grid* pGrid=pManager->GetGrid();		//using class Grid to set the clipboard
	Output* pOut=pGrid->GetOutput();
	pCard=pGrid->HasCard(cardPosition);
	pCard = pCard->getCpy(cardPosition);

	if(pGrid->HasCard(cardPosition)==NULL)                      	//check if there is card in this position  or not
		pGrid->PrintErrorMessage("There is no card here,press to continue..");  //print error message if there is no card
	else
	{
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
		// cut the card object to the GameObject of its Cell using clipboard to save card's information
	//	Card* Temp = pCard;
		pGrid->SetClipboard(pCard);
		pGrid->PrintErrorMessage("The card is copied.");  //print to the user it is done

		// Clear messages
		pOut->ClearStatusBar();
		// Remove the card from its Cell:
		pGrid->RemoveObjectFromCell(cardPosition);
		pGrid->UpdateInterface(); // Update interface with the changes 
		pGrid->PrintErrorMessage("The card is cut.");  //print to the player it is done

		// Clear messages
		pOut->ClearStatusBar();
		// Here, the card is copied to the GameObject of its Cell, so we finished executing the CopyCardAction

	}
}
