#pragma once

enum DIR
{
    AHEAD,BACK,LEFT,RIGHT,NEUTRAL
};

const float turnSpeed = 0.25f;
const float waveSpeed = 0.03f;
const float obsSpeed = 10.0f;
const float stageLength = 500.0f;
const float stageWidth = 40.0f;
const float playerSpeed = 0.5f;
const float playerSize = 6.0f;
const float playerR = 1.5f;
const float aimR = 5.0f;
const int aimSpeed = 15.0f;
const int mouseBuffer = 5;