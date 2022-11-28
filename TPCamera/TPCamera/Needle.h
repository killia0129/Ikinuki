#pragma once
#include "ObstructBase.h"
#include"game.h"
class Needle :
    public ObstructBase
{
public:
    Needle(VECTOR _pos);
    virtual ~Needle();
    void Update(float deltaTime);
    void Draw();

private:
    float moveDis;
    void ColorChanger();
    int redColorValue;
    float turnRad;
    unsigned int Color;
    const float needleLong = 2.0f;
    const float needleWidth = 1.5f;
};

