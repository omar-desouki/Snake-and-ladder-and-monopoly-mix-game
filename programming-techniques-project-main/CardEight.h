#pragma once

#include "Card.h"

class CardEight : public Card
{
	int AmountOfCoins;

public:
	CardEight();
	CardEight(const CellPosition& Position);  // Constructor that takes the Card Position

	virtual void ReadCardParameters(Grid* pGrid);  // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer);  // Applies the effect of CardOne on the passed Player									  // by decrementing the player's wallet by the walletAmount data member
	virtual void Load(ifstream& Infile);
	virtual void Save(ofstream& OutFile, GameObjectType type);
	void SetAmountOfCoins(int amount);
	Card* Clone(CellPosition newPosition);
	virtual ~CardEight(); // A Virtual Destructor

};
