#include "Player.h"

#include "GameObject.h"
#include "IceAttack.h"
#include "FireAttack.h"
#include "PoisonAttack.h"
#include "LightningAttack.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	turnCount = 0;

	// Make all the needed initialization or validations
	justRolledDiceNum=0;
	card_8 = 0;  // Initiallize it with zero until player reaches card 8
	//Bonus:
	Num_Of_Special_Attacks_Used = 0;
	SpecialAttackUsed[0] = false;
	SpecialAttackUsed[1] = false;
	SpecialAttackUsed[2] = false;
	SpecialAttackUsed[3] = false;
	BurnedTurnsLeft = 0;
	PoisonedTurnsLeft = 0;
	AffectedByIce = false;
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}
void Player::setCArd_8(bool b)
{
	card_8 = b;
}
bool Player::getCArd_8()
{
	return card_8;
}
void Player::excute_card8(bool& card_8)
{
	//Make dice number =0 so player won't move
	//turnCount--;
	justRolledDiceNum = 0;
}
int Player::GetjustRolledDiceNum() const
{
	return justRolledDiceNum;
}


void Player::SetWallet(int wallet)
{
	// Make any needed validations
	//me: number of coins can't be negative
	if(wallet>=0)
	{
		this->wallet = wallet;
	}
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(),playerNum,playerColor);

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;

	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(),playerNum,cellColor);
}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int x, y;
	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	turnCount++;
	//Checking For Special Attacks Effects:
	if (BurnedTurnsLeft != 0)
	{
		BurnedTurnsLeft--;
		pOut->PrintMessage("Burned! : " + to_string(BurnedTurnsLeft) + "turns left ");
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
		SetWallet(GetWallet() - 20);
	}
	if (PoisonedTurnsLeft != 0)
	{
		PoisonedTurnsLeft--;
		pOut->PrintMessage("Poisoned! :" + to_string(PoisonedTurnsLeft) + "turns left ");
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
		diceNumber -= 1;
	}
	if (turnCount == 3 && diceNumber != 0)
	{
		if (Num_Of_Special_Attacks_Used < 2)
		{
			////asks if the player wants to use a special attack instead of recharging his wallet
			pOut->PrintMessage("Do you wish to launch a special attack instead of recharging? Y/N");

			string playerChoice = pIn->GetSrting(pOut);
			if (playerChoice == "Y" || playerChoice == "y")
			{
				SpecialAttack* pSpecialAttack = NULL;
				ChooseSpecialAttack(pGrid, pSpecialAttack);
				pSpecialAttack->Attack(pGrid);
				playerChoice = to_string(2 - Num_Of_Special_Attacks_Used);
				pOut->PrintMessage(playerChoice + " special attacks left, click to continue...");
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
				turnCount = 0;
				return;
			}
			else if (playerChoice == "N" || playerChoice == "n")
			{
				pOut->PrintMessage("Recharging wallet ...");
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
				//If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
				wallet += 10 * diceNumber;
				turnCount = 0;
				return;
			}
		}
		else
		{
			// If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
			wallet += 10 * diceNumber;
			turnCount = 0;
			return;
		}

	}
	else {
		//me:player will not move if his wallet's coins are less thann 1 coin

		if (wallet > 1 && diceNumber != 0 && AffectedByIce != true)
		{
			// 3- Set the justRolledDiceNum with the passed diceNumber
			justRolledDiceNum = diceNumber;
			// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
			//    Using the appropriate function of CellPosition class to update "pos"
			CellPosition pos;
			pos = pCell->GetCellPosition();

			if ((pos.GetCellNum() + diceNumber) > 99)   //Checks the position with dice number to avoid reaching cell >99
				return;
			pos.AddCellNum(diceNumber);

			// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
			//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
			pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(), pos);

			// 6- Apply() the game object of the reached cell (if any)

			while (pCell->GetGameObject()!=NULL)
				pCell->GetGameObject()->Apply(pGrid, pGrid->GetCurrentPlayer());

			stepCount = pCell->GetCellPosition().GetCellNum();
			// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
			if (stepCount == 99)
			{
				pGrid->SetEndGame(true);
				string s = to_string(playerNum);
				pGrid->PrintErrorMessage("The winner player is " + s + " CONGRATULATIONS!!"); // Announce the winner! =)
			}
			else pGrid->SetEndGame(false);
		}
		else if (AffectedByIce == true)
		{
			pOut->PrintMessage("Ice effect activated: You can't roll dice this turn!");
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
			AffectedByIce == false;
			return;
		}
	}
}


