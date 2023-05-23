#pragma once
#include "Element.h"
class Block :
    public Element {

private:
    bool bCanBeDestroyed;

public:
    Block();

    void SetDestroy(bool);
    bool BlockHitCheck(Coordinate, Size);
    bool GetDestroy() { return bCanBeDestroyed; }
};

