#include<math.h>
#include "Exprosion.h"

Exprosion::Exprosion(VECTOR _pos)
{
    pos = _pos;
    count = 1.0f;
    end = false;
}

Exprosion::~Exprosion()
{
}

void Exprosion::Update(float deltaTime)
{
    count -= deltaTime;
    if (count < 0.0f)
    {
        end = true;
    }
}

void Exprosion::Draw()
{
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 144);
    DrawSphere3D(pos, 7.5 * (sinf(count * DX_PI_F)), 8, GetColor(255, 0, 0), GetColor(255, 0, 0), true);
    DrawSphere3D(pos, 12.0 * (sinf(count * DX_PI_F)), 8, GetColor(255, 0, 0), GetColor(255, 0, 0), false);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
    SetFontSize(10);
    DrawString(ConvWorldPosToScreenPos(pos).x - 20, ConvWorldPosToScreenPos(pos).y - 5, "NICE!", GetColor(255, 255, 255));
    SetFontSize(40);
}
