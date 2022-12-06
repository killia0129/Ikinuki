#include "Particle.h"

Particle::Particle(VECTOR _pos)
{
	pos = _pos;
	rad = particleR;
	count = 0.0f;
	endFlag = false;
	xPower = -0.5f + ((float)(rand() % 20) / 20.0f);
	yPower = -0.25f + ((float)(rand() % 20) / 40.0f);
}

Particle::~Particle()
{
}

void Particle::Update(float deltaTime,VECTOR _pos)
{
	rad = ((particleSec - count) / particleSec) * particleR;
	yPower -= g * deltaTime;
	pos.x += xPower;
	pos.y += yPower;
	pos.z -= obsSpeed*deltaTime;
	count += deltaTime;
	if (count > particleSec)
	{
		endFlag = true;
	}
}

void Particle::Draw()
{
	DrawSphere3D(pos, rad, 8, GetColor(255, 0, 0), GetColor(255, 0, 0), false);
}