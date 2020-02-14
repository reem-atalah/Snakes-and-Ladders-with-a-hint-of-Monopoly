#pragma once

#include "Card.h"

// [ CardSix ] Summary:
// Its Apply() Function: Moves the player backward the same number of steps that he just rolled. 

class CardSix :	public Card
{
	// CardSix has no Parameters

public:
	CardSix(const CellPosition & pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardSix which is: None

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSix on the passed Player
	                                                  // Moves the player backward the same number of steps that he just rolled. 
	virtual void Save(ofstream& OutFile, Type);	// Saves the GameObject parameters to the file
	virtual Card* getCpy(CellPosition pos);
	virtual ~CardSix(); // A Virtual Destructor
};

