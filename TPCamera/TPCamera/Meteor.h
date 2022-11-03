#pragma once
#include"ObstructBase.h"
class Meteor :
    public ObstructBase
{
public:
    Meteor();
    virtual ~Meteor();
    void Draw();
    void Update(float deltaTime);

private:
    float rad;
    float yaw;
    float ang;
};

