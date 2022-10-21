#pragma once
#include<DxLib.h>
class Object
{
public:
    void Draw();
    virtual void Update(float deltaTime) = 0;

protected:
    VECTOR pos;
    int objectName;
    int modelHandle;
};

