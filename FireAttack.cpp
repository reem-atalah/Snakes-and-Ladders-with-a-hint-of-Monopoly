#include "FireAttack.h"

FireAttack::FireAttack()
{

}

void FireAttack::ReadAttackParameters(Grid* pGrid)
{
	Player* pPlayer =pGrid->GetCurrentPlayer();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	while (1)
	{
		pOut->PrintMessage("Please enter the number of the player you want to burn: ");
		chosenPlayerNumber = pIn->GetInteger(pOut);
		if (chosenPlayerNumber == pPlayer->GetPlayerNumber())
			pGrid->PrintErrorMessage("You can't burn yourself! Please enter a different player number");
		else if (chosenPlayerNumber > 3 || chosenPlayerNumber < 0)
			pGrid->PrintErrorMessage("Please enter a valid player number!");
		else
			break;
	}
}

void FireAttack::Attack(Grid* pGrid)
{
	ReadAttackParameters(pGrid);
	Player* pPlayer = pGrid->GetCurrentPlayer();
	int CurrentPlayerNum = pPlayer->GetPlayerNumber();
	do {
		pGrid->AdvanceCurrentPlayer();
		pPlayer = pGrid->GetCurrentPlayer();
	} while ((pPlayer->GetPlayerNumber())!=chosenPlayerNumber);
	pPlayer->SetBurnedTurnsLeft(3);
	do {
		pGrid->AdvanceCurrentPlayer();
		pPlayer = pGrid->GetCurrentPlayer();
	} while ((pPlayer->GetPlayerNumber()) != CurrentPlayerNum);
}

FireAttack::~FireAttack()
{

}