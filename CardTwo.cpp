#include "CardTwo.h"


CardTwo::CardTwo(const CellPosition & pos) : Card(pos)
{
	cardNumber=2;
}


void CardTwo::ReadCardParameters(Grid * pGrid) 
{
	
	
	Output * pOut = pGrid->GetOutput();
	Input * pIn = pGrid->GetInput();
	pGrid->PrintErrorMessage("New Card two: Enter amount of money that the player will add to wallet.");
	int money = pIn->GetInteger(pOut);
	walletIncrease = ( money > 0)? money : 0 ;

	
	pOut->ClearStatusBar();
}


void CardTwo::Apply(Grid * pGrid,Player * pPlayer){

	Card::Apply(pGrid,pPlayer);
	// 2- Icrement the wallet of pPlayer by the walletAmount data member of CardOne
	pGrid->PrintErrorMessage("Player will get " + to_string(walletIncrease)+ "added into wallet");
	pPlayer->SetWallet(pPlayer->GetWallet() + walletIncrease);

}

void CardTwo::Save(ofstream& OutFile, Type T)
{
	if (T == CardsType)
	{
		Card::Save(OutFile, T);
		OutFile << " " << walletIncrease << endl;

	}
	else
		return;
}

void CardTwo::Read(ifstream& Infile)
{
	Card::Read(Infile);
	Infile >> walletIncrease;

}
CardTwo::~CardTwo(void)
{
}

Card* CardTwo::getCpy(CellPosition pos)
{
	Card* pCard;
	pCard = new CardTwo(pos);
	return pCard;
}