#include "CJail.h"
#include <iostream>

CJail::CJail(int id, string name) : CSquare(id, name)
{
}

void CJail::LandOn(CPlayer* player){

	if (player->GetPosition() == 6)
	{
		cout << player->GetName() + " lands on Jail" << endl;

		cout <<" "<< endl;

		cout << player->GetName() + " is just visiting" << endl;

	}

}
