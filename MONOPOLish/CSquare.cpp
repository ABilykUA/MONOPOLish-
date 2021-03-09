//Andrii Bilyk

#include "CSquare.h"

#include <string>
#include <iostream>

using namespace std;

//constructor											setting up pointers 
CSquare::CSquare(int id, string name) : mCode(new int), mName(new string) { 


	SetID(id);

	SetName(name);

}

//destructor

CSquare::~CSquare()
{
	
	//deallocate memory by deleting operators

	delete mCode;
	
	delete mName;



}

void CSquare::PlayerLandsOn(CPlayer* player) {}


void CSquare::LandOnRE(CPlayer* player1, CPlayer* player2) {}

void CSquare::LandOnBonusORPenalty(CPlayer* player1, int random) {}




