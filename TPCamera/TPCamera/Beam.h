#pragma once
#include<DxLib.h>
class Beam
{
public:
    Beam(VECTOR _pos);
    virtual ~Beam();
    void Update(float deltaTime);
    void Draw();

private:
    VECTOR pos;
    int screenX;
    int screenY;
    int phase;

};

