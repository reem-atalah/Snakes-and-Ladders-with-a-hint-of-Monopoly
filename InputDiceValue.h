#pragma once

#include "ApplicationManager.h"
#include "Cell.h"
#include"Action.h"
#include"Input.h"
#include "Output.h"


class InputDiceValue : public Action 
{
	Input *pIn;
	Output *pOut;
	int diceNumber;

public:

	InputDiceValue(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~InputDiceValue();
};


