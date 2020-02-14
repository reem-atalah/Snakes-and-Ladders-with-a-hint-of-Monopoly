#include "CardSix.h"

CardSix::CardSix(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number (6 here)
}

CardSix::~CardSix(void)
{
}

void CardSix::ReadCardParameters(Grid * pGrid) 
{
	Output *pOut= pGrid->GetOutput();
	pOut->ClearStatusBar();
	//get dice number
	pGrid->GetCurrentPlayer()->GetjustRolledDiceNum();
	//tell the user what will happen at reaching this card

	//pOut->PrintMessage("You will move backward with "+pGrid->GetCurrentPlayer()->GetjustRolledDiceNum());
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer) //Done
{

	// Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid,pPlayer);
	// me:Decrement dice number with justRolledDiceNum.
	int newNum=-(pPlayer->GetjustRolledDiceNum());
	// me:Move backward the same number of steps that you just rolled 
	pPlayer->Move(pGrid,newNum) ;
	//me: print message to the player with what happens
	pGrid->PrintErrorMessage("Player will move" + to_string(abs(newNum)) +"steps backward.");

}

void CardSix::Save(ofstream& OutFile, Type T)
{
	if (T == CardsType)
	{
		Card::Save(OutFile, T);
		OutFile << endl;
	}
	else
		return;
}

Card* CardSix::getCpy(CellPosition pos)
{
	Card* pCard;
	pCard = new CardSix(pos);
	return pCard;
}