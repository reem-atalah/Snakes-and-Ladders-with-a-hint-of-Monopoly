#pragma once
#include "Card.h"
#include "Ladder.h"
class CardThree :
	public Card
{
public:
	CardThree(const CellPosition & pos) ;
	virtual void Apply(Grid* ,Player*);
	virtual void Save(ofstream& OutFile, Type);	// Saves the GameObject parameters to the file
	virtual Card* getCpy(CellPosition pos);
	~CardThree();
};

