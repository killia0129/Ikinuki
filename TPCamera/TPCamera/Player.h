#pragma once
#include<DxLib.h>
#include "Object.h"
#include"Move.h"
#include"InputMove.h"
class Player :
    public Object
{
public:
    void Update(float deltaTime);
    void HPGetter();
    VECTOR posGetter();

private:
    int HP;
    Move move;
    InputMove input;
};

