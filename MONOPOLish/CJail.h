#pragma once
#include "CSquare.h"
class CJail :
    public CSquare
{

public:

    CJail(int id, string name); 
    ~CJail();

    
    void PlayerLandsOn(CPlayer* player) override;

private:




};

