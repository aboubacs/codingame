#pragma once //<ck:del>

#include "../../util/Object.h"

template <typename WorldType, typename PlayerDecisionType>
class DecisionGenerator : Object {
public:
    DecisionGenerator() {}
    virtual PlayerDecisionType generate_random(
        const WorldType& world,
        int player=0
    )=0;
};


