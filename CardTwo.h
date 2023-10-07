#pragma once
#include "Card.h"
class CardTwo : public Card
{
public:
	CardTwo(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardTwo();
};

