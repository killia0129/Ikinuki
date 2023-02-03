#include<math.h>
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
            pos = VGet(20.0 + (rand() % 100), 20.0 + (rand() % 50), 550);
        }
        else
        {
            pos = VGet(20.0 + (rand() % 100), -20.0 - (rand() % 50), 550);
        }
    }
    else
    {
        if (rand() % 2 == 0)
        {
            pos = VGet(-20.0 - (rand() % 100), 20.0 + (rand() % 50), 550);
        }
        else
        {
            pos = VGet(-20.0 - (rand() % 100), -20.0 - (rand() % 50), 550);
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
    switch (curveType)
    {
    case STRAIGHT:
        StraightUpdate(deltaTime);
        break;

    case CURVE_HI:
        CurveHiUpdate(deltaTime);
        break;

    case CURVE_LOW:
        CurveLowUpdate(deltaTime);
        break;

    case STRAYLIGHT:
        StraightUpdate(deltaTime);
        break;

    default:
        StraightUpdate(deltaTime);
        break;
    }

    if (endPos.z < 0.0f)
    {
        endFlag = true;
    }
}

void LineEffect::Draw()
{
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 96);
    DrawLine3D(pos, midPos, GetColor(0, 255, 0));
    DrawLine3D(midPos, endPos, GetColor(0, 255, 0));
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void LineEffect::StraightUpdate(float deltaTime)
{
    pos.z -= LineSpeed * deltaTime;
    midPos.z -= LineSpeed * deltaTime;
    endPos.z -= LineSpeed * deltaTime;
}

void LineEffect::CurveHiUpdate(float deltaTime)
{
    if (rand() % 50 == 0 && !curvedFlag && !curvingFlag)
    {
        curvingFlag = true;
        midPos = pos;
    }
    else
    {
        pos.z -= LineSpeed * deltaTime;
        midPos.z -= LineSpeed * deltaTime;
        endPos.z -= LineSpeed * deltaTime;
    }
    if (curvingFlag && !curvedFlag)
    {
        pos.y += LineSpeed * deltaTime;
        endPos.z -= LineSpeed * deltaTime;
        if (endPos.z <= midPos.z)
        {
            float tmp;
            tmp = midPos.z - endPos.z;
            pos.y += tmp;
            endPos = midPos;
            curvedFlag = true;
            midPos = pos;
        }
    }
    if (curvingFlag && curvedFlag)
    {
        pos.z -= LineSpeed * deltaTime;
        endPos.y += LineSpeed * deltaTime;
        if (endPos.y >= midPos.y)
        {
            float tmp;
            tmp = endPos.y - midPos.y;
            pos.z -= tmp;
            endPos = midPos;
            curvingFlag = false;
            midPos = pos;
        }
    }
    if (!curvingFlag && curvedFlag)
    {
        pos.z -= LineSpeed * deltaTime;
        midPos.z -= LineSpeed * deltaTime;
        endPos.z -= LineSpeed * deltaTime;
    }
}

void LineEffect::CurveLowUpdate(float deltaTime)
{
    if (rand() % 50 == 0 && !curvedFlag && !curvingFlag)
    {
        curvingFlag = true;
        midPos = pos;
    }
    else
    {
        pos.z -= LineSpeed * deltaTime;
        midPos.z -= LineSpeed * deltaTime;
        endPos.z -= LineSpeed * deltaTime;
    }
    if (curvingFlag && !curvedFlag)
    {
        pos.y -= LineSpeed * deltaTime;
        endPos.z -= LineSpeed * deltaTime;
        if (endPos.z <= midPos.z)
        {
            float tmp;
            tmp = midPos.z - endPos.z;
            pos.y -= tmp;
            endPos = midPos;
            curvedFlag = true;
            midPos = pos;
        }
    }
    if (curvingFlag && curvedFlag)
    {
        pos.z -= LineSpeed * deltaTime;
        endPos.y -= LineSpeed * deltaTime;
        if (endPos.y <= midPos.y)
        {
            float tmp;
            tmp = midPos.y - endPos.y;
            pos.z -= tmp;
            endPos = midPos;
            curvingFlag = false;
            midPos = pos;
        }
    }
    if (!curvingFlag && curvedFlag)
    {
        pos.z -= LineSpeed * deltaTime;
        midPos.z -= LineSpeed * deltaTime;
        endPos.z -= LineSpeed * deltaTime;
    }
}

void LineEffect::StrayLightUpdate(float deltaTime)
{
    int randI;
    float randF;
    randI = rand() % 10;
    randF = (float)randI / 10.0f;
    pos.z -= LineSpeed * deltaTime * sinf(randF);
    endPos.z -= LineSpeed * deltaTime * sinf(randF);
    if (randI % 2 == 0)
    {
        pos.y += LineSpeed * deltaTime * (1.0f - sinf(randF));
        endPos.y += LineSpeed * deltaTime * (1.0f - sinf(randF));
    }
    else
    {
        pos.y -= LineSpeed * deltaTime * (1.0f - sinf(randF));
        endPos.y -= LineSpeed * deltaTime * (1.0f - sinf(randF));
    }
    midPos = pos;
}
