#pragma once
#include "Object.h"
class ObstructBase :
    public Object
{
public:
    ObstructBase();
    virtual ~ObstructBase();
    virtual void Update(float deltaTime) = 0;

protected:
    enum TYPE
    {
        METEOR,BULLET
    };
    int type;
};

