#pragma once
#include "Card.h"
class CardTwo :
    public Card
{
public:
    CardTwo();
    CardTwo(CellPosition position);
    virtual void ReadCardParameters(Grid* pGrid);
    virtual void Apply(Grid* pGrid, Player* pPlayer);
    Card* Clone(CellPosition newPosition);
};

