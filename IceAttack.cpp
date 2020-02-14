#include "IceAttack.h"

IceAttack::IceAttack()
{

}

void IceAttack::ReadAttackParameters(Grid* pGrid)
{
	Player* pPlayer = pGrid->GetCurrentPlayer();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	while (1)
	{
		pOut->PrintMessage("Please enter the number of the player you want to freeze: ");
		chosenPlayerNumber = pIn->GetInteger(pOut);
		if (chosenPlayerNumber == pPlayer->GetPlayerNumber())
			pGrid->PrintErrorMessage("You can't freeze yourself! Please enter a different player number");
		else if (chosenPlayerNumber > 3 || chosenPlayerNumber < 0)
			pGrid->PrintErrorMessage("Please enter a valid player number!");
		else
			break;
	}
	//Print to players which player will be attacked
	string s = to_string(chosenPlayerNumber);
	pGrid->PrintErrorMessage("Player number " + s + "will not move the next turn");	
}

void IceAttack::Attack(Grid* pGrid)
{
	ReadAttackParameters(pGrid);
	Player* pPlayer = pGrid->GetCurrentPlayer();
	int CurrentPlayerNum = pPlayer->GetPlayerNumber();
	do {
		pGrid->AdvanceCurrentPlayer();
		pPlayer = pGrid->GetCurrentPlayer();
	} while ((pPlayer->GetPlayerNumber()) != chosenPlayerNumber);
	pPlayer->SetIceEffect(true);
	do {
		pGrid->AdvanceCurrentPlayer();
		pPlayer = pGrid->GetCurrentPlayer();
	} while ((pPlayer->GetPlayerNumber()) != CurrentPlayerNum);
	Output* pOut = pGrid->GetOutput();
	//stop player from moving
	bool b = true;
	pPlayer->setCArd_8(&b);
	pPlayer->excute_card8(b);
	pOut->ClearStatusBar();
}

IceAttack::~IceAttack()
{

}