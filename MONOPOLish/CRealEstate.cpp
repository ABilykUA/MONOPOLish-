#include "CRealEstate.h"
#include "CPlayer.h"
#include <iostream>
#include <string>

using namespace std;




CRealEstate::CRealEstate(int id, string name, int Cost, int Rent) : CSquare(id, name), mCost(Cost), mRent(Rent), mColourGroup(15), IsBought(false), mBoughtBy("") {}

CRealEstate::CRealEstate(int id, string name, int Cost, int Rent, int ColourGroup): CSquare(id, name), mCost(Cost),mRent(Rent),mColourGroup(ColourGroup),IsBought(false),mBoughtBy(""){}


void CRealEstate::LandOn(CPlayer* player1, CPlayer* player2)  {

	switch (GetIsBought())
	{

	case true:

		//comment here
		if (player1->GetName() != GetBoughtBy()) {



			player1->SubtractMoney(GetRent());

			player2->AddMoney(GetRent());

			cout << player1->GetName() << " pays " << GetRent() << endl;


			//if (CheckIfFullHouse(board, player1) != true)
			//{
			//	player1->SubtractMoney(GetRent());

			//	player2->AddMoney(GetRent());

			//	cout << player1->GetName() << " pays " << GetRent() << endl;

			//}
			//else {
			//
			//	player1->SubtractMoney(GetRent() * 2 );

			//	player2->AddMoney(GetRent() * 2);

			//	cout << player1->GetName() << " pays " << GetRent() * 2 << endl;

			//
			//}


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

