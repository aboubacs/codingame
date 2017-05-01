#pragma once //<ck:del>

#include <vector>

#include "Object.h"
#include "World.h"
#include "AlgorithmResult.h"
#include "DecisionGenerator.h"
#include "Time.h"
#include "TurnDecision.h"

template<typename WorldType, typename PlayerDecisionType, int nb_players, int depth>
class Algorithm : Object {
    static_assert(
        is_base_of<
            World<PlayerDecisionType, nb_players>,
            WorldType
        >::value,
        "WorldType must inherit from World"
    );
    static_assert(
        is_base_of<PlayerDecision, PlayerDecisionType>::value,
        "PlayerDecisionType must inherit from PlayerDecision"
    );
    static_assert(
        depth > 0,
        "Depth must be positive"
    );
    static_assert(
        nb_players >= 2,
        "Number of players should be at least 2"
    );
public:
    Algorithm():m_generator(nullptr){}

    virtual AlgorithmResult<PlayerDecisionType, depth> run(
        const WorldType& world,
        double allowed_time,
        int player_id,
        vector<TurnDecision<PlayerDecisionType, nb_players>> context)=0;

    void set_decision_generator(DecisionGenerator<PlayerDecisionType, nb_players>* generator) {
        ASSERT(generator != nullptr);
        m_generator = generator;
    }

protected:
    DecisionGenerator<PlayerDecisionType, nb_players>* m_generator;
    Time m_time_control;
};


