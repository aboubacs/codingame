#pragm once

#include "Point.h"
#include "Object.h"

class Unit {
public:
    Point p;
    float r;
    float vx;
    float vy;

    Point save_p;
    float save_r;
    float save_vx;
    float save_vy;

    Unit();
    Unit(float _x, float _y, float _r, float _vx, float _vy);
    float collision_time(const Unit& unit);

    void save();
    void rollback();
};
