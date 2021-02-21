#include "CRealEstate.h"
#include "CPlayer.h"

#include <iostream>
#include <string>

using namespace std;


CRealEstate::CRealEstate(int id, string name) : CSquare(id, name), mRent(0), IsBought(true), mBoughtBy("Company") {}

CRealEstate::CRealEstate(int id, string name, int Cost, int Rent, int ColourGroup): CSquare(id, name), mCost(Cost),mRent(Rent),mColourGroup(ColourGroup),IsBought(false),mBoughtBy(""){}

//comment here
void CRealEstate::LandOnRE(CPlayer* player1 , CPlayer* player2) {

	//comment here
	if (GetIsBought() == false)
	{
		//comment here
		if (player1->GetMoney() > 0)
		{
			player1->SubtractMoney(GetCost());

			SetIsBought(true);

			SetBoughtBy(player1->GetName());

			cout << player1->GetName() << " buys " << GetName() << " for " << GetCost() << endl;

		}
	}

	//comment here
	if (GetIsBought() == true)
	{
		//comment here
		if (player1->GetName() != GetBoughtBy()) {

			player1->SubtractMoney(GetRent());
			
			player2->AddMoney(GetRent());

			cout << player1->GetName() << " pays " << GetRent() << endl;

		}

	}








}

