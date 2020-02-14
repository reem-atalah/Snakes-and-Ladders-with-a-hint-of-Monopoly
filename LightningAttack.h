#pragma once
#include "SpecialAttack.h"
class LightningAttack :	public SpecialAttack
{
	//[Action Parameters]
	//No parameters needed
public:
	LightningAttack();
	virtual void ReadAttackParameters(Grid* pGrid);//Not needed in this particular attack
	virtual void Attack(Grid* pGrid);//The functions that applys the effect of the attack
	~LightningAttack(); //Destructor
};

