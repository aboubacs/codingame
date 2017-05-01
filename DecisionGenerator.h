#pragma once //<ck:del>

#include "Object.h"
#include "PlayerDecision.h"
#include "World.h"

template <typename PlayerDecisionType, int nb_players>
class DecisionGenerator : Object {
    static_assert(
        is_base_of<PlayerDecision, PlayerDecisionType>::value,
        "PlayerDecisionType must inherit from PlayerDecision"
    );
public:
    DecisionGenerator() {}
    virtual PlayerDecisionType generate_random(
        const World<PlayerDecisionType, nb_players>& world,
        int player=0
    )=0;
};


