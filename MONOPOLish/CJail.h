#pragma once
#include "CSquare.h"
class CJail :
    public CSquare
{

public:

    CJail(int id, string name);  
    void LandOn(CPlayer* player1) override;

private:




};

