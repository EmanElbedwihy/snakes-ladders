#include "CopyCardAction.h"


CopyCardAction ::CopyCardAction( ApplicationManager* pApp ) : Action (pApp)
{
	
}

CopyCardAction ::~CopyCardAction()
{
}

void CopyCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Copy Card , Click on a card to copy it : ");
	cellpos = pIn -> GetCellClicked();

	pCard = pGrid->hasCard(&cellpos) ;

	pOut->ClearStatusBar();
}
void CopyCardAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	if (pCard == NULL)
		pOut->PrintMessage("This cell has no card");

	else
	{
		pGrid->SetClipboard(pCard);
		pOut->PrintMessage("Card is copied to clipboard");
	}
}
