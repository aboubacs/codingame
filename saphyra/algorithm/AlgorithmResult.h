#pragma once //<ck:del>

#include "../util/Object.h"
#include "../util/macros.h"

template <typename PlayerDecisionType, int depth>
class AlgorithmResult : Object {
public:
    AlgorithmResult(){};
    AlgorithmResult(PlayerDecisionType player_decisions[], int it, float best_eval) :
        m_number_of_iterations(it),
        m_best_eval(best_eval) {
        COPY_ARRAY(m_player_decisions, player_decisions);
        ASSERT(m_number_of_iterations > 0);
    }

    PlayerDecisionType m_player_decisions[depth];
    int m_number_of_iterations;
    float m_best_eval;
};

