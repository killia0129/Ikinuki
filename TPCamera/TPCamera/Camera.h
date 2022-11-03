#pragma once
#include<DxLib.h>
#include"Object.h"
class Camera:public Object
{
public:
    Camera();
    virtual ~Camera();
private:
    VECTOR pos;
    float ang;
    float yaw;
};

