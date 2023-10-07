#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos)
{
	cardNumber = 2;
}
CardTwo::~CardTwo(void)
{
}
void CardTwo::ReadCardParameters(Grid* pGrid)
{
	// Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New CardTwo");

	pOut->ClearStatusBar();
}
void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer); 

	Cell* pCell;
	CellPosition cellpos = pCell->GetCellPosition();

	Ladder* nextLadder = pGrid->GetNextLadder(cellpos);

	/*if (nextLadder != NULL)
	nextLadder->Apply(pGrid, pPlayer);*/

}
