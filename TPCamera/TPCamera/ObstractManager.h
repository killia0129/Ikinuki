#pragma once
#include<vector>
#include"ObstructBase.h"
#include"Meteor.h"
class ObstractManager
{
public:
    ObstractManager();
    virtual ~ObstractManager();
    void Update(float delataTime);
    void Clear();
    void Remove();

private:
    std::vector<ObstructBase*> ObsBuff;
};

