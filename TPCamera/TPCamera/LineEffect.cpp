#include "LineEffect.h"

LineEffect::LineEffect()
{
    endFlag = false;
    if (rand() % 2 == 0)
    {
        if (rand() % 2 == 0)
        {
            pos = VGet(20.0 + (rand() % 20), 20.0 + (rand() % 20), 550);
        }
        //��肩��
    }
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
