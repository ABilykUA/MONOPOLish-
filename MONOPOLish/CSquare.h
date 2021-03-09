#pragma once
//Andrii Bilyk

#include <string>
#include "CPlayer.h"


using namespace std;

class CSquare
{
public:


	//constructor											setting up pointers 
	CSquare(int id , string name);
	~CSquare();

	//functions 
	virtual void PlayerLandsOn(CPlayer* player);

	virtual void LandOnRE(CPlayer* player1, CPlayer* player2);
	
	//getters and setters 
	void SetID(int input) { *mCode = input;}
	void SetName(string input) { *mName = input; }


	int GetID() { return *mCode; }
	string GetName() { return *mName; }


private:


	int *mCode;
	string *mName;


};


