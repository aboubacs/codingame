#pragma once

#include "AbstractMutationPolicy.h"

class BoundedFloatMutationPolicy : public AbstractMutationPolicy {
public:
    BoundedFloatMutationPolicy();
    static float mutate(float value, float range);
};