//me : Print player's information on tool bar
void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}

void Player::resetGame(Grid* pGrid)
{
	for (int i = 0; i < 4; i++)
	{
		Player* pPlayer;
		pPlayer = pGrid->GetCurrentPlayer();
		//Resets all the player's parameters
		pPlayer->turnCount = 0;
		pPlayer->stepCount = 0;
		pPlayer->SetWallet(100);
		pPlayer->justRolledDiceNum = 0;
		pPlayer->card_8 = 0;
		pPlayer->Num_Of_Special_Attacks_Used = 0;
		pPlayer->SpecialAttackUsed[0] = false;
		pPlayer->SpecialAttackUsed[1] = false;
		pPlayer->SpecialAttackUsed[2] = false;
		pPlayer->SpecialAttackUsed[3] = false;
		pPlayer->BurnedTurnsLeft = 0;
		pPlayer->PoisonedTurnsLeft = 0;
		pPlayer->AffectedByIce = false;
		//Return players to the beginning place
		CellPosition pos;
		pos.SetHCell(0);
		pos.SetVCell(8);
		pGrid->UpdatePlayerCell(pPlayer, pos);
		pGrid->AdvanceCurrentPlayer();
	}
	pGrid->setCurrentPlayerNumber(0);
	pGrid->SetEndGame(false);
}

int Player::GetPlayerNumber() const
{
	return playerNum;
}

void Player::SetBurnedTurnsLeft(int rTurns)
{
	BurnedTurnsLeft = rTurns;
}
void Player::SetPoisonedTurnsLeft(int rTurns)
{
	PoisonedTurnsLeft = rTurns;
}

Special_Attack Player::ChooseSpecialAttack(Grid* pGrid, SpecialAttack*& pSpecialAttack)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int x, y;
	string playerChoice;
	int SpecialAttackNum;
	Num_Of_Special_Attacks_Used++;
	pOut->PrintMessage("Which special attack would you like to use Ice, Fire, Poison or Lightning? I/F/P/L");


	while (1)
	{
		playerChoice = pIn->GetSrting(pOut);
		if (playerChoice == "I" || playerChoice == "i")
		{
			if (SpecialAttackUsed[ICE] == true)
			{
				pOut->PrintMessage("Ice Special Attack used once before , please choose another attack...");
			}
			else
			{
				pOut->PrintMessage("Ice Special Attack activated, click to continue");
				pIn->GetPointClicked(x, y);
				//Create IceAttack
				pSpecialAttack = new IceAttack;
				SpecialAttackUsed[ICE] = true;
				pOut->ClearStatusBar();
				return ICE;
			}
		}
		else if (playerChoice == "F" || playerChoice == "f")
		{
			if (SpecialAttackUsed[FIRE] == true)
			{
				pOut->PrintMessage("Fire Special Attack used once before , please choose another attack...");
			}
			else
			{
				pOut->PrintMessage("Fire Special Attack activated, click to continue");
				pIn->GetPointClicked(x, y);
				//Create FireAttack
				pSpecialAttack = new FireAttack;
				SpecialAttackUsed[FIRE] = true;
				pOut->ClearStatusBar();

				return FIRE;
			}
		}
		else if (playerChoice == "P" || playerChoice == "p")
		{
			if (SpecialAttackUsed[POISON] == true)
			{
				pOut->PrintMessage("Poison Special Attack used once before , please choose another attack...");
			}
			else
			{
				pOut->PrintMessage("Poison Special Attack activated, click to continue");
				pIn->GetPointClicked(x, y);
				//Create PoisonAttack
				pSpecialAttack = new PoisonAttack;
				SpecialAttackUsed[POISON] = true;
				pOut->ClearStatusBar();
				return POISON;
			}
		}
		else if (playerChoice == "L" || playerChoice == "l")
		{
			if (SpecialAttackUsed[LIGHTNING] == true)
			{
				pOut->PrintMessage("Lightning Special Attack used once before , please choose another attack...");
			}
			else
			{
				pOut->PrintMessage("Lightning Special Attack activated, click to continue");
				pIn->GetPointClicked(x, y);
				//Create LightningAttack
				pSpecialAttack = new LightningAttack;
				SpecialAttackUsed[LIGHTNING] = true;
				pOut->ClearStatusBar();
				return LIGHTNING;
			}
		}
		else
		{
			pOut->PrintMessage("Please choose an attack... I/F/P/L");
		}
	}
}

void Player::SetIceEffect(bool rIce)
{
	AffectedByIce = rIce;
}