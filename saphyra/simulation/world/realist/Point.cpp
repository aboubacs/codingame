#include <cmath>

#include "Point.h"
#include "../../../util/macros.h"

Point::Point() {}
Point::Point(float _x, float _y) : x(_x), y(_y) {}

float Point::distance2(const Point& p) const {
    return POW2(x-p.x) + POW2(y-p.y);
}
float Point::distance2(float _x, float _y) const {
    return POW2(x-_x) + POW2(y-_y);
}
float Point::distance(const Point& p) const {
    return sqrt(POW2(x-p.x) + POW2(y-p.y));
}
float Point::distance(float _x, float _y) const {
    return sqrt(POW2(x-_x) + POW2(y-_y));
}
Point Point::closest(const Point& a, const Point& b) const {
    float da = b.y - a.y;
    float db = a.x - b.x;
    float c1 = da*a.x + db*a.y;
    float c2 = -db*x + da*y;
    float det = POW2(da) + POW2(db);
    if (det != 0) {
        return Point((da*c1 - db*c2) / det, (da*c2 + db*c1) / det);
    } else {
        return Point(x, y);
    }

}