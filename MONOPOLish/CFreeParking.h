#pragma once
#include "CSquare.h"
class CFreeParking :
    public CSquare
{

public:
    CFreeParking(int id, string name);



    void LandOn(CPlayer* player1) override;

private:


};

