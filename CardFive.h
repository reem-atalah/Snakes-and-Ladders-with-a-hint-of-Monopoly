#pragma once

#include "Card.h"

// [ CardFive ] Summary:
// Its Apply() Function: Move forward the same number of steps that you just rolled 
//(if you reach a ladder or a snake at the end of moving forward, take it). 

class CardFive :	public Card
{
	// CardFive has no parameters

public:
	CardFive(const CellPosition & pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardFive which is: None

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFive on the passed Player
	                                                  // by moving forward the same number of steps that it just rolled 
	virtual void Save(ofstream& OutFile, Type);	// Saves the GameObject parameters to the file
	virtual Card* getCpy(CellPosition pos);
	virtual ~CardFive(); // A Virtual Destructor
};

