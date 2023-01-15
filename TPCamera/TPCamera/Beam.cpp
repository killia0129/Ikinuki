#include "Beam.h"
#include"game.h"

Beam::Beam(int laneNum)
{
    pos = VGet(-15.0f + 10.0 * (float)laneNum, 25.0f, 25.0f);
    beamLast = pos;
    phase = READY;
    count = 0.0f;
    lane = laneNum;
    blinkController = 0.0f;
    blinkFlag = true;
    beamR = 5.0f;
    hitFlag = false;
}

Beam::~Beam()
{
}

void Beam::Update(float deltaTime)
{
    if (phase != READY)
    {
        count += deltaTime;
    }
    if (phase == ANNOUNCE)
    {
        blinkController += deltaTime;
        if (blinkController <= 0.3f)
        {
            blinkFlag = true;
        }
        else if(blinkController<=0.45)
        {
            blinkFlag = false;
        }
        else
        {
            blinkController = 0.0f;
        }
        if (count >= 2.0f)
        {
            phase = ONFIRE;
        }
    }
    if (phase == ONFIRE)
    {
        beamLast = VGet(beamLast.x, beamLast.y - (1000.0f * deltaTime), beamLast.z);
        if (count >= 4.0)
        {
            phase = COOLDOWN;
        }
    }
    if (phase == COOLDOWN)
    {
        beamR -= 100.0f * deltaTime;
        if (beamR <= 0.0f)
        {
            phase = READY;
        }
    }
}


void Beam::Draw()
{
    if (phase != READY)
    {
        switch (phase)
        {
        case ANNOUNCE:
            if (blinkFlag)
            {
                DrawLine(lane * 480, 0,lane* 480, 1080, GetColor(255, 0, 0), 3);
                DrawLine((lane+1) * 480, 0, (lane+1) * 480, 1080, GetColor(255, 0, 0), 3);
                SetFontSize(100);
                DrawString(10 + lane * 480, 530, "!!!!!!", GetColor(255, 0, 0));
            }
            break;

        case ONFIRE:
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 169);
            DrawCapsule3D(pos, beamLast, beamR, 8, GetColor(255, 0, 0), GetColor(255, 0, 0), true);
            DrawCapsule3D(pos, beamLast, beamR, 4, GetColor(42, 255, 255), GetColor(42, 255, 255), false);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
            break;

        case COOLDOWN:
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 169);
            DrawCapsule3D(pos, beamLast, beamR, 8, GetColor(255, 0, 0), GetColor(255, 0, 0), true);
            DrawCapsule3D(pos, beamLast, beamR, 4, GetColor(42, 255, 255), GetColor(42, 255, 255), false);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
            break;

        default:
            break;
        }
    }
}

void Beam::Start()
{
    phase = ANNOUNCE;
    count = 0.0f;
    blinkController = 0.0f;
    beamLast = pos;
    beamR = 5.0f;
    hitFlag = false;
}

bool Beam::HitCheck(VECTOR pPos)
{
    if (!hitFlag)
    {
        if (phase == ONFIRE)
        {
            if (pPos.x >= -20.0f + (10.0f * lane) - playerR && pPos.x <= -20.0f + (10.0f * (lane + 1)) + playerR)
            {
                hitFlag = true;
                return true;
            }
        }
    }
    return false;
}

