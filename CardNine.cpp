#include "CardNine.h"

CardNine::CardNine(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 9; // set the inherited cardNumber data member with the card number (9 here)
}

CardNine::~CardNine(void)
{
}

void CardNine::ReadCardParameters(Grid* pGrid)
{


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read an the cell to move the player to from the user using the Input class and set it to MoveToThisCell
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	pOut->PrintMessage("New CardNine : Please choose the cell to move the player to ");
	MoveToThisCell = pIn->GetCellClicked();

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	Card::Apply(pGrid, pPlayer);

	pOut->PrintMessage("You have been transported to another cell ...");
	pOut->ClearStatusBar();
	pGrid->UpdatePlayerCell(pPlayer,MoveToThisCell);
}

void CardNine::Save(ofstream& OutFile, Type T)
{
	if (T == CardsType)
	{
		Card::Save(OutFile, T);
		OutFile << " " << MoveToThisCell.GetCellNum() << endl;
	}
	else
		return;
}

void CardNine::Read(ifstream& Infile)
{
	Card::Read(Infile);
	int CellNum;
	Infile >> CellNum;
	MoveToThisCell = MoveToThisCell.GetCellPositionFromNum(CellNum);
}

Card* CardNine::getCpy(CellPosition pos)
{
	Card* pCard;
	pCard = new CardNine(pos);
	return pCard;
}