#include "CardFive.h"

CardFive::CardFive(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (5 here)
}

CardFive::~CardFive(void)
{
}

void CardFive::ReadCardParameters(Grid * pGrid) 
{
	//me:no parameters to read.
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer) //Done
{
		
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid,pPlayer);
	// 2-  Move forward the same number of steps that you just rolled 
	pPlayer->Move(pGrid,pPlayer->GetjustRolledDiceNum()) ;

	//me: print message to the player with what happens
	pGrid->PrintErrorMessage("Player will move " + to_string(pPlayer->GetjustRolledDiceNum()) +" steps forward.");
	
}

void CardFive::Save(ofstream& OutFile, Type T)
{
	if (T == CardsType)
	{
		Card::Save(OutFile, T);
		OutFile << endl;
	}
	else
		return;
}

Card* CardFive::getCpy(CellPosition pos)
{
	Card* pCard;
	pCard = new CardFive(pos);
	return pCard;
}