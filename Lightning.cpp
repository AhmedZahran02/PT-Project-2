#include "Lightning.h"
#include "Player.h"

Lightning::Lightning(ApplicationManager* pApp) : Attack(pApp)
{
	
}

void Lightning::ReadActionParameters()
{

}

Lightning::~Lightning()
{
}

// Execute the action
void Lightning::Execute(Grid* pGrid, Player* pPlayer)
{
	for (int i = 0; i < MaxPlayerCount-1; i++)
	{
		pGrid->AdvanceCurrentPlayer();
		pPlayer->SetWallet(pPlayer->GetWallet() - 20);
	}
	pGrid->AdvanceCurrentPlayer();
}
