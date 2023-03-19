#pragma once

#include "GameObject.h"

class Snake :	public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the Snake's "Start Cell Position"

	CellPosition endCellPos; // here is the Snake's End Cell Position

public:
	Snake();

	Snake(const CellPosition & startCellPos, const CellPosition & endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a Snake from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the Snake by moving player to Snake's end cell

	virtual	bool AreOverlapping(GameObject* Obj) const; 


	CellPosition GetEndPosition() const; // A getter for the endCellPos data member
	virtual GameObjectType GetType();
	virtual void Save(ofstream& OutFile, GameObjectType type);
	virtual void Load(ifstream& Infile);
	virtual ~Snake(); // Virtual destructor
};

