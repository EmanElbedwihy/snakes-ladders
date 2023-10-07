#include "Snake.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) :GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
	if (startCellPos.VCell() > endCellPos.VCell() || startCellPos.HCell() != endCellPos.HCell())
	{
		position.SetHCell(-1);
		position.SetVCell(-1);
		(this->endCellPos).SetHCell(-1);
		(this->endCellPos).SetVCell(-1);
	}

}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

Snake::~Snake()
{
}

