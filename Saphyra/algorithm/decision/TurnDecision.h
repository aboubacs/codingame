#pragma once //<ck:del>

#include "../../util/Object.h"
#include "../../util/my_assert.h"

template<typename PlayerDecisionType, int nb_players>
class TurnDecision : Object {
public:
    TurnDecision(){};
    PlayerDecisionType m_player_decisions[nb_players];

    void update(const PlayerDecisionType& decision, int player) {
        ASSERT(player < nb_players);
        ASSERT(player >= 0);
        m_player_decisions[player] = decision;
    }
};
