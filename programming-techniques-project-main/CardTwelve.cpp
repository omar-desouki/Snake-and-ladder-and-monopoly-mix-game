#include "CardTwelve.h"
#include <climits>


CardTwelve::CardTwelve()
{
	cardNumber = 12;
}

CardTwelve::CardTwelve(CellPosition& pos): Card(pos)
{
	cardNumber = 12;
}

void CardTwelve::ReadCardParameters(Grid* pGrid)
{
}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	int MostExpensiveStation = -1;
	int station = 0;
	
	if (CardNine::GetCellPrice() > MostExpensiveStation && pPlayer == CardNine::GetOwner())
	{
		MostExpensiveStation = CardNine::GetCellPrice();
		station = 9;
	}
		
	if (CardTen::GetCellPrice() > MostExpensiveStation && pPlayer == CardTen::GetOwner())
	{
		MostExpensiveStation = CardTen::GetCellPrice();
		station = 10;
	}
	if (CardEleven::GetCellPrice() > MostExpensiveStation && pPlayer == CardEleven::GetOwner())
	{
		MostExpensiveStation = CardEleven::GetCellPrice();
		station = 11;
	}
	int minWallet = INT_MAX;
	Player* player;
	for (int i = 0; i < MaxPlayerCount; ++i)
	{
		if (pGrid->GetPlayerist()[i]->GetWallet() < minWallet && pGrid->GetPlayerist()[i] != pPlayer)
		{
			minWallet = pGrid->GetPlayerist()[i]->GetWallet();
			player = pGrid->GetPlayerist()[i];
		}
	}
	if (station == 9)
	{
		CardNine::SetOwner(player);
	}
	else if (station == 10)
	{
		CardTen::SetOwner(player);
	}
	else if (station == 11)
		CardEleven::SetOwner(player);
}

Card* CardTwelve::Clone(CellPosition newPosition)
{
	Card* newCard = new CardTwelve(newPosition);
	return newCard;
}