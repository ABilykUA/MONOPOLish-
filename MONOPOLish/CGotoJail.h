#pragma once
#include "CSquare.h"
class CGotoJail :
    public CSquare
{

public:

    CGotoJail(int id, string name);
    ~CGotoJail();

    void PlayerLandsOn(CPlayer* player) override;


private:





};

