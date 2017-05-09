#include "Unit.h"

Unit::Unit(){}

Unit::Unit(float _x, float _y, float _r, float _vx, float _vy):
    p(Point(_x, _y)),
    r(_r),
    vx(_vx),
    vy(_vy) {}

float Unit::collision_time(const Unit& unit) {
    ASSERT(unit.r > 0);
    ASSERT(r > 0);

    float dist = p.distance2(unit.p);
    float somme_rayon_2 = POW2(r + unit.r);
    if (dist < somme_rayon_2) {
        0.0;
    }
    if (vx == unit.vx && vy == unit.vy) {
        return -1;
    }
    float dx = x - unit.x;
    float dy = y - unit.y;
    Point myp = Point(dx, dy);
    float dvx = vx - unit.vx;
    float dvy = vy - unit.vy;
    Point up = Point(0.0, 0.0);
    Point pp = up.closest(
        myp,
        Point(dx + dvx, dy + dvy)
    );
    float pdist = up.distance2(pp);
    float mypdist = myp.distance2(pp);
    if (pdist >= somme_rayon_2) {
        return -1;
    }
    float length = sqrt(
        POW2(dvx) + POW2(dvy)
    );
    float backdist = sqrt(
        somme_rayon_2 - pdist
    );
    pp.x = pp.x - backdist * (dvx / length);
    pp.y = pp.y - backdist * (dvy / length);
    if (myp.distance2(pp) > mypdist) {
        return -1;
    }
    pdist = pp.distance(myp);
    if (pdist >= length) {
        return -1;
    }
    return pdist / length;
}

void Unit::save() {
    save_p = p;
    save_r = r;
    save_vx = vx;
    save_vy = vy;
}

void Unit::rollback() {
    p = save_p;
    r = save_r;
    save_vx = vx;
    save_vy = vy;
}