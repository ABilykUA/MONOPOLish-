#include "CStation.h"
#include <iostream>

CStation::CStation(int id, string name, int Cost, int Rent) : CRealEstate(id, name, Cost, Rent) {}


void CStation::LandOn(CPlayer* player1, CPlayer* player2)
{

	switch (GetIsBought())
	{

	case true:

		
		if (player1->GetName() != GetBoughtBy()) {

			player1->SubtractMoney(GetRent());

			player2->AddMoney(GetRent());

			cout  << player1->GetName() << " pays " << GetRent() << "for the ticket" << endl;

		}

		break;

	case false:

		if (player1->GetMoney() > 0)
		{
			player1->SubtractMoney(GetCost());

			SetIsBought(true);

			SetBoughtBy(player1->GetName());

			cout << player1->GetName() << " buys " << GetName() << " for " << GetCost() << endl;

		}

		break;


	}

}
