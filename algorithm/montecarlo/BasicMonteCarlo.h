#pragma once //<ck:del>

#include <vector>
#include <type_traits>

#include "../../Algorithm.h"
#include "../../AlgorithmResult.h"
#include "../TurnDecision.h"
#include "../../../util/my_assert.h"
#include "../../../util/macros.h"

template<typename WorldType, typename PlayerDecisionType, int nb_players, int depth>
class MonteCarlo : Algorithm<WorldType, PlayerDecisionType, nb_players, depth> {
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
    MonteCarlo(){}
    AlgorithmResult<PlayerDecisionType, depth> run(
        const WorldType& world,
        double allowed_time,
        int player,
        vector<TurnDecision<PlayerDecisionType, nb_players>> context
    ) {
        ASSERT(this->m_generator != NULL);
        ASSERT(depth > 0);
        ASSERT(depth == context.size());

        PlayerDecisionType best_decisions[depth];
        this->m_time_control.set_checkpoint();
        float best_eval = - numeric_limits<float>::infinity();
        int counter = 0;
        while (!this->m_time_control.is_elapsed(allowed_time)) {
            WorldType world_copy(world);
            counter++;
            PlayerDecisionType decisions[depth];
            loop(i, depth) {
                decisions[i] = this->m_generator->generate_random(world_copy, player);
                context[i].update(decisions[i], player);
                world_copy.applyDecision(context[i]);
            }
            float eval = world_copy.eval(player);
            if (eval > best_eval) {
                best_eval = eval;
                COPY_ARRAY(best_decisions, decisions);
            }
        }
        ASSERT(counter > 0);
        ASSERT(best_eval != - numeric_limits<float>::infinity());
        return AlgorithmResult<PlayerDecisionType, depth>(best_decisions, counter);
    };

protected:
};
