#pragma once
#include "SpecialAttack.h"
class PoisonAttack : public SpecialAttack
{
	//[Action Parameters]
	//will be read in ReadActionParameters
	int chosenPlayerNumber; //The target player to be poisoned. Deduct 1 number from his dice roll for the next five turns.
public:
	PoisonAttack();
	virtual void ReadAttackParameters(Grid* pGrid);//A function that reads the chosen player to attack. It is implemented differently in each derived class. 
	virtual void Attack(Grid* pGrid);//The functions that applys the effect of the attack
	~PoisonAttack(); //Destructor
};

