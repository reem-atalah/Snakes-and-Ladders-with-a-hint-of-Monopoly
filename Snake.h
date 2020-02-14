#pragma once

#include "GameObject.h"

class Snake : public GameObject    // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the snake's "Start Cell Position"

	CellPosition endCellPos; // here is the snake's End Cell Position
	bool NotValidPosition; //A boolean variable that indicates if a snake's input are wrong 

public:

	Snake(const CellPosition& startCellPos, const CellPosition& endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a snake from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the snake by moving player to snake's end cell

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	virtual void Save(ofstream& OutFile,Type);	// Saves the GameObject parameters to the file

	virtual void Read(ifstream& Infile);	// Loads and Reads the GameObject parameters from the file

	virtual bool IsOverlapping(GameObject* newObj)const; //overlapping check of ladders with other ladders

	bool NotValid()const;

	void SetNotValid(bool);

	virtual ~Snake(); // Virtual destructor
};

