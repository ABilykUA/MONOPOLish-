#include "CPlayer.h"

#include <iostream>
using namespace std;

//constructor
CPlayer::CPlayer(string name, int money, int position) :mName(name), mMoney(money), mPosition(position) {}


//adds to Position
void CPlayer::AddPosition(int add) { mPosition += add; }

//adds to Money
void CPlayer::AddMoney(int add) { mMoney += add; }

//subtracts Money
void CPlayer::SubtractMoney(int subtract) { mMoney -= subtract; }

//if player passes go adds money 
void CPlayer::PassGo() { 
	mMoney += 200; 
	cout << "" << endl;
	cout << GetName() << " passes GO and collects £200 his balance is now : " << GetMoney() << endl;
}




void CPlayer::CheckIfGoIsPassed() {

	if (GetPosition() >= 26)
	{
		mPosition -= 26;
		PassGo();
	}

}
