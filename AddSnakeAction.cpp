#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddSnakeAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	if (startPos.IsValidCell() && endPos.IsValidCell())
	{
		//next block of code is for the case if (this snake overlaps with another snake)"//

		int SnakeLength = endPos.VCell() - startPos.VCell() - 1;  //to check if there's another snake in this snake's region 
															   //from start.VCell to the (endpos-1).VCell, since the endpos.VCell
															   //case has different type of error
		CellPosition SCheck;
		SCheck.SetHCell(startPos.HCell());
		SCheck.SetVCell(startPos.VCell());
		int vcell = startPos.VCell() + 1;
		bool hasNoSnake = true;
		int i = 0;

		while (hasNoSnake && i < SnakeLength)
		{
			if (pGrid->hasSnake(&SCheck))
				hasNoSnake = false;

			i++;
			SCheck.SetVCell(vcell + i);
		}
		//-------------------------------------//
		//next block of code is for the case if(the end cell of thi ladder has another ladder or snake or has a card”)
		bool hasNoObj = true;
		SCheck.SetVCell(endPos.VCell());

		if (!(pGrid->emptyCell(&startPos)) && !(pGrid->emptyCell(&endPos)))
			hasNoObj = false;

		//------------------------------------//
		//next block of code is to re-initialize the startPos and endPos of the addLadder attributes to be invalid cells (if they are)
		//so we could make sure that they won't be drawn in the interface unless they are valid / i want to remove the error message that's in 
		//the excution function since it's been already appeared in the read function, is it okay to do so? /

		if (!hasNoSnake || !hasNoObj || startPos.VCell() > endPos.VCell() || startPos.HCell() != endPos.HCell() || startPos.VCell() == endPos.VCell())
		{
			startPos.SetHCell(-1);
			startPos.SetVCell(-1);
			endPos.SetHCell(-1);
			endPos.SetVCell(-1);
		}

		//------------------------------------//

		if (!hasNoSnake)
			pGrid->PrintErrorMessage("Two Snakes cannot overlap, Click to continue . . .");
		else if (!hasNoObj)
			pGrid->PrintErrorMessage("end cell and start cell of two Game Objets can't be the same, Click to continue . . .");
		else if (startPos.VCell() > endPos.VCell())
			pGrid->PrintErrorMessage("End cell cannot be higher than start cell, Click to continue . . .");
		else if (startPos.HCell() != endPos.HCell())
			pGrid->PrintErrorMessage("End cell and start cell are not in the same column, Click to continue . . .");
		else if (startPos.VCell() == endPos.VCell())
			pGrid->PrintErrorMessage("End cell and start cell can't hold the same positions, Click to continue . . .");
		else if (startPos.GetCellNum() == 99 || endPos.GetCellNum() == 1)
			pGrid->PrintErrorMessage("You cannot place game objects in the first or last cell, Click to continue");
	}
	else
		pGrid->PrintErrorMessage("Invalid Cells, Click to continue . . .");

	pOut->ClearStatusBar();

}

void AddSnakeAction::Execute()
{

	ReadActionParameters();

	// Create a Snake object with the parameters read from the user

	Snake* pSnake = new Snake(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pSnake);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Snake Couldn't be added ! Click to continue ...");
	}

}

AddSnakeAction::~AddSnakeAction()
{
}

