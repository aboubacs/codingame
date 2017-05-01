#pragma once //<ck:del>

#include "Object.h"
#include "World.h"
#include "AlgorithmResult.h"
#include "DecisionGenerator.h"
#include "Time.h"

class Algorithm : Object {
public:
    Algorithm();
    virtual AlgorithmResult run(const World& world, double allowed_time, int player_id)=0;
    void set_decision_generator(DecisionGenerator* generator);
protected:
    DecisionGenerator* m_generator;
    Time m_time_control;
};


