#include "CardEight.h"
#include <time.h> // used to in srand to generate random numbers with different seed

CardEight::CardEight(const CellPosition & pos) : Card(pos) 
{
	cardNumber = 8; 
}

void CardEight::Apply(Grid* pGrid , Player * pPlayer)
{
	// Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	//Get the current player from pGrid
	pPlayer = pGrid->GetCurrentPlayer();
	Output* pOut = pGrid->GetOutput();

	//print to the player that he will not move
	pOut->PrintMessage("you'll not move the next turn");
	pGrid->PrintErrorMessage("you'll not move the next turn");

	//stop player from moving 
	bool b;
	b = true;
	//Change value of card_8 in player to announce that the player will not move 
	pPlayer->setCArd_8(&b);
	pPlayer->excute_card8(b);
	//clear statusbar
	pOut->ClearStatusBar();

}
void CardEight ::ReadCardParameters(Grid * pGrid)
{
	//no parameters to read
}

void CardEight::Save(ofstream& OutFile, Type T)
{
	if (T == CardsType)
	{
		Card::Save(OutFile, T);
		OutFile << endl;
	}
	else
		return;
}

CardEight::~CardEight()
{
}

Card* CardEight::getCpy(CellPosition pos)
{
	Card* pCard;
	pCard = new CardEight(pos);
	return pCard;
}