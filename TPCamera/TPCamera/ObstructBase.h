#pragma once
#include "Object.h"
class ObstructBase :
    public Object
{
public:
    ObstructBase();
    virtual ~ObstructBase();

protected:
    enum TYPE;//������ŏ���
    int type;
};

