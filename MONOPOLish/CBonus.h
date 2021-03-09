#pragma once
#include "CSquare.h"
class CBonus :
    public CSquare
{
public:
    
    CBonus(int id, string name);
    ~CBonus();
    virtual void LandOnBonusORPenalty(CPlayer* player1, int random) override;

private:

};

