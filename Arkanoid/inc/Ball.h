#pragma once
#include "Element.h"
#include<cmath>
#include <stdlib.h>
#include <cstring>

class Ball :
    public Element {

private:
    Coordinate upper_left_border, lower_right_border;
    Coordinate currentSpeed, defaultSpeed;
    bool bIsDropped;
    bool bIsMove;
    unsigned int tick;
    float angle_direction;

public:
    Ball();
    void SetDefaultSettings();
    void SetBorder(float left, float right, float top, float bottom);
    void SetDirectionMove(int x, int y);
    void SetMove(bool bIsBallMove);
    void ChangeDirection(Coordinate c_block, Size s_block, unsigned int tick);
    void Move(Coordinate coordinatePlatform, Size sizePlatform);

   
    bool IsMove() const { return bIsMove; }
    bool IsDropped() { return bIsDropped; }
};

