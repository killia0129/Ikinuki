#include "LineEffect.h"

LineEffect::LineEffect()
{
    endFlag = false;
    curvingFlag = false;
    curvedFlag = false;
    switch (rand()%4)
    {
    case 0:
        curveType = STRAIGHT;
        break;

    case 1:
        curveType = CURVE_HI;
        break;

    case 2:
        curveType = CURVE_LOW;
        break;

    case 3:
        curveType = STRAYLIGHT;
        break;
    default:
        curveType = STRAYLIGHT;
        break;
    }
    if (rand() % 2 == 0)
    {
        if (rand() % 2 == 0)
        {
            pos = VGet(20.0 + (rand() % 20), 20.0 + (rand() % 20), 550);
        }
        else
        {
            pos = VGet(20.0 + (rand() % 20), 20.0 - (rand() % 20), 550);
        }
    }
    else
    {
        if (rand() % 2 == 0)
        {
            pos = VGet(20.0 - (rand() % 20), 20.0 + (rand() % 20), 550);
        }
        else
        {
            pos = VGet(20.0 - (rand() % 20), 20.0 - (rand() % 20), 550);
        }
    }
    midPos = pos;
    midPos.z -= LineLength / 2.0f;
    endPos = pos;
    endPos.z -= LineLength;
}

LineEffect::~LineEffect()
{
}

void LineEffect::Update(float deltaTime)
{
}

void LineEffect::Draw()
{
}
