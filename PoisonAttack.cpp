#include "PoisonAttack.h"

PoisonAttack::PoisonAttack()
{

}

void PoisonAttack::ReadAttackParameters(Grid* pGrid)
{
	Player* pPlayer = pGrid->GetCurrentPlayer();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	while (1)
	{
		pOut->PrintMessage("Please enter the number of the player you want to poison: ");
		chosenPlayerNumber = pIn->GetInteger(pOut);
		if (chosenPlayerNumber == pPlayer->GetPlayerNumber())
			pGrid->PrintErrorMessage("You can't poison yourself! Please enter a different player number");
		else if (chosenPlayerNumber > 3 || chosenPlayerNumber < 0)
			pGrid->PrintErrorMessage("Please enter a valid player number!");
		else
			break;
	}
}

void PoisonAttack::Attack(Grid* pGrid)
{
	ReadAttackParameters(pGrid);
	Player* pPlayer = pGrid->GetCurrentPlayer();
	int CurrentPlayerNum = pPlayer->GetPlayerNumber();
	do {
		pGrid->AdvanceCurrentPlayer();
		pPlayer = pGrid->GetCurrentPlayer();
	} while ((pPlayer->GetPlayerNumber()) != chosenPlayerNumber);
	pPlayer->SetPoisonedTurnsLeft(5);
	do {
		pGrid->AdvanceCurrentPlayer();
		pPlayer = pGrid->GetCurrentPlayer();
	} while ((pPlayer->GetPlayerNumber()) != CurrentPlayerNum);
}

PoisonAttack::~PoisonAttack()
{

}