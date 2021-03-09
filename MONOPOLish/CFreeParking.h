#pragma once
#include "CSquare.h"
class CFreeParking :
    public CSquare
{

public:
    CFreeParking(int id, string name);
    ~CFreeParking();


    void PlayerLandsOn(CPlayer* player) override;

private:


};

