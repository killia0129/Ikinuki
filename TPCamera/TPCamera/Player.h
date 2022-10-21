#pragma once
#include<DxLib.h>
#include "Object.h"
class Player :
    public Object
{
public:
    void Update(float deltaTime);
    void HPGetter();
    VECTOR posGetter();

private:
    int HP;
};

