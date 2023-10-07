#include "PasteCardAction.h"

PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
	
}

PasteCardAction ::~PasteCardAction()
{
}
void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Paste Card , Click on a cell to paste card : ");
	cellpos = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}
void PasteCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	ReadActionParameters();
	pCard = pGrid->GetClipboard();


	//pGrid->AddObjectToCell(pCard);


}

