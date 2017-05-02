#pragma once

#include "AbstractMutationPolicy.h"

class EquiprobableFloatMutationPolicy : public AbstractMutationPolicy {
public:
    EquiprobableFloatMutationPolicy();
    static float mutate(float value, float range);
};

