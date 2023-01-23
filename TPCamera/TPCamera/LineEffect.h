#pragma once
#include"Object.h"
class LineEffect:public Object
{
public:
    LineEffect();
    virtual ~LineEffect();
    void Update(float deltaTime);
    void Draw();

private:
    bool endFlag;
    bool curvingFlag;
    bool curvedFlag;
    VECTOR midPos;
    VECTOR endPos;
};

