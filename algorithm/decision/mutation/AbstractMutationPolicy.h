#pragma once

class AbstractMutationPolicy {
public:
    AbstractMutationPolicy();
    virtual static float mutate(float value, float range)=0;
};


