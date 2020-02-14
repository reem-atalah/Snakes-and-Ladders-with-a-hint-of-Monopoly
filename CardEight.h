#pragma once

#include "Card.h"

// [ CardEight ] Summary:
// Its Apply() Function: Prevents the player from rolling the next turn.

class CardEight :	public Card 
{
	// CardEight has no parameters

public:
	CardEight(const CellPosition & pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardEight which is: None

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardEight on the passed Player
	                                                  // Prevents the player from rolling the next turn.
	virtual void Save(ofstream& OutFile, Type);	// Saves the GameObject parameters to the file

	virtual Card* getCpy(CellPosition pos);

	virtual ~CardEight(); // A Virtual Destructor
};

