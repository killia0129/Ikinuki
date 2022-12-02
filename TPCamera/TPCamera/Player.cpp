#include "Player.h"
#include"game.h"

Player::Player()
{
	pos = VGet(0, 0, 30);
	HP = 10;
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	int keyInput = input.Input();
	switch (keyInput)
	{
	case DIR::AHEAD:
		pos.y += playerSpeed;
		break;

	case DIR::BACK:
		pos.y -= playerSpeed;
		break;

	case DIR::LEFT:
		pos.x -= playerSpeed;
		break;

	case DIR::RIGHT:
		pos.x += playerSpeed;
		break;

	default:
		break;
	}
	if (pos.x < (stageWidth / 2) * (-1)+ playerR)
	{
		pos.x = (stageWidth / 2) * (-1) + playerR;
	}
	if (pos.x > (stageWidth / 2) - playerR)
	{
		pos.x = (stageWidth / 2) - playerR;
	}
	if (pos.y < (stageWidth / 2) * (-1) + playerR)
	{
		pos.y = (stageWidth / 2) * (-1) + playerR;
	}
	if (pos.y > (stageWidth / 2) - playerR)
	{
		pos.y = (stageWidth / 2) - playerR;
	}

}

void Player::HPGetter()
{
}

VECTOR Player::posGetter()
{
	return pos;
}

void Player::Draw()
{
	VECTOR pos1, pos2;
	pos1 = pos;
	pos2 = pos;
	pos1.z += playerSize / 2.0f;
	pos2.z -= playerSize / 2.0f;
	//DrawCapsule3D(pos1, pos2, playerR, 16, GetColor(42, 255, 255), GetColor(42, 255, 255), true);
	DrawCapsule3D(pos1, pos2, playerR, 4, GetColor(42, 255, 255), GetColor(42, 255, 255), false);
}
