#include "Snake.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
	if ((position.HCell() != endCellPos.HCell()) || (position.VCell() > endCellPos.VCell()))
	{
		NotValidPosition = true;
		return;
	}
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// Get a Pointer to the Input / Output Interfaces
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int x, y;

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a snake. Click to continue ..." and wait mouse click
	pOut->PrintMessage("You have reached a snake. Click to continue ...");
	pIn->GetPointClicked(x, y);
	// 2- Apply the snake's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

void Snake::Save(ofstream& OutFile,Type T)
{
	if (T == SnakesType)
	{
		OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
	}
	else
		return;
}

void Snake::Read(ifstream& Infile)
{
	int StartCellNum, EndCellNum;
	Infile >> StartCellNum >> EndCellNum;
	position = position.GetCellPositionFromNum(StartCellNum);
	endCellPos = endCellPos.GetCellPositionFromNum(EndCellNum);
}
Snake::~Snake()
{
}

bool Snake::IsOverlapping(GameObject* newObj)const
{
	Snake* pSnake = dynamic_cast<Snake*>(newObj);
	if (pSnake)
	{
		CellPosition StartCellOld = GetPosition();
		CellPosition EndCellOld = GetEndPosition();
		CellPosition StartCellNew = pSnake->GetPosition();
		CellPosition EndCellNew = pSnake->GetEndPosition();

		if (StartCellOld.HCell() == StartCellNew.HCell())
		{
			bool StartOverLap = ((StartCellNew.VCell() >= StartCellOld.VCell()) || (StartCellNew.VCell() <= EndCellOld.VCell()));
			bool EndOverLap = EndOverLap = ((EndCellNew.VCell() >= StartCellOld.VCell()) || (EndCellNew.VCell() <= EndCellOld.VCell()));
			if (StartOverLap || EndOverLap)
				return true;
		}
	}
	return false;
}

bool Snake::NotValid()const
{
	return NotValidPosition;
}

void Snake::SetNotValid(bool rNot)
{
	NotValidPosition = rNot;
}