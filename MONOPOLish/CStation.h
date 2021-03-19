#pragma once
#include "CRealEstate.h"
class CStation :
    public CRealEstate
{
public:

    CStation(int id, string name, int Cost, int Rent);
    

    void LandOn(CPlayer* player1, CPlayer* player2) override;

private:



};

