#pragma once
#include "Action.h"
#include"Card.h"

class CopyCardAction : public Action
{
	Card *pCard;
public:
	CopyCardAction(ApplicationManager *pApp) ;
	// [Action Parameters]
	CellPosition cardPosition; // cell position of the card

	// Note: These parameters should be read in ReadActionParameters()

		
	virtual void ReadActionParameters(); // Reads CopyCardAction action parameters (cardPosition)
	
	virtual void Execute(); // Creates a new Card Object of the specific Card Number
	                        // and Reads the Parameters of This Card Number (if any)
	                        // then Sets this Card Object to GameObject Pointer of its Cell
	
	virtual ~CopyCardAction(void);
};

