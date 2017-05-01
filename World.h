#pragma once //<ck:del>

#include "Object.h"
#include "TurnDecision.h"

class World : Object {
public:
    World();
    virtual float eval()=0;
    virtual void applyDecision(const TurnDecision&)=0;
};


