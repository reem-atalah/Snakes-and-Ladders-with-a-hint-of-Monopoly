#include "CardThree.h"


//Move to the Next Ladder
CardThree::CardThree(const CellPosition & pos) : Card(pos)
{
	cardNumber = 3 ;
}


void CardThree::Apply(Grid* pGrid , Player * pPlayer){
	Card::Apply(pGrid,pPlayer);

	Ladder * L ;

	L = pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition());

	if(L == NULL){
		pGrid->PrintErrorMessage("No ladders ahead. No changes will happen");
	}
	else
	{
		pGrid->PrintErrorMessage("Player will move to and up the next ladder");
		pGrid->UpdatePlayerCell(pPlayer,L->GetEndPosition());
	}


}

void CardThree::Save(ofstream& OutFile, Type T)
{
	if (T == CardsType)
	{
		Card::Save(OutFile, T);
		OutFile << endl;
	}
	else
		return;
}

CardThree::~CardThree(void)
{
}

Card* CardThree::getCpy(CellPosition pos)
{
	Card* pCard;
	pCard = new CardThree(pos);
	return pCard;
}