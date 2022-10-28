#include "Move.h"

VECTOR Move::MovePos(VECTOR pos, float speed, float rad)
{
    return VGet(pos.x + speed * cos(rad * DX_PI), pos.y, pos.z + speed * sin(rad * DX_PI));
}
