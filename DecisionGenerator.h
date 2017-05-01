#pragma once //<ck:del>

#include "Object.h"
#include "PlayerDecision.h"
#include "World.h"

class DecisionGenerator : Object {
public:
    DecisionGenerator();
    virtual PlayerDecision* generate_random(const World& world, int player=0)=0;
};


