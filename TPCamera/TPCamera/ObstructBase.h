#pragma once
#include "Object.h"
class ObstructBase :
    public Object
{
public:
    ObstructBase();
    virtual ~ObstructBase();

protected:
    enum TYPE;//Ç±Ç±å„Ç≈èëÇ≠
    int type;
};

