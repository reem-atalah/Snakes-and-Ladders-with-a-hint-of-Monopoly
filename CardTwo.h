#pragma once
#include "Card.h"

// [ CardTwo ] Summary:
// Its Apply() Function: Increments the value of the passing player’s wallet by a value
// Its Parameters: The Wallet Value to increase --> put it as a "data member" and read it in ReadCardParameters()
class CardTwo :
	public Card
{
	int walletIncrease;
public:
	CardTwo(const CellPosition & pos);
	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardTwo which is: walletAmount
	virtual void Apply(Grid * pGrid,Player * pPlayer);
	virtual void Save(ofstream& OutFile, Type);	// Saves the GameObject parameters to the file

	virtual void Read(ifstream& Infile);	// Loads and Reads the GameObject parameters from the file
	virtual Card* getCpy(CellPosition pos);
	~CardTwo(void);
};

