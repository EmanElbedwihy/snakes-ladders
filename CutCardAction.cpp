#include "CutCardAction.h"

CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
	
}

CutCardAction ::~CutCardAction()
{
}

void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Cut Card , Click on a card to cut it : ");
	cellpos = pIn->GetCellClicked();

	pCard = pGrid->hasCard(&cellpos);

	pOut->ClearStatusBar();
}
void CutCardAction::Execute()
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
		pGrid->RemoveObjectFromCell(cellpos);
	}
}
