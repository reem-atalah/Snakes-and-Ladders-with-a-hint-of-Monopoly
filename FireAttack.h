#pragma once
#include "SpecialAttack.h"
class FireAttack : public SpecialAttack
{
	//[Action Parameters]
	//will be read in ReadActionParameters
	int chosenPlayerNumber; //The target player to be burned. Deduct 20 coins from his wallet for the next three turns.
public:
	FireAttack();
	virtual void ReadAttackParameters(Grid* pGrid);//A function that reads the chosen player to attack. It is implemented differently in each derived class. 
	virtual void Attack(Grid* pGrid);//The functions that applys the effect of the attack
	~FireAttack(); //Destructor
};

