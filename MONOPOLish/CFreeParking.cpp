#include "CFreeParking.h"
#include <iostream>

CFreeParking::CFreeParking(int id, string name) : CSquare(id, name){}


void CFreeParking::LandOn(CPlayer*  player)
{

	if (player->GetPosition() == 13)
	{

		cout << player->GetName() + "lands on Free Parking" << endl;
		
		cout << " " << endl;

		cout << player->GetName() + " is resting" << endl;
	}

}
