#include "BoundedFloatMutationPolicy.h"
#include "../../../util/Rand.h"
#include "../../../util/macros.h"

BoundedFloatMutationPolicy::BoundedFloatMutationPolicy() :
    AbstractMutationPolicy(){}

float BoundedFloatMutationPolicy::mutate(float value, float range) {
    float res = Rand::Double(value-range,value+range);
    if (res < 0) return 0.f;
    if (res > 1) return 1.f;
    return res;
}