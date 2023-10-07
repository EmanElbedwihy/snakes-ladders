#include "DeleteGameObjectAction.h"

DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) : Action(pApp)
{

}
DeleteGameObjectAction::~DeleteGameObjectAction()
{

}
void DeleteGameObjectAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Delete Game Object , Click on a object to delete it : ");
	cellpos = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}
void DeleteGameObjectAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	if (pGrid->emptyCell(&cellpos))
		pOut->PrintMessage("This Cell has no object");
	else
		pGrid->RemoveObjectFromCell(cellpos);
}
