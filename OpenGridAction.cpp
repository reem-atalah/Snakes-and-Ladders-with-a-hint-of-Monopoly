#include "OpenGridAction.h"
#include "Grid.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"
#include <fstream>

OpenGridAction::OpenGridAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void OpenGridAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Open Grid: Enter File Name ...");
	FileName = pIn->GetSrting(pOut);

	// Clear messages
	pOut->ClearStatusBar();
}

void OpenGridAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	int CountOfGameObject; //Variable that stores the count of a certain type of element in this line it stores the no. of ladders.
	Storage_Cell = Storage_Cell.GetCellPositionFromNum(1);
	CountOfGameObject = pGrid->getNumberOfLadders();
	for (int i = 0; i < CountOfGameObject; i++)
	{
		Ladder* pLadder = pGrid->GetNextLadder(Storage_Cell);
		Storage_Cell = pLadder->GetPosition();
		delete pLadder;
		pGrid->RemoveObjectFromCell(Storage_Cell);
	}
	Storage_Cell = Storage_Cell.GetCellPositionFromNum(1);
	CountOfGameObject = pGrid->getNumberOfSnakes();
	for (int i = 0; i < CountOfGameObject; i++)
	{
		Snake* pSnake = pGrid->GetNextSnake(Storage_Cell);
		Storage_Cell = pSnake->GetPosition();
		delete pSnake;
		pGrid->RemoveObjectFromCell(Storage_Cell);
	}
	Storage_Cell = Storage_Cell.GetCellPositionFromNum(1);
	CountOfGameObject = pGrid->getNumberOfCards();
	for (int i = 0; i < CountOfGameObject; i++)
	{
		Card* pCard = pGrid->GetNextCard(Storage_Cell);
		Storage_Cell = pCard->GetPosition();
		delete pCard;
		pGrid->RemoveObjectFromCell(Storage_Cell);
	}
	ifstream OpenFile(FileName + ".txt");

	for (int i = 0; i < 3; i++)
	{
		OpenFile >> CountOfGameObject;
		Storage_Cell.SetHCell(0);
		Storage_Cell.SetVCell(0);
		if (CountOfGameObject != 0)
		{
			switch (i)
			{
			case 0://In case of ladders
				for (int j = 0; j < CountOfGameObject; j++)
				{
					Ladder* pLadder = new Ladder(Storage_Cell, Storage_Cell_2);
					pLadder->Read(OpenFile);
					pGrid->AddObjectToCell(pLadder);
				}
				break;
			case 1://In case of snakes
				for (int j = 0; j < CountOfGameObject; j++)
				{
					Snake* pSnake = new Snake(Storage_Cell, Storage_Cell_2);
					pSnake->Read(OpenFile);
					pGrid->AddObjectToCell(pSnake);
				}
				break;
			case 2://In case of cards
				for (int j = 0; j < CountOfGameObject; j++)
				{
					int cardNumber;
					OpenFile >> cardNumber;
					Card* pCard = NULL; // will point to the card object type
					switch (cardNumber)
					{
					case 1:
						pCard = new CardOne(Storage_Cell);
						break;

						// A- Add the remaining cases
					case 2:
						pCard = new CardTwo(Storage_Cell);
						break;

					case 3:
						pCard = new CardThree(Storage_Cell);
						break;

					case 4:
						pCard = new CardFour(Storage_Cell);
						break;

					case 5:
						pCard = new CardFive(Storage_Cell);
						break;

					case 6:
						pCard = new CardSix(Storage_Cell);
						break;
						
					case 7:
						pCard=new CardSeven(Storage_Cell);
						break;

					case 8:
						pCard=new CardEight(Storage_Cell);
						break;
						
					case 9:
						pCard = new CardNine(Storage_Cell);
						break;

					case 10:
						pCard = new CardTen(Storage_Cell);
						break;

					case 11:
						pCard = new CardEleven(Storage_Cell);
						break;

					case 12:
						pCard = new CardTwelve(Storage_Cell);
						break;

					case 13:
						pCard = new CardThirteen(Storage_Cell);
						break;

					case 14:
						pCard = new CardFourteen(Storage_Cell);
						break;

					}
					//Card* pCard = new Card(Storage_Cell);
					pCard->Read(OpenFile);
					pGrid->AddObjectToCell(pCard);
				}
				break;
			}
		}
	}
	OpenFile.close();
	pGrid->UpdateInterface();
}