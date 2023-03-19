#include "OpenGridAction.h"
#include <iostream>
#include <fstream>
#include "ApplicationManager.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "Ladder.h"
#include "Snake.h"
#include "Snake.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include"CardEleven.h"
#include "CardTwelve.h"

OpenGridAction::OpenGridAction(ApplicationManager* pApp)
	:Action(pApp)
{
}

void OpenGridAction::ReadActionParameters()
{
	pManager->GetGrid()->GetOutput()->PrintMessage("Please enter file name");
	fileName = pManager->GetGrid()->GetInput()->GetString(pManager->GetGrid()->GetOutput());
}

void OpenGridAction::Execute()
{
	ReadActionParameters();
	ifstream fIn;
	fIn.open(fileName);
	if (fIn.fail()) {
		pManager->GetGrid()->GetOutput()->PrintMessage("file not found");
		return;
	}
	pManager->GetGrid()->ClearGrid();

	int numOfLadders;
	fIn >> numOfLadders;
	for (int i = 0; i < numOfLadders; ++i)
	{
		Ladder* ladder = new Ladder();
		ladder->Load(fIn);
		pManager->GetGrid()->AddObjectToCell(ladder);
	}
	int numOfSnakes;
	fIn >> numOfSnakes;
	for (int i = 0; i < numOfSnakes; ++i)
	{
		Snake* snake = new Snake();
		snake->Load(fIn);
		pManager->GetGrid()->AddObjectToCell(snake);
	}
	int numOfCards;
	fIn >> numOfCards;
	for (int i = 0; i < numOfCards; ++i)
	{
		int cardNumber;
		Card* pCard;
		fIn >> cardNumber;
		switch (cardNumber)
		{
		case 1:
			pCard = new CardOne();
			break;
		case 2:
			pCard = new CardTwo();
			break;

		case 3:
			pCard = new CardThree();
			break;

		case 4:
			pCard = new CardFour();
			break;

		case 5:
			pCard = new CardFive();
			break;

		case 6:
			pCard = new CardSix();
			break;

		case 7:
			pCard = new CardSeven();
			break;

		case 8:
			pCard = new CardEight();
			break;

		case 9:
			pCard = new CardNine();
			break;

		case 10:
			pCard = new CardTen();
			break;

		case 11:
			pCard = new CardEleven();
			break;

		case 12:
			pCard = new CardTwelve();
			break;
		}
		pCard->Load(fIn);
		pManager->GetGrid()->AddObjectToCell(pCard);

	}
	pManager->GetGrid()->GetOutput()->PrintMessage("Grid Opened");
}