#pragma once
#include "card.h"
class CardSix : public Card
{
private:
	int CellToGoTo;

public:
	CardSix();
	CardSix(const CellPosition & pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	                                                  // by decrementing the player's wallet by the walletAmount data member
	virtual void Load(ifstream& Infile);
	virtual void Save(ofstream& OutFile, GameObjectType type);
	Card* Clone(CellPosition newPosition);
	void SetCellToGoTo(int cellNum);
	virtual ~CardSix(); // A Virtual Destructor
};

