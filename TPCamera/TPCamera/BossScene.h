#pragma once
#include<math.h>
#include<DxLib.h>
#include"Stage.h"
#include"Beam.h"
#include"ObstructBase.h"
class BossScene:public ObstructBase
{
public:
    BossScene(VECTOR pos);
    virtual ~BossScene();
    void Update(float deltaTime);
    void Draw();
    void GivenDmg(float deltaTime) { HP -= deltaTime; }

private:
    float mainR;
    float coreR;
    float HP;
    float rad;
    VECTOR line1Start, line1End;
    VECTOR line2Start, line2End;
};

