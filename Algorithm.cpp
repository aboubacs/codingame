#include "Algorithm.h"

Algorithm::Algorithm() {
    m_generator = nullptr;
}

void Algorithm::set_decision_generator(DecisionGenerator *generator) {
    m_generator = generator;
}