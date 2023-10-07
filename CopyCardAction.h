#pragma once
#include "Action.h"
#include "ApplicationManager.h"


class CopyCardAction : public Action

{
    CellPosition cellpos;
	Card* pCard;
	
public:

	CopyCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~CopyCardAction();
};

