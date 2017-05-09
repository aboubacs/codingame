#pragma once

#include "Object.h"

class Point : public Object {
public:
    float x;
    float y;

    Point();
    Point(float _x, float _y);
    float distance2(const Point& p) const;
    float distance2(float _x, float _y) const;
    float distance(const Point& p) const;
    float distance(float _x, float _y) const;
    Point closest(const Point& a, const Point& b) const;
};


