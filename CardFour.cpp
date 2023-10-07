#include "CardFour.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos)
{
	cardNumber = 4;
}
CardFour::~CardFour(void)
{
}
void CardFour::ReadCardParameters(Grid* pGrid)
{
	// Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New CardThree");

	pOut->ClearStatusBar();
}
void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Apply(pGrid, pPlayer);


}
