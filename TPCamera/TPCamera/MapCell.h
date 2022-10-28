#pragma once
#include<DxLib.h>
#include "Object.h"
class MapCell :
    public Object
{
public:
    MapCell(VECTOR pos);
    virtual ~MapCell();
    void Draw();
private:
    int color;
};

