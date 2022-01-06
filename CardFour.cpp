#include "CardFour.h"
#include "ApplicationManager.h"
#include "RollDiceAction.h"

bool CardFour::Card4Players[MaxPlayerCount];
int CardFour::arrRemRolls[MaxPlayerCount];

CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number (4 here)
}

CardFour::~CardFour(void)
{
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- prevent the pPlayer from the next dice roll
	pGrid->PrintErrorMessage("You have landed on Card 4, you are prevented from rolling the next turn!");
	
	int playerNum = pPlayer->GetPlayerNum();
	Card4Players[playerNum] = true;
	arrRemRolls[playerNum] = 1;
}

bool CardFour::isCard4Players(int playerNum) const
{
	return Card4Players[playerNum];
}

int CardFour::GetRemRolls(int playerNum) const
{
	return arrRemRolls[playerNum];
}

void CardFour::DecrementRemRolls(int playerNum)
{
	arrRemRolls[playerNum]--;
}

void CardFour::free(int playerNum)
{
	Card4Players[playerNum] = false;
}
