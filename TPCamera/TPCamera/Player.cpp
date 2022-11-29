#include "Player.h"
#include"game.h"

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

}

void Player::HPGetter()
{
}

VECTOR Player::posGetter()
{
	return VECTOR();
}
//1965

void Player::Draw()
{
}
