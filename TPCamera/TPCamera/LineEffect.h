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
    const float LineSpeed = 1.5f;
    void StraightUpdate(float deltaTime);
    void CurveHiUpdate(float deltaTime);
    void CurveLowUpdate(float deltaTime);
    void StrayLightUpdate(float deltaTime);

    enum LINE_TYPE
    {
        STRAIGHT,CURVE_HI,CURVE_LOW,STRAYLIGHT
    };
};

