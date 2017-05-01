#pragma once //<ck:del>

#include "Object.h"
#include "PlayerDecision.h"
#include "macros.h"

template <typename PlayerDecisionType, int depth>
class AlgorithmResult : Object {
public:
    AlgorithmResult(){};
    AlgorithmResult(PlayerDecisionType player_decisions[], int it) :
        number_of_iterations(it) {
        COPY_ARRAY(m_player_decisions, player_decisions);
    }

    PlayerDecisionType m_player_decisions[depth];
    int number_of_iterations;
};

