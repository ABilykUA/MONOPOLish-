﻿#include "CPlayer.h"

#include <iostream>
using namespace std;


const char POUND = 156;

//constructor										
CPlayer::CPlayer(string name, int money, int position) :mName(name),mMoney(money), mPosition(position) {}

//adds to Position
void CPlayer::AddPosition(int add) { mPosition += add; }

//subtracts from Money
void CPlayer::SubtractPosition(int subtract) { mPosition -= subtract; }

//adds to Money
void CPlayer::AddMoney(int add) { mMoney += add; }

//subtracts from Money
void CPlayer::SubtractMoney(int subtract) { mMoney -= subtract; }


//Checks if player passes go. It checks if players position is more than 26 it subtracts 26 to simulate a passby 
void CPlayer::CheckIfGoIsPassed() {

	if (GetPosition() >= 26)
	{
		SubtractPosition(26);
		AddMoney(200);
		cout << "" << endl;
		cout << GetName() << " passes GO and collects " << POUND<< "200 his balance is now : " << GetMoney() << endl;
		cout << "" << endl;
	}

}
