#pragma once
#include<vector>
#include"MapCell.h"
class MapManager
{
public:
    MapManager();
    virtual ~MapManager();
    void DrawAll();

private:
    std::vector<MapCell*> mapCell;
};

