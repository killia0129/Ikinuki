#include<math.h>
#include "Aim.h"
#include"game.h"

Aim::Aim()
{
	SetMousePoint(1920 / 2, 1080 / 2);
	nearSquare = VGet(0, 0, 80);
	farSquare = VGet(0, 0, 140);
	playerPos = VGet(0, 0, 30);
	lineLast = VGet(0, 0, 530);
	for (int i = 0; i < 16; i++)
	{
		prevPlayerPos[i] = playerPos;
		prevLineLast[i] = lineLast;
	}
	mousePointX = 0;
	mousePointY = 0;
	/*GetMousePoint(&mousePointX, &mousePointY);
	GetMousePoint(&previousPointX, &previousPointY);*/
	aimMark = VGet(0, 0, 110);
	normalColor = GetColor(0, 255, 0);
	lockedColor = GetColor(255, 0, 0);
	color = normalColor;
}

Aim::~Aim()
{
}

void Aim::Update(float deltaTime, VECTOR pPos)
{
	for (int i = 15; i >= 1; i--)
	{
		prevPlayerPos[i] = prevPlayerPos[i - 1];
		prevLineLast[i] = prevLineLast[i - 1];
	}
	prevPlayerPos[0] = playerPos;
	prevLineLast[0] = lineLast;
	playerPos = pPos;
	GetMousePoint(&mousePointX, &mousePointY);
	//SetMousePoint(1920 / 2, 1080 / 2);
	if (mousePointX > 1920 / 2 + mouseBuffer)
	{
		aimMark.x += aimSpeed * deltaTime;
	}
	if (mousePointX < 1920 / 2 - mouseBuffer)
	{
		aimMark.x -= aimSpeed * deltaTime;
	}
	if (mousePointY > 1080 / 2 + mouseBuffer)
	{
		aimMark.y -= aimSpeed * deltaTime;
	}
	if (mousePointY < 1080 / 2 - mouseBuffer)
	{
		aimMark.y += aimSpeed * deltaTime;
	}

	XINPUT_STATE padInput;
	GetJoypadXInputState(DX_INPUT_KEY_PAD1, &padInput);
	

	aimMark.x += aimSpeed * deltaTime * ((float)padInput.ThumbRX / 32768.0f);
	aimMark.y += aimSpeed * deltaTime * ((float)padInput.ThumbRY / 32768.0f);

	playerPos.z += playerSize / 2.0f;

	nearSquare.x = (aimMark.x - playerPos.x) * nearMarkRatio + playerPos.x;
	nearSquare.y = (aimMark.y - playerPos.y) * nearMarkRatio + playerPos.y;
	farSquare.x = (aimMark.x - playerPos.x) * farMarkRatio + playerPos.x;
	farSquare.y = (aimMark.y - playerPos.y) * farMarkRatio + playerPos.y;
	lineLast.x = (aimMark.x - playerPos.x) * lastMarkRatio + playerPos.x; 
	lineLast.y = (aimMark.y - playerPos.y) * lastMarkRatio + playerPos.y;
	SetMousePoint(1920 / 2, 1080 / 2);
}

void Aim::Draw(bool lockFlag)
{
	if (lockFlag)
	{
		color = lockedColor;
	}
	else
	{
		color = normalColor;
	}
	DrawTriangle3D(VGet(nearSquare.x, nearSquare.y + aimR, nearSquare.z),
		VGet(nearSquare.x + aimR * sinf(2.0f * DX_PI_F / 3.0f), nearSquare.y + aimR * cosf(2.0f * DX_PI_F / 3.0f), nearSquare.z),
		VGet(nearSquare.x + aimR * sinf(4.0f * DX_PI_F / 3.0f), nearSquare.y + aimR * cosf(4.0f * DX_PI_F / 3.0f), nearSquare.z),
		color, false);
	DrawTriangle3D(VGet(farSquare.x, farSquare.y + aimR, farSquare.z),
		VGet(farSquare.x + aimR * sinf(2.0f * DX_PI_F / 3.0f), farSquare.y + aimR * cosf(2.0f * DX_PI_F / 3.0f), farSquare.z),
		VGet(farSquare.x + aimR * sinf(4.0f * DX_PI_F / 3.0f), farSquare.y + aimR * cosf(4.0f * DX_PI_F / 3.0f), farSquare.z),
		color, false);

	for (int i = 0; i < 16; i++)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128 - 8 * i);
		DrawCapsule3D(prevPlayerPos[i], prevLineLast[i], 0.5f, 4, GetColor(10, 10, 255), GetColor(10, 10, 255), true);
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	DrawCapsule3D(playerPos, lineLast, 0.5f, 4, GetColor(42, 255, 255), GetColor(42, 255, 255), true);
	DrawCapsule3D(playerPos, lineLast, 0.45f, 1, lockedColor,lockedColor, false);


	DrawSphere3D(aimMark, 1.0f, 16, lockedColor, lockedColor, true);
	DrawLine3D(aimMark, VGet(aimMark.x, -20.0f, aimMark.z), lockedColor);
	DrawLine3D( VGet(-20.0f, -20.0f, aimMark.z), VGet(20.0f, -20.0f, aimMark.z),lockedColor);
	DrawLine3D(VGet(-20.0f, aimMark.y, aimMark.z), VGet(20.0f, aimMark.y, aimMark.z), lockedColor);
	DrawLine3D(VGet(-20.0f, -20.0f, aimMark.z), VGet(-20.0f, 20.0f, aimMark.z), lockedColor);
	DrawLine3D(VGet(20.0f, -20.0f, aimMark.z), VGet(20.0f, 20.0f, aimMark.z), lockedColor);

	//DrawFormatString(10, 30, GetColor(255, 255, 255),"X:%d,Y=%d",mousePointX,mousePointY);
	//DrawFormatString(10, 50, GetColor(255, 255, 255), "pX:%f", playerPos.x);
}
