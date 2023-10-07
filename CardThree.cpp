#include "CardThree.h"

CardThree::CardThree(const CellPosition& pos) : Card(pos)
{
	cardNumber = 3;
}
CardThree::~CardThree(void)
{
}
void CardThree::ReadCardParameters(Grid* pGrid)
{
	// Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New CardThree");

	pOut->ClearStatusBar();
}
void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Apply(pGrid, pPlayer);
	

}

