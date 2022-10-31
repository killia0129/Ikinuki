#pragma once
#include<vector>
#include"MapCell.h"
class MapManager
{
public:
    MapManager();
    virtual ~MapManager();
    void DrawAll();
    void Update(float deltaTime);
    void Generate();

private:
    std::vector<MapCell*> mapCell;
};

