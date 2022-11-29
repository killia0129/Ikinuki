#include "Player.h"
#include"game.h"

void Player::Update(float deltaTime)
{
	int keyInput = input.Input();
	switch (keyInput)
	{
	case DIR::AHEAD:
		pos.y += 0.5f;
		break;

	case DIR::BACK:
		pos.y -= 0.5f;
		break;
	}
}

void Player::HPGetter()
{
}

VECTOR Player::posGetter()
{
	return VECTOR();
}

void Player::Draw()
{
}
