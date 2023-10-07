#include "Ladder.h"

Ladder::Ladder(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{

	this->endCellPos = endCellPos;
	///TODO: Do the needed validation
	if (startCellPos.VCell() < endCellPos.VCell() || startCellPos.HCell() != endCellPos.HCell())
	{
		position.SetHCell(-1);
		position.SetVCell(-1);
		(this->endCellPos).SetHCell(-1);
		(this->endCellPos).SetVCell(-1);
	}

}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Output* pOut = pGrid->GetOutput();

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pOut->PrintMessage("You have reached a ladder, Click to continue ...");
	// 2- Apply the ladder's effect by moving the player to the endCellPos

	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

	//    Review the "pGrid" functions and decide which function can be used for that


}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
}
