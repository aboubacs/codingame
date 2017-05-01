#pragma once

#include <limits>

#include "BasicMonteCarlo.h"
#include "../../simulation/data_structures/CycleArray.h"
#include "../../util/macros.h"

template<
    typename WorldType,
    typename PlayerDecisionType,
    int nb_players,
    int depth,
    int nb_retry
>
class MemoryMonteCarlo :
    BasicMonteCarlo<
        WorldType,
        PlayerDecisionType,
        nb_players,
        depth
    > {
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
    static_assert(
        nb_retry >= 0,
        "Number of retries for memorized solutions should be positive"
    );
public:
    MemoryMonteCarlo() :
        BasicMonteCarlo<WorldType, PlayerDecisionType, nb_players, depth>(),
        m_turn(0) {}
    AlgorithmResult<PlayerDecisionType, depth> run(
        const WorldType& world,
        double allowed_time,
        int player,
        vector<TurnDecision<PlayerDecisionType, nb_players>> context
    ) {
        ASSERT(m_turn >= 0);
        m_turn++;
        this->m_time_control.set_checkpoint();
        float best_eval_memorized = - numeric_limits<float>::infinity();
        PlayerDecisionType best_memory_decisions[depth];
        loop(i, MAX(depth,m_turn-1)) {
            auto decisions = m_memorized.get(i);
            memmove(
                decisions,
                decisions+1,
                sizeof(PlayerDecisionType)*(depth-1)
            );
            loop(j, nb_retry) {
                WorldType world_copy(world);
                loop(k, depth) {
                    if (k == depth-1) {
                        decisions[k] = this->m_generator->generate_random(
                            world_copy,
                            player
                        );
                    }
                    context[k].update(decisions[k], player);
                    world_copy.apply_decision(context[k]);
                }

                float eval = world_copy.eval();
                if (eval > best_eval_memorized) {
                    best_eval_memorized = eval;
                    COPY_ARRAY(best_memory_decisions, decisions);
                }
            }
        }
        auto result = BasicMonteCarlo<
            WorldType,
            PlayerDecisionType,
            nb_players,
            depth
        >::run(
            world,
            this->m_time_control.get_time_left(allowed_time) - 0.001,
            player,
            context
        );
        if (best_eval_memorized > result.m_best_eval) {
            cerr << "Memorized solution is better !" << endl;
            result.m_best_eval = best_eval_memorized;
            COPY_ARRAY(
                result.m_player_decisions,
                best_memory_decisions
            );
        }
        result.m_number_of_iterations +=
            nb_retry * (
                MAX(
                    depth,
                    m_turn-1
                )
            );
        m_memorized.set_and_turn(result.m_player_decisions);
        return result;
    };
protected:
    CycleArray<PlayerDecisionType[depth], depth> m_memorized;
    int m_turn;
};
