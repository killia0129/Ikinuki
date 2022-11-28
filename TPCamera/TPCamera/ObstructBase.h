#pragma once
#include "Object.h"
class ObstructBase :
    public Object
{
public:
    ObstructBase();
    virtual ~ObstructBase();
    virtual void Update(float deltaTime) = 0;
    virtual void Draw() = 0;

protected:
    enum TYPE
    {
        METEOR,NEEDLE
    };
    int type;
};

