#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	///TODO: Make the needed validations on the read parameters

	//should i force the user to click on the grid or should i just end the operation if he clicked on an invalid one?
	// and if i should force him, how can i end the operation if he decided to? is there any function or icon that could cancle the operation?
	//f the following bolock of code should be implemented, the if condition after the block must be removed and just keep what's inside the if block
	/*if(!startPos.IsValidCell() || !endPos.IsValidCell())
		do
		{
			pOut->PrintMessage("Invalid Cells, Click on a cell in the grid itself . . .");

			pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
			startPos = pIn->GetCellClicked();

			pOut->PrintMessage("New Ladder: Click on its End Cell ...");
			endPos = pIn->GetCellClicked();
		} while (!startPos.IsValidCell() || !endPos.IsValidCell());*/

	if (startPos.IsValidCell() && endPos.IsValidCell())
	{

		//next block of code is for the case if (this ladder overlaps with another ladder)"//

		int ladderHeight = startPos.VCell() - endPos.VCell() - 1;  //to check if there's another ladder in this ladder's region 
															   //from (startpos-1).VCell to the (endpos-1).VCell

		CellPosition LCheck;
		LCheck.SetHCell(startPos.HCell());
		LCheck.SetVCell(startPos.VCell() - 1);
		int vcell = startPos.VCell() - 1;
		bool hasNoLadder = true;
		int i = 0;

		while (hasNoLadder && i < ladderHeight)
		{
			if (pGrid->hasLadder(&LCheck))
				hasNoLadder = false;

			i++;
			LCheck.SetVCell(vcell - i);
		}
		//-------------------------------------//
		//next block of code is for the case if(the end cell of thi ladder has another ladder or snake or has a card”)
		bool hasNoObj = true;

		if (!(pGrid->emptyCell(&startPos)) && !(pGrid->emptyCell(&endPos)))
			hasNoObj = false;

		//------------------------------------//
		//next block of code is to re-initialize the startPos and endPos of the addLadder attributes to be invalid cells (if they are)
		//so we could make sure that they won't be drawn in the interface unless they are valid/ i want to remove the error message that's in 
		//the excution function since it's been already appeared in the read function/

		if (!hasNoLadder || !hasNoObj || startPos.VCell() < endPos.VCell() || startPos.HCell() != endPos.HCell() || startPos.VCell() == endPos.VCell())
		{
			startPos.SetHCell(-1);
			startPos.SetVCell(-1);
			endPos.SetHCell(-1);
			endPos.SetVCell(-1);
		}

		//------------------------------------//

		if (!hasNoLadder)
			pGrid->PrintErrorMessage("Two ladders cannot overlap, Click to continue . . .");
		else if (!hasNoObj)
			pGrid->PrintErrorMessage("end cell and start cell of two Game Objets can't be the same, Click to continue . . .");
		else if (startPos.VCell() < endPos.VCell())
			pGrid->PrintErrorMessage("End cell cannot be lower than the start cell, Click to continue . . .");
		else if (startPos.HCell() != endPos.HCell())
			pGrid->PrintErrorMessage("End cell and start cell are not in the same column, Click to continue . . .");
		else if (startPos.VCell() == endPos.VCell())
			pGrid->PrintErrorMessage("End cell and start cell of a ladder can't be on the same cell, Click to continue . . .");
		else if (startPos.GetCellNum() == 1 || endPos.GetCellNum() == 99)
			pGrid->PrintErrorMessage("You cannot place game objects in the first or last cell, Click to continue");
	}
	else
		pGrid->PrintErrorMessage("Invalid Cells, Click to continue . . .");

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Ladder object with the parameters read from the user

	Ladder* pLadder = new Ladder(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Ladder Couldn't be added ! Click to continue ...");
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}