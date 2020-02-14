#pragma once
#include "Card.h"
#include "Snake.h"

// [ CardFour ] Summary:
// Its Apply() Function: Moves the current player to the next snake

class CardFour :
	public Card
{
public:
	CardFour(const CellPosition & pos) ;
	void Apply(Grid* pGrid , Player * pPlayer);
	virtual void Save(ofstream& OutFile, Type);	// Saves the GameObject parameters to the file
	virtual Card* getCpy(CellPosition pos);
	~CardFour();
};

