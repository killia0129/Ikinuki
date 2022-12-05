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
    DrawSphere3D(pos, 5.0 * (sinf(count * DX_PI_F)), 8, GetColor(100, 255, 255), GetColor(100, 255, 255), false);
}
