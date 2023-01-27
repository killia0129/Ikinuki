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
    int curveType;
    VECTOR midPos;
    VECTOR endPos;
    const float LineLength = 3.0f;

    enum LINE_TYPE
    {
        STRAIGHT,CURVE_HI,CURVE_LOW,STRAYLIGHT
    };
};

