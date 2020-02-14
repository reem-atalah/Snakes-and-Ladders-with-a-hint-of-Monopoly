#include "Card.h"


Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
}

void Card::SetCardNumber(int cnum)
{
	cardNumber = (cnum>=1&&cnum<=14)? cnum:1; // needs validation
}

int Card::GetCardNumber()
{
	return cardNumber;
}


void Card::setPosition(CellPosition pos) //set the position of the card
{
	position.SetHCell(pos.HCell());
	position.SetVCell(pos.VCell());
}

void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position,cardNumber);

}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

void Card::Save(ofstream& OutFile, Type T)
{
	if (T == CardsType)
	{
		OutFile << cardNumber << " " << position.GetCellNum();// << endl;
	}
	else
		return;
}

void Card::Read(ifstream& Infile)
{
	int StartCellNum;
	Infile >> StartCellNum;
	position = position.GetCellPositionFromNum(StartCellNum);
}

Card::~Card()
{

}

bool Card::IsOverlapping(GameObject* newObj)const
{
	return false;
}