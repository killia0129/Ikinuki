#pragma once
#include<DxLib.h>
#include"game.h"
class Particle
{
public:
    Particle(VECTOR _pos);
    virtual ~Particle();
    void Update(float deltaTime,VECTOR _pos);
    void Draw();
    bool isEnd() { return endFlag; }

private:
    float rad;
    float count;
    bool endFlag;
    float xPower;
    float yPower;
    VECTOR pos;
};

