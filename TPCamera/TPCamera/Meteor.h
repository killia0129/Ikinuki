#pragma once
#include <DxLib.h>
#include"ObstructBase.h"
class Meteor :
    public ObstructBase
{
public:
    Meteor(VECTOR _pos);
    virtual ~Meteor();
    void Draw();
    void Update(float deltaTime);

private:
    float rad;
    float yaw;
    float ang;
};

