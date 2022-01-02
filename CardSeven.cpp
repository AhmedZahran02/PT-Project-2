#include "CardSeven.h"
CardSeven::CardSeven(const CellPosition& pos)
	: Card(pos)
{
	cardNumber = 7;
}

CardSeven::~CardSeven()
{

}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->AdvanceCurrentPlayer();
	Player* currPlayer = pGrid->GetCurrentPlayer();
	CellPosition start(8, 0);
	for (int i = 0; i < 3; i++) {
		pPlayer = pGrid->GetCurrentPlayer();
		if (pPlayer->GetStepCount() > position.GetCellNum()) {
			pGrid->UpdatePlayerCell(pPlayer, start);
			pPlayer->SetStepCount(1);
			break;
		}
		else pGrid->AdvanceCurrentPlayer();
	}
	pGrid->SetCurrentPlayer((currPlayer->GetPlayerNum() + 3) % 4);
}