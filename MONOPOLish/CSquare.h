#pragma once
//Andrii Bilyk
#include "CPlayer.h"
#include <memory.h>
#include <string>
#include <vector>


using namespace std;

class CSquare
{
public:

	//constructor										 
	CSquare(int id , string name);

	void LandOnSquare(CPlayer* player1, CPlayer* player2, int random);

	//functions 
	virtual void LandOn(CPlayer* player1);

	virtual void LandOn(CPlayer*  player1, int random);

	virtual void LandOn(CPlayer*  player1, CPlayer*  player2);

	
	//getters and setters 
	void SetID(int input) { mCode = input;}
	void SetName(string input) { mName = input; }


	int GetID() { return mCode; }
	string GetName() { return mName; }

private:

	int mCode;
	string mName;


};


