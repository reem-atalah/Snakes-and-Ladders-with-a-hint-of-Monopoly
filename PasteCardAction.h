#pragma once

#include "Action.h"

class PasteCardAction : public Action
{
	Card *pCard;
	// Note: These parameters should be read in ReadActionParameters()

public:
	PasteCardAction(ApplicationManager *pApp); // A Constructor
	// [Action Parameters]
	CellPosition cardPosition; // cell position of the card

	virtual void ReadActionParameters(); // Reads PasteCardAction action parameters (cardPosition)

	virtual void Execute(); // Creates a new Card Object of the specific Card Number
	// and Reads the Parameters of This Card Number (if any)
	// then Sets this Card Object to GameObject Pointer of its Cell

	virtual ~PasteCardAction(); // A Virtual Destructor
};

