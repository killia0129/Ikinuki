#include "BossScene.h"

BossScene::BossScene(VECTOR pos)
{
    BossScene::pos = pos;
    for (int i = 0; i < 32; i++)
    {
        prevPos[i] = BossScene::pos;
    }
    mainR = 14.0f;
    coreR = 7.0f;
    HP = 2.0f;
    rad = 0.0f;
    xSpeed = 0.3f;
    ySpeed = 0.4f;
    line1Start = VGet(pos.x + mainR * sinf(0.5f * DX_PI_F) * cosf(rad * DX_PI_F), pos.y + mainR * cos(0.5f * DX_PI_F), pos.z + mainR * sinf(0.5f * DX_PI_F) * sinf(rad * DX_PI_F));
    line1End = VGet(pos.x - mainR * sinf(0.5f * DX_PI_F) * cosf(rad * DX_PI_F), pos.y - mainR * cos(0.5f * DX_PI_F), pos.z - mainR * sinf(0.5f * DX_PI_F) * sinf(rad * DX_PI_F));
    line2Start = VGet(pos.x + mainR * sinf(0.5f * DX_PI_F) * cosf((rad + 0.5f) * DX_PI_F), pos.y - mainR * cos(0.5f * DX_PI_F), pos.z + mainR * sinf(0.5f * DX_PI_F) * sinf((rad + 0.5f) * DX_PI_F));
    line2End = VGet(pos.x - mainR * sinf(0.5f * DX_PI_F) * cosf((rad + 0.5f) * DX_PI_F), pos.y + mainR * cos(0.5f * DX_PI_F), pos.z - mainR * sinf(0.5f * DX_PI_F) * sinf((rad + 0.5f) * DX_PI_F));
    Color = GetColor(0, 255, 0);
    redColorValue = 0;
}

BossScene::~BossScene()
{
}

void BossScene::Update(float deltaTime)
{
    for (int i = 31; i >= 1; i--)
    {
        prevPos[i] = prevPos[i - 1];
    }
    prevPos[0] = pos;
    rad += 1.0f * deltaTime;
    if (rad >= 2.0f)
    {
        rad = 0.0f;
    }
    if (pos.z >= 200)
    {
        pos.z -= 15.0f * deltaTime;
    }
    pos.x += xSpeed;
    pos.y += ySpeed;
    if (pos.x > 20.0f)
    {
        pos.x = 20.0f;
        xSpeed *= -1;
    }
    if (pos.x < -20.0f)
    {
        pos.x = -20.0f;
        xSpeed *= -1;
    }
    if (pos.y > 20.0f)
    {
        pos.y = 20.0f;
        ySpeed *= -1;
    }
    if (pos.y < -20.0f)
    {
        pos.y = -20.0f;
        ySpeed *= -1;
    }

    line1Start = VGet(pos.x + mainR * sinf(0.25f * DX_PI_F) * cosf(rad * DX_PI_F), pos.y + mainR * cos(0.25f * DX_PI_F), pos.z + mainR * sinf(0.25f * DX_PI_F) * sinf(rad * DX_PI_F));
    line1End = VGet(pos.x - mainR * sinf(0.25f * DX_PI_F) * cosf(rad * DX_PI_F), pos.y - mainR * cos(0.25f * DX_PI_F), pos.z - mainR * sinf(0.25f * DX_PI_F) * sinf(rad * DX_PI_F));
    line2Start = VGet(pos.x - mainR * sinf(0.25f * DX_PI_F) * cosf((rad + 1.0f) * DX_PI_F), pos.y - mainR * cos(0.25f * DX_PI_F), pos.z - mainR * sinf(0.25f * DX_PI_F) * sinf((rad + 1.0f) * DX_PI_F));
    line2End = VGet(pos.x + mainR * sinf(0.25f * DX_PI_F) * cosf((rad + 1.0f) * DX_PI_F), pos.y + mainR * cos(0.25f * DX_PI_F), pos.z + mainR * sinf(0.25f * DX_PI_F) * sinf((rad + 1.0f) * DX_PI_F));

    ColorChanger();

    if (HP <= 0.0f)
    {
        deadFlag = true;
    }
}

void BossScene::Draw()
{
    for (int i = 0; i < 32; i++)
    {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64 - 2 * i);
        DrawSphere3D(prevPos[i], mainR*((float)(32-(i/2))/32.0f), 16, Color, Color, true);
    }
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
    DrawSphere3D(pos, mainR, 16, Color, Color, true);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
    DrawSphere3D(pos, coreR, 16, Color, Color, true);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
    DrawLine3D(line1Start, line1End, Color);
    DrawLine3D(line2Start, line2End, Color);
    DrawLine3D(pos, VGet(pos.x, -20.0f, pos.z), Color);
}

void BossScene::ColorChanger()
{
    redColorValue = 255 * (1 - (HP / 2.0f));
    Color = GetColor(redColorValue, 255 - redColorValue, 0);
}
