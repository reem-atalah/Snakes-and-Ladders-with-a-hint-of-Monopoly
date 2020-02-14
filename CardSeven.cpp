#include "CardSeven.h"
#include <time.h> // used to in srand to generate random numbers with different seed
#include <string>

CardSeven::CardSeven(const CellPosition & pos) : Card(pos) 
{
	cardNumber = 7;
}

void CardSeven::Apply(Grid* pGrid , Player * pPlayer)
{
//Call Apply() to till the player which card he reached 
	Card::Apply(pGrid,pPlayer);
	//Get the current player
	pPlayer=pGrid->GetCurrentPlayer();
	
	// - Generate a random number from 1 to 6 --> This step is done for you
	srand((int)time(NULL)); // time is for different seed each run
	Output *pOut=pGrid->GetOutput();
	pGrid->PrintErrorMessage("You reached card 7,You'll have another rolled dice");
	int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed
	
	//print to the player the number of moves he got from the another roll dice
	string st=to_string(diceNumber);
	pOut->PrintMessage("you'll move " +st+ " steps forward.");

	//move the player using the new dice number
	pPlayer->Move(pGrid,diceNumber);
}
void CardSeven ::ReadCardParameters(Grid * pGrid)
{
	//no parameters to read
}

void CardSeven::Save(ofstream& OutFile, Type T)
{
	if (T == CardsType)
	{
		Card::Save(OutFile, T);
		OutFile << endl;
	}
	else
		return;
}

CardSeven::~CardSeven()
{
}

Card* CardSeven::getCpy(CellPosition pos)
{
	Card* pCard;
	pCard = new CardSeven(pos);
	return pCard;
}