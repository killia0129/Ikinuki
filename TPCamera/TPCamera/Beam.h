#pragma once
#include<DxLib.h>
class Beam
{
public:
    Beam(int laneNum);
    virtual ~Beam();
    void Update(float deltaTime);
    void Draw();
    void Start();

private:
    VECTOR pos;
    int phase;
    int count;

    enum PHASENAME
    {
        READY,ANNOUNCE,ONFIRE,COOLDOWN
    };
};

