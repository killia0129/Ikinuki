#pragma once
#include<vector>
#include"ObstructBase.h"
#include"Meteor.h"

class ObstructManager
{
public:
    static void Update(float delataTime);
    static void Add(ObstructBase* newObs);
    static void Clear();
    static void Remove(ObstructBase* dltObs);
    static void Draw();
    static void Finalize();
    static void Init();

private:
    ObstructManager();
    virtual ~ObstructManager();
    static ObstructManager* instance;
    std::vector<ObstructBase*> obsBuff;
    std::vector<ObstructBase*> obstructs;
    static float obstractCD;

    VECTOR cell[4][4];
};

