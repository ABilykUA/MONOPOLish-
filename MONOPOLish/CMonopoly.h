#pragma once
#include "CPlayer.h"
#include <memory>
#include "CSquare.h"
class CMonopoly
{

public:
	CMonopoly();
	~CMonopoly();

	void Play();
	void GetArryData(vector<shared_ptr<CSquare>> mboard);
	void Turn(CPlayer* player1, CPlayer* player2);
	void WinCondition(int i, CPlayer* Dog, CPlayer* Car);
	int Random();

private:


	vector<shared_ptr<CSquare>> mboard;

	CPlayer* mDog;

	CPlayer* mCar;

};

