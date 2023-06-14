#include<math.h>
#include "Exprosion.h"

const float MaxCount = 0.5f;
const float CountDownSpeed = 1.2f;

Exprosion::Exprosion(VECTOR _pos)
{
    pos = _pos;
    count = MaxCount;
    end = false;
}

Exprosion::~Exprosion()
{
}

void Exprosion::Update(float deltaTime)
{
    count -= CountDownSpeed*deltaTime;
    if (count < 0.0f)
    {
        end = true;
    }
}

void Exprosion::Draw()
{
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * count);
    DrawSphere3D(pos, 500.0f * (1.0f-count), 8, GetColor(255, 0, 0), GetColor(255, 0, 0), false);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200 * count);
    DrawSphere3D(pos, 500.0f * (1.0f-count), 8, GetColor(255, 0, 0), GetColor(255, 0, 0), true);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
    SetFontSize(20);
    DrawString(ConvWorldPosToScreenPos(pos).x - 40, ConvWorldPosToScreenPos(pos).y - 5, "NICE!", GetColor(255, 255, 255));
    SetFontSize(40);
}
