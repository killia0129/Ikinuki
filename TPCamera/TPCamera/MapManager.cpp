#include "MapManager.h"

MapManager::MapManager()
{
}

MapManager::~MapManager()
{
}

void MapManager::DrawAll()
{
    for (auto cube : mapCell)
    {
        cube->Draw();
    }
}

void MapManager::Generate()
{

}
