#pragma once
#include "Grid.h"
#include"Player.h"

class SpecialAttack
{
	//No Action Parameters in the base class
public:
	SpecialAttack(); //Constructor
	virtual void ReadAttackParameters(Grid* pGrid) = 0;//A function that reads the chosen player to attack. It is implemented differently in each derived class. 
	virtual void Attack(Grid* pGrid) = 0;//The functions that applys the effect of the attack
	virtual ~SpecialAttack(); //Destructor
};

