#pragma once //<ck:del>

#include "Object.h"
#include "PlayerDecision.h"
#include "macros.h"

template <typename PlayerDecisionType, int depth>
class AlgorithmResult : Object {
public:
    AlgorithmResult(){};
    AlgorithmResult(PlayerDecisionType player_decisions[], int it) :
        m_number_of_iterations(it) {
        COPY_ARRAY(m_player_decisions, player_decisions);
        ASSERT(m_number_of_iterations > 0);
    }

    PlayerDecisionType m_player_decisions[depth];
    int m_number_of_iterations;
};

