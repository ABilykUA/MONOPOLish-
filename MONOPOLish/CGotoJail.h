#pragma once
#include "CSquare.h"
class CGotoJail :
    public CSquare
{

public:

    CGotoJail(int id, string name);
 

    void LandOn(CPlayer* player) override;


private:





};

