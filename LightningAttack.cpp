#include "LightningAttack.h"

LightningAttack::LightningAttack()
{

}

void LightningAttack::ReadAttackParameters(Grid* pGrid)
{
	//No parameters to read
}

void LightningAttack::Attack(Grid* pGrid)
{
	Player* pPlayer = pGrid->GetCurrentPlayer();
	int CurrentPlayerNum = pPlayer->GetPlayerNumber();
	do {
		pGrid->AdvanceCurrentPlayer();
		pPlayer = pGrid->GetCurrentPlayer();
		if((pPlayer->GetPlayerNumber()) != CurrentPlayerNum)
		pPlayer->SetWallet(pPlayer->GetWallet() - 20);
	} while ((pPlayer->GetPlayerNumber()) != CurrentPlayerNum);
}

LightningAttack::~LightningAttack()
{

}