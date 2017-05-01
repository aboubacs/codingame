#pragma once //<ck:del>

#include "Object.h"
#include "TurnDecision.h"

template<typename PlayerDecisionType, int nb_players>
class World : Object {
public:
    World(){};
    virtual float eval(int player)=0;
    virtual void applyDecision(const TurnDecision<PlayerDecisionType, nb_players>&)=0;
};


