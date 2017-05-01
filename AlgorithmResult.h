#pragma once //<ck:del>

#include "Object.h"
#include "PlayerDecision.h"

class AlgorithmResult : Object {
public:
    AlgorithmResult();

    PlayerDecision m_player_decision[];
};

