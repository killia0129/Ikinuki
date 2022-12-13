#include "Beam.h"

Beam::Beam(int laneNum)
{
    pos = VGet(-15.0f + 10.0 * (float)laneNum, 25.0f, 10.0f);
    phase = READY;
    count = 0;
}

Beam::~Beam()
{
}

void Beam::Update(float deltaTime)
{
}


void Beam::Draw()
{
}

void Beam::Start()
{
}
