#pragma once
#include "SpecialAttack.h"
class IceAttack : public SpecialAttack
{
	//[Action Parameters]
	//will be read in ReadActionParameters
	int chosenPlayerNumber; //The target player to be struck by lightning. Prevent him from rolling the next turn.
public:
	IceAttack();
	virtual void ReadAttackParameters(Grid* pGrid);//A function that reads the chosen player to attack. It is implemented differently in each derived class. 
	virtual void Attack(Grid* pGrid);//The functions that applys the effect of the attack
	~IceAttack(); //Destructor
};

