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
	XINPUT_STATE padInput;
	GetJoypadXInputState(DX_INPUT_KEY_PAD1, &padInput);
	if (padInput.ThumbLX < 0)
	{
		if (padInput.ThumbLX < -16383)
		{
			pos.x -= playerSpeed;
		}
		else
		{
			pos.x -= playerSpeed / 2;
		}
	}
	if (padInput.ThumbLX > 0)
	{
		if (padInput.ThumbLX > 16383)
		{
			pos.x += playerSpeed;
		}
		else
		{
			pos.x += playerSpeed / 2;
		}
	}
	if (padInput.ThumbLY < 0)
	{
		if (padInput.ThumbLY < -16383)
		{
			pos.y -= playerSpeed;
		}
		else
		{
			pos.y -= playerSpeed / 2;
		}
	}
	if (padInput.ThumbLY > 0)
	{
		if (padInput.ThumbLY > 16383)
		{
			pos.y += playerSpeed;
		}
		else
		{
			pos.y += playerSpeed / 2;
		}
	}

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
	return Player::pos;
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
