#pragma once //<ck:del>

#include "Algorithm.h"
#include "AlgorithmResult.h"

class MonteCarlo : Algorithm {
public:
    MonteCarlo();
    AlgorithmResult run(const World& world, double allowed_time, int player);
private:
    int m_profondeur;
};
