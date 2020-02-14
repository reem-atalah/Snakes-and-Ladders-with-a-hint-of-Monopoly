#pragma once

#include "Card.h"

// [ CardSeven ] Summary:
// Its Apply() Function: Gives the player another dice roll
//(if you reach a ladder or a snake at the end of moving forward, take it). 

class CardSeven :	public Card 
{
	// CardSeven has no parameters

public:
	CardSeven(const CellPosition & pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardSeven which is: None

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSeven on the passed Player
	                                                  // Gives the player another dice roll
	virtual void Save(ofstream& OutFile, Type);	// Saves the GameObject parameters to the file
	virtual Card* getCpy(CellPosition pos);

	virtual ~CardSeven(); // A Virtual Destructor
};

