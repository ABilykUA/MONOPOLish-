#pragma once
//Andrii Bilyk

#include <string>
#include "CPlayer.h"


using namespace std;

class CSquare
{
public:

	//constructor										 
	CSquare(int id , string name);


	//functions 
	virtual void LandOn(CPlayer* player);

	virtual void LandOn(CPlayer* player1, CPlayer* player2);

	virtual void LandOn(CPlayer* player1, int random);


	//getters and setters 
	void SetID(int input) { mCode = input;}
	void SetName(string input) { mName = input; }


	int GetID() { return mCode; }
	string GetName() { return mName; }

private:

	int mCode;
	string mName;


};


