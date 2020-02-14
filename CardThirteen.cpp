#include "CardThirteen.h"

int CardThirteen::fees = -1;
int CardThirteen::cardPrice = -1;
Player* CardThirteen::cardOwner = NULL;
int CardThirteen::NumberOfCards = 0;
bool CardThirteen::Saved_Before = false;

CardThirteen::CardThirteen(const CellPosition& pos) : Card(pos)
{
	NumberOfCards++;
	cardNumber = 13;
}


CardThirteen::~CardThirteen(void)
{
	NumberOfCards--;
	if (NumberOfCards == 0)
	{
		fees = -1;
		cardPrice = -1;
	}
}

bool CardThirteen::isBought()
{
	if (cardOwner != NULL) return true;
	return false;
}

void CardThirteen::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (fees == -1 && cardPrice == -1)
	{
		pOut->PrintMessage("New Card thirteen: Enter card price that the owner will lose from wallet.");	//sets cardPrice to be deducted from owner's wallet
		int money = pIn->GetInteger(pOut);
		cardPrice = (money > 0) ? money : 0;
		pOut->PrintMessage("New Card thirteen: Enter fees that each player must pay");		//sets fees to be deducted from any player on CardThirteen
		money = pIn->GetInteger(pOut);
		fees = (money > 0) ? money : 0;
		pOut->ClearStatusBar();
	}
}

void CardThirteen::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);
	if (!isBought())
	{
		pOut->PrintMessage("Would you like to buy this card? Y/N");		//asks if the player wants to buy the card
		string playerChoice = pIn->GetSrting(pOut);
		if (playerChoice=="N"||playerChoice=="n")
		{
			pOut->PrintMessage("Click to continue");
			pIn->GetCellClicked();
			pOut->ClearStatusBar();
		}
		else if (playerChoice == "Y" || playerChoice == "y")
		{
			if (pPlayer->GetWallet() < cardPrice)
			{
				pOut->PrintMessage("Player doesn't have enough money to buy the card, click to continue");
				pIn->GetCellClicked();
				pOut->ClearStatusBar();
			}
			else
			{
				cardOwner = pPlayer;
				pOut->PrintMessage("Player will own this card for " + to_string(cardPrice) + ", click to continue");
				cardOwner->SetWallet(cardOwner->GetWallet() - cardPrice);		//if player agress cardPrice is deducted from his wallet
				pOut->ClearStatusBar();
			}
		}
	}
	else if (pGrid->GetCurrentPlayer() != cardOwner)		//if the current player is not the card owner fees are deducted from his wallet and added to the owner's
	{
		pOut->ClearStatusBar();
		int paidFees = (pPlayer->GetWallet() - fees >= 0) ? fees : 0;
		if (paidFees != 0)
		{
			pOut->PrintMessage("Player will lose " + to_string(paidFees) + " from wallet, click to continue");
			pPlayer->SetWallet(pPlayer->GetWallet() - fees);
			cardOwner->SetWallet(cardOwner->GetWallet() + paidFees);
			pIn->GetCellClicked();
			pOut->ClearStatusBar();
		}
		else
		{
			pOut->PrintMessage("Player doesn't have enough money, click to continue");
			pIn->GetCellClicked();
			pOut->ClearStatusBar();
		}
	}

}

void CardThirteen::setfees(int f)
{
	fees = f;
}

void CardThirteen::setcardPrice(int p)
{
	cardPrice = p;
}

void CardThirteen::Save(ofstream& OutFile, Type T)
{
	if (T == CardsType)
	{
		Card::Save(OutFile, T);
		if (Saved_Before == false)
		{
			OutFile << " " << cardPrice << " " << fees << endl;
			Saved_Before = true;
		}
		else
		{
			OutFile << endl;
		}
	}
	else
		return;
}

void CardThirteen::Read(ifstream& Infile)
{
	Card::Read(Infile);
	if (NumberOfCards == 1)
	{
		Infile >> cardPrice >> fees;
	}
	else
		return;
}

Card* CardThirteen::getCpy(CellPosition pos)
{
	Card* pCard;
	pCard = new CardThirteen(pos);
	return pCard;
}