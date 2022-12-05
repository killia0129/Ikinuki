#include<math.h>
#include "Meteor.h"

Meteor::Meteor(VECTOR _pos,bool _wave)
{
    pos = _pos;
    firstPosX = _pos.x;
    moveDis = 0.0f;
    rad = 2.5f;
    yaw = 0.0f;
    ang = 0.0f;
    wave = 0.0f;
    waveMoveFlag = _wave;
    Color = GetColor(0, 255, 0);
    redColorValue = 0;
    type = METEOR;
}

Meteor::~Meteor()
{
}

void Meteor::Draw()
{
    VECTOR pos1;
    VECTOR pos2;
    pos1.x = pos.x + rad * cos(ang * DX_PI_F);
    pos2.x = pos.x - rad * cos(ang * DX_PI_F);
    pos1.y = pos.y + rad * cos(0.25 * DX_PI_F);
    pos2.y = pos.y - rad * cos(0.25 * DX_PI_F);
    pos1.z = pos.z + rad * sin(ang * DX_PI_F);
    pos2.z = pos.z - rad * sin(ang * DX_PI_F);
    DrawCube3D(pos1, pos2, Color, Color, true);
    DrawCube3D(pos1, pos2, GetColor(0,255,0), GetColor(0, 255, 0), false);
    DrawLine3D(pos, VGet(pos.x, -20.0f, pos.z), Color);
    deltaSpeed = 0.0f;
    //DrawSphere3D(pos,10, 16, GetColor(255, 255, 255), GetColor(255, 255, 255),true);
}

void Meteor::Update(float deltaTime)
{
    deltaSpeed += deltaTime / 10.0f;
    addAngle(ang, deltaTime);
    addAngle(yaw, deltaTime);
    if (waveMoveFlag)
    {
        wave += waveSpeed * deltaTime;
        if (wave >= 2.0f)
        {
            wave = 0.0f;
        }
        pos.x = firstPosX + stageWidth / 4 * sinf(wave * DX_PI_F);
    }
    pos.z -= obsSpeed * deltaTime;
    moveDis += obsSpeed * deltaTime;
    ColorChanger();
}

void Meteor::addAngle(float& _ang, float deltaTime)
{
    _ang += turnSpeed * deltaTime;
    if (_ang >= 2.0f)
    {
        _ang = 0;
    }
}

void Meteor::ColorChanger()
{
    redColorValue = 255 *(moveDis / stageLength);
    Color = GetColor(redColorValue, 255 - redColorValue, 0);
}
