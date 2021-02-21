#pragma once
//Andrii Bilyk

#include "CSquare.h"
#include "CPlayer.h"

using namespace std;

class CRealEstate :
    public CSquare
{

public:    
    //constructor

    //subject to change is fro 40+
    CRealEstate(int id, string name);

    //original constructor where cost,rend,cg are set
    CRealEstate(int id, string name, int Cost, int Rent, int ColourGroup);
    
    //Methods
    void LandOnRE(CPlayer* player1, CPlayer* player2);
    
   
    //setter and getters 

    int GetCost() { return mCost; }
    int GetRent() { return mRent; }
    int GetColourGroup() { return mColourGroup; }

    string GetBoughtBy() { return mBoughtBy; }
    bool GetIsBought() { return IsBought; }


    void SetBoughtBy(string boughtby) { mBoughtBy = boughtby; }
    void SetIsBought(bool bought) { IsBought = bought; }



private:

    //input by game rules
    int mCost, mRent, mColourGroup;
    
    //mBoughtBy is used to track who bought the RE
    string mBoughtBy;

    //IsBought is used to track if the RE is sold
    bool IsBought;


};

