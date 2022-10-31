#include "Camera.h"

Camera::Camera()
{
    pos = VGet(0.0f, -30.0f, -30.0f);
    rad = 0.0f;
    yaw = -0.25f;
}

Camera::~Camera()
{
}
