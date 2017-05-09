#pragma once

#include "../../../../util/Rand.h"

namespace FloatMutation {

    float equiprobable(float value, float range) {
        return Rand::Float(MIN(0,value-range),MAX(1,value+range));
    }

    // Bad ?
    float bounded(float value, float range) {
        float res = Rand::Float(value-range,value+range);
        if (res < 0) return 0.f;
        if (res > 1) return 1.f;
        return res;
    }

    float equidirectional(float value, float range) {
        if (Rand::Int(0,1) == 1) {
            return Rand::Float(MIN(0,value-range), value);
        } else {
            return Rand::Float(value, MAX(1,value+range));
        }
    }
}