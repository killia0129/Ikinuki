#include "MapCell.h"

MapCell::MapCell(VECTOR pos)
{
    modelHandle = MV1LoadModel("Models/Roof/cube.mv1");
}

MapCell::~MapCell()
{
}

void MapCell::Draw()
{
    MV1DrawModel(modelHandle);
}
