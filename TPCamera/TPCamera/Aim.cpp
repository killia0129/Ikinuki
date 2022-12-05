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
	DrawCapsule3D(playerPos, lineLast, 0.5f, 4, GetColor(42, 255, 255), GetColor(42, 255, 255), true);
	DrawCapsule3D(playerPos, lineLast, 0.6f, 4, lockedColor,lockedColor, false);
	DrawSphere3D(aimMark, 1.0f, 16, lockedColor, lockedColor, true);
	DrawLine3D(aimMark, VGet(aimMark.x, -20.0f, aimMark.z), lockedColor);
	DrawLine3D( VGet(-20.0f, -20.0f, aimMark.z), VGet(20.0f, -20.0f, aimMark.z),lockedColor);
	DrawLine3D(VGet(-20.0f, aimMark.y, aimMark.z), VGet(20.0f, aimMark.y, aimMark.z), lockedColor);
	DrawLine3D(VGet(-20.0f, -20.0f, aimMark.z), VGet(-20.0f, 20.0f, aimMark.z), lockedColor);
	DrawLine3D(VGet(20.0f, -20.0f, aimMark.z), VGet(20.0f, 20.0f, aimMark.z), lockedColor);

	//DrawFormatString(10, 30, GetColor(255, 255, 255),"X:%d,Y=%d",mousePointX,mousePointY);
	//DrawFormatString(10, 50, GetColor(255, 255, 255), "pX:%f", playerPos.x);
}
