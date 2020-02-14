#pragma once

#include "GameObject.h"

class Ladder :	public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the ladder's "Start Cell Position"

	CellPosition endCellPos; // here is the ladder's End Cell Position
	bool NotValidPosition; //A boolean variable that indicates if a ladder's input are wrong 

public:

	Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	virtual void Save(ofstream& OutFile,Type);	// Saves the GameObject parameters to the file

	virtual void Read(ifstream& Infile);	// Loads and Reads the GameObject parameters from the file

	virtual bool IsOverlapping(GameObject* newObj)const; //overlapping check of ladders with other ladders

	bool NotValid()const;

	void SetNotValid(bool);

	virtual ~Ladder(); // Virtual destructor
};

