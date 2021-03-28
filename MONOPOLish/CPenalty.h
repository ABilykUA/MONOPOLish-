#pragma once
#include "CSquare.h"

class CPenalty :
    public CSquare
{
public:
   
    CPenalty(int id, string name);


     void LandOn(CPlayer* player1, int random) override;

private:

};

