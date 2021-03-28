#pragma once
#include "CSquare.h"
#include "CPlayer.h"


class CBonus :
    public CSquare
{
public:
    
    CBonus(int id, string name);
  
     void LandOn(CPlayer* player1, int random) override;

private:

};


