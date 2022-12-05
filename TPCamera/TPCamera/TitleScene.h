#pragma once
#include<vector>
#include"Stage.h"
#include"Needle.h"
#include"Meteor.h"
class TitleScene
{
public:
    TitleScene();
    virtual ~TitleScene();
    float ALL();

private:
    Stage* stage = new Stage;
    std::vector<ObstructBase*>obstructs;
    int nowTime;
    int previousTime;
    float deltaTime;
    float obsCool;
    int seed;
    void Entry();
    void ObsDelete(ObstructBase* deleteObs);
    VECTOR cell[4][4];
};

