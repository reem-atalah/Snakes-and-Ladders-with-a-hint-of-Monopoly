#include "CardFour.h"


CardFour::CardFour(const CellPosition & pos) : Card(pos)
{
	cardNumber = 4;
}

void CardFour::Apply(Grid* pGrid , Player * pPlayer){

	Output * pOut = pGrid->GetOutput();
	Input * pIn = pGrid->GetInput();

	Snake * S = pGrid->GetNextSnake(pPlayer->GetCell()->GetCellPosition());
	if(!S){
		pGrid->PrintErrorMessage("No Snakes ahead. No change will happen");
	}
	else
	{
		pOut->PrintMessage("Player will move to and down the next snake");
		pGrid->UpdatePlayerCell(pPlayer,S->GetEndPosition());
	}

}

void CardFour::Save(ofstream& OutFile, Type T)
{
	if (T == CardsType)
	{
		Card::Save(OutFile, T);
		OutFile << endl;
	}
	else
		return;
}

CardFour::~CardFour()
{
}

Card* CardFour::getCpy(CellPosition pos)
{
	Card* pCard;
	pCard = new CardFour(pos);
	return pCard;
}