#include<math.h>
#include "Needle.h"

Needle::Needle(VECTOR _pos)
{
    pos = _pos;
    moveDis = 0.0f;
    Color = GetColor(0, 255, 0);
    redColorValue = 0;
    type = NEEDLE;
    turnRad = 0.0f;
}

Needle::~Needle()
{
}

void Needle::Update(float deltaTime)
{
    turnRad += turnSpeed * deltaTime * 10.0f;
    pos.z -= obsSpeed * deltaTime * 1.2f;
    moveDis += obsSpeed * deltaTime * 1.2;
    ColorChanger();
}

void Needle::Draw()
{
    DrawCone3D(pos, VGet(pos.x, pos.y, pos.z + needleLong), needleWidth, 16, Color, Color, true);
    DrawCone3D(pos, VGet(pos.x, pos.y, pos.z + needleLong), needleWidth, 8, GetColor(0, 255, 0), GetColor(0,255,0), false);
}

void Needle::ColorChanger()
{
    redColorValue = 255 * (moveDis / stageLength);
    Color = GetColor(redColorValue, 255 - redColorValue, 0);
}
