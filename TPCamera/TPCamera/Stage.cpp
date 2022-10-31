#include "Stage.h"

Stage::Stage()
{
    for (int i = 0; i < 3; i++)
    {
        reftArrow[i] = VGet(20.0f, 0.0f, 500.0f + (250 * i));
        lightArrow[i] = VGet(-20.0f, 0.0f, 500.0f + (250 * i));
    }
}

Stage::~Stage()
{
}

void Stage::Update(float deltaTime)
{
    for (int i = 0; i < 3; i++)
    {
        lightArrow[i] = VGet(lightArrow[i].x, lightArrow[i].y, lightArrow[i].z - 3.0f);
        reftArrow[i] = VGet(reftArrow[i].x, reftArrow[i].y , reftArrow[i].z - 3.0f);

        if (lightArrow[i].z < 0.0f)
        {
            reftArrow[i] = VGet(20.0f, 0.0f, 500.0f);
            lightArrow[i] = VGet(-20.0f, 0.0f, 500.0f);
        }
    }
}

void Stage::Draw()
{
    DrawCube3D(VGet(-20.0f, -20.0f, -20.0f), VGet(20.0f, 20.0f, 500.0f), GetColor(0, 255, 0), GetColor(0, 255, 0), false);
    for (int i = 0; i < 3; i++)
    {
        DrawTriangle3D(lightArrow[i], VGet(lightArrow[i].x, lightArrow[i].y - 10.0f, lightArrow[i].z + 10.0f), VGet(lightArrow[i].x, lightArrow[i].y + 10.0f, lightArrow[i].z + 10.0f), GetColor(0, 255, 0), true);
        DrawTriangle3D(reftArrow[i], VGet(reftArrow[i].x, reftArrow[i].y - 10.0f, reftArrow[i].z + 10.0f), VGet(reftArrow[i].x, reftArrow[i].y + 10.0f, reftArrow[i].z + 10.0f), GetColor(0, 255, 0), true);
    }
}
