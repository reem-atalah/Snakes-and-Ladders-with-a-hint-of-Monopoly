#pragma once

#include "Card.h"

// [ CardNine ] Summary:
// Its Apply() Function: Instructs the player to go to a specific cell.
// Its Parameters: Cell to move to --> put it as a "data member" and read it in ReadCardParameters()

class CardNine : public Card
{
	// CardNine Parameters:
	CellPosition MoveToThisCell; // the cell the player will be moved to
public:
	CardNine(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardNine which is: MoveToThisCell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardNine on the passed Player
													  // by moving the player to the cell MoveToThisCell;
	virtual void Save(ofstream& OutFile, Type);	// Saves the GameObject parameters to the file

	virtual void Read(ifstream& Infile);	// Loads and Reads the GameObject parameters from the file
	virtual Card* getCpy(CellPosition pos);
	virtual ~CardNine(); // A Virtual Destructor
};
