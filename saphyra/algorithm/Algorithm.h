#pragma once //<ck:del>

#include <vector>

#include "../util/Object.h"
#include "AlgorithmResult.h"
#include "decision/DecisionGenerator.h"
#include "../util/Time.h"
#include "decision/TurnDecision.h"

template<typename WorldType, typename PlayerDecisionType, int nb_players, int depth>
class Algorithm : Object {
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

    void set_decision_generator(
        DecisionGenerator<
            WorldType,
            PlayerDecisionType
        >* generator) {
        ASSERT(generator != nullptr);
        m_generator = generator;
    }

protected:
    DecisionGenerator<WorldType, PlayerDecisionType>* m_generator;
    Time m_time_control;
};


