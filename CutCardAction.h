#pragma once
#include "Action.h"
#include"Card.h"

class CutCardAction : public Action
{
	Card *pCard;

	// Note: These parameters should be read in ReadActionParameters()

public:
	CutCardAction(ApplicationManager *pApp) ;
	// [Action Parameters]
	CellPosition cardPosition; //cell position of the card


	virtual void ReadActionParameters(); // Reads CutCardAction action parameters (cardPosition)

	virtual void Execute(); // Delete Object of the specific Card Number
	// and Reads the Parameters of This Card Number (if any)
	// then Sets this Card Object to GameObject Pointer of its Cell

	virtual ~CutCardAction(void);
};

