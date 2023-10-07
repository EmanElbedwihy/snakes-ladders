#pragma once
#include "Card.h"

// [ CardSeven ] Summary:
// Its Apply() Function: Restarts the game for the first player whose cell is after the current player in the grid.
//(Restarting the game for a player makes him go to cell number 1).
// Its Parameters: no parameters
class CardSeven : public Card
{

public:
	CardSeven(const CellPosition& pos); // A Constructor takes card position


	virtual void Apply(Grid* pGrid, Player* pPlayer);
	/*void CardSeven::Save(ofstream Outfile, Type GOtype);
	void CardSeven::Load(ifstream& Infile);*/
	virtual ~CardSeven(); // A Virtual Destructor
};

