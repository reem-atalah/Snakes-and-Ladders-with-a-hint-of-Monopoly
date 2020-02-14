#include "Ladder.h"

Ladder::Ladder(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	NotValidPosition = false;
	///TODO: Do the needed validation
	if ((position.HCell() != endCellPos.HCell()) || (position.VCell() <= endCellPos.VCell()))
	{
		NotValidPosition = true;
		return;
	}
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// Get a Pointer to the Input / Output Interfaces
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int x, y;
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pOut->PrintMessage("You have reached a ladder. Click to continue ...");
	pIn->GetPointClicked(x, y);
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

void Ladder::Save(ofstream& OutFile, Type T)
{
	if (T == LaddersType)
	{
		OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
	}
	else
		return;
}

void Ladder::Read(ifstream& Infile)
{
	int StartCellNum, EndCellNum;
	Infile >> StartCellNum >> EndCellNum;
	position = position.GetCellPositionFromNum(StartCellNum);
	endCellPos = endCellPos.GetCellPositionFromNum(EndCellNum);
}

Ladder::~Ladder()
{
}

bool Ladder::IsOverlapping(GameObject* newObj)const
{
	Ladder* pLadder = dynamic_cast<Ladder*>(newObj);
	if (pLadder)
	{
		CellPosition StartCellOld = GetPosition();
		CellPosition EndCellOld = GetEndPosition();
		CellPosition StartCellNew = pLadder->GetPosition();
		CellPosition EndCellNew = pLadder->GetEndPosition();

		if (StartCellOld.HCell() == StartCellNew.HCell())
		{
			bool StartOverLap = ((StartCellNew.VCell() <= StartCellOld.VCell()) && (StartCellNew.VCell() >= EndCellOld.VCell()));
			bool EndOverLap = EndOverLap = ((EndCellNew.VCell() <= StartCellOld.VCell()) && (EndCellNew.VCell() >= EndCellOld.VCell()));
			if (StartOverLap || EndOverLap)
				return true;
		}
	}
	return false;
}

bool Ladder::NotValid()const
{
	return NotValidPosition;
}

void Ladder::SetNotValid(bool rNot)
{
	NotValidPosition = rNot;
}