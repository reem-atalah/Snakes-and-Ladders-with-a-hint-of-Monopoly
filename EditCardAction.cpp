#include "EditCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
///////////////CARDS////////////// 
#include "Card.h"
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

EditCardAction::EditCardAction(ApplicationManager *pApp) : Action(pApp)
{
}
void EditCardAction::ReadActionParameters()
{	

}
void EditCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	pOut->PrintMessage("Please click on the card you want to edit");
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	cardPosition=(pIn->GetCellClicked());
	Card*pCard=NULL;
	if(cardPosition.IsValidCell() )
	{
		pCard=( pGrid->GetCard(cardPosition) );// will point to the card object type
	}

	CardOne *pOne=dynamic_cast<CardOne*>(pCard);
	CardTwo *pTwo=dynamic_cast<CardTwo*>(pCard);
	CardThree *pThree=dynamic_cast<CardThree*>(pCard);
	CardFour *pFour=dynamic_cast<CardFour*>(pCard);
	CardFive *pFive=dynamic_cast<CardFive*>(pCard);
	CardSix *pSix=dynamic_cast<CardSix*>(pCard);
	//CardSeven *pSeven=dynamic_cast<CardSeven*>(pCard);
	//CardEight *pEight=dynamic_cast<CardEight*>(pCard);
	CardNine *pNine=dynamic_cast<CardNine*>(pCard);
	CardTen *pTen=dynamic_cast<CardTen*>(pCard);
	CardEleven *pEleven=dynamic_cast<CardEleven*>(pCard);
	CardTwelve *pTwelve=dynamic_cast<CardTwelve*>(pCard);
	CardThirteen *pThirteen=dynamic_cast<CardThirteen*>(pCard);
	CardFourteen *pFourteen=dynamic_cast<CardFourteen*>(pCard);

	if(pCard!=NULL)
	{
		cardNumber=pCard->GetCardNumber();
	}
	switch (cardNumber) 
	{
	case 1: pOne->ReadCardParameters(pGrid); break;
	
	case 2: pTwo->ReadCardParameters(pGrid); break;
	
	case 3: 
		pOut->PrintMessage("No parameters for card 3, click to continue"); 
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		break;
	
	case 4: 
		pOut->PrintMessage("No parameters for card 4, click to continue"); 
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		break;
	
	case 5: 
		pOut->PrintMessage("No parameters for card 5, click to continue"); 
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
	
	case 6: 
		pOut->PrintMessage("No parameters for card 6, click to continue"); 
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
	//case 7: pSeven->ReadCardParameters(pGrid); break;
	//case 8: pEight->ReadCardParameters(pGrid); break;
	
	case 9: pNine->ReadCardParameters(pGrid); break;
	
	case 10: 
		pTen->setfees(-1);
		pTen->setcardPrice(-1);
		pTen->ReadCardParameters(pGrid);
		break;
	
	case 11: 
		pEleven->setfees(-1);
		pEleven->setcardPrice(-1);
		pEleven->ReadCardParameters(pGrid); break;
	
	case 12: 
		pTwelve->setfees(-1);
		pTwelve->setcardPrice(-1);
		pTwelve->ReadCardParameters(pGrid); break;
	
	case 13: 
		pThirteen->setfees(-1);
		pThirteen->setcardPrice(-1);
		pThirteen->ReadCardParameters(pGrid); break;
	
	case 14: 
		pFourteen->setfees(-1);
		pFourteen->setcardPrice(-1);
		pFourteen->ReadCardParameters(pGrid); break;
	}
	pGrid->UpdateInterface();
}
EditCardAction::~EditCardAction()
{
}
