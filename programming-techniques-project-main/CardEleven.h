#pragma once

#include "Card.h"

class CardEleven : public Card
{
	static int CardPrice;
	static int FeesToPay;
	static bool Cardbought;
	static Player* Owner;
	static bool CardInitialized;

public:
	CardEleven();
	CardEleven(const CellPosition& Position);  // Constructor that takes the Card Position

	virtual void ReadCardParameters(Grid* pGrid);  // Reads the parameters of CardOne which is: walletAmount
	virtual void Apply(Grid* pGrid, Player* pPlayer);  // Applies the effect of CardOne on the passed Player									
													   // by decrementing the player's wallet by the walletAmount data member
	virtual void Load(ifstream& Infile);
	virtual void Save(ofstream& OutFile, GameObjectType type);

	static Player* GetOwner();
	static void SetOwner(Player* player);
	static int GetCellPrice();
	Card* Clone(CellPosition newPosition);
	static void SetCardbought(bool S); // setter for card bought

	virtual ~CardEleven(); // A Virtual Destructor

};