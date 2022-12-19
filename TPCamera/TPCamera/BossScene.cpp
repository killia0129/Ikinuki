#include "BossScene.h"

BossScene::BossScene(VECTOR pos)
{
    BossScene::pos = pos;
    mainR = 5.0f;
    coreR = 2.0f;
    HP = 20.0f;
    rad = 0.0f;
    line1Start = VGet(pos.x + mainR * sinf(0.5f * DX_PI_F) * cosf(rad * DX_PI_F), pos.y + mainR * cos(0.5f * DX_PI_F), pos.z + mainR * sinf(0.5f * DX_PI_F) * sinf(rad * DX_PI_F));
    line1End = VGet(pos.x - mainR * sinf(0.5f * DX_PI_F) * cosf(rad * DX_PI_F), pos.y - mainR * cos(0.5f * DX_PI_F), pos.z - mainR * sinf(0.5f * DX_PI_F) * sinf(rad * DX_PI_F));
    line2Start = VGet(pos.x + mainR * sinf(0.5f * DX_PI_F) * cosf((rad + 0.5f) * DX_PI_F), pos.y - mainR * cos(0.5f * DX_PI_F), pos.z + mainR * sinf(0.5f * DX_PI_F) * sinf((rad + 0.5f) * DX_PI_F));
    line2End = VGet(pos.x - mainR * sinf(0.5f * DX_PI_F) * cosf((rad + 0.5f) * DX_PI_F), pos.y + mainR * cos(0.5f * DX_PI_F), pos.z - mainR * sinf(0.5f * DX_PI_F) * sinf((rad + 0.5f) * DX_PI_F));
}

BossScene::~BossScene()
{
}

void BossScene::Update(float deltaTime)
{
    rad += 1.0f * deltaTime;
    if (rad >= 2.0f)
    {
        rad = 0.0f;
    }
    pos.z -= 20.0f * deltaTime;
    line1Start = VGet(pos.x + mainR * sinf(0.25f * DX_PI_F) * cosf(rad * DX_PI_F), pos.y + mainR * cos(0.25f * DX_PI_F), pos.z + mainR * sinf(0.25f * DX_PI_F) * sinf(rad * DX_PI_F));
    line1End = VGet(pos.x - mainR * sinf(0.25f * DX_PI_F) * cosf(rad * DX_PI_F), pos.y - mainR * cos(0.25f * DX_PI_F), pos.z - mainR * sinf(0.25f * DX_PI_F) * sinf(rad * DX_PI_F));
    line2Start = VGet(pos.x - mainR * sinf(0.25f * DX_PI_F) * cosf((rad + 1.0f) * DX_PI_F), pos.y - mainR * cos(0.25f * DX_PI_F), pos.z - mainR * sinf(0.25f * DX_PI_F) * sinf((rad + 1.0f) * DX_PI_F));
    line2End = VGet(pos.x + mainR * sinf(0.25f * DX_PI_F) * cosf((rad + 1.0f) * DX_PI_F), pos.y + mainR * cos(0.25f * DX_PI_F), pos.z + mainR * sinf(0.25f * DX_PI_F) * sinf((rad + 1.0f) * DX_PI_F));
}

void BossScene::Draw()
{
    DrawSphere3D(pos, coreR, 16, GetColor(0, 255, 0), GetColor(0, 255, 0), true);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 144);
    DrawSphere3D(pos, mainR, 16, GetColor(0, 255, 0), GetColor(0, 255, 0), true);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
    DrawLine3D(line1Start, line1End, GetColor(0, 255, 0));
    DrawLine3D(line2Start, line2End, GetColor(0, 255, 0));
}
