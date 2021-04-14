//Andrii Bilyk
#include "CPlayer.h"
#include <memory.h>
#include "CSquare.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

//constructor											
CSquare::CSquare(int id, string name) : mCode(id), mName(name) {}

void CSquare::LandOnSquare(CPlayer*  player1, CPlayer*  player2, int random)
{
	LandOn(player1);

	LandOn(player1,random);

	LandOn(player1, player2);
}

void CSquare::LandOn(CPlayer* player1)
{
}

void CSquare::LandOn(CPlayer*  player1, int random)
{
}

void CSquare::LandOn(CPlayer* player1, CPlayer* player2)
{
}

