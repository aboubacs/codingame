#include <chrono>

#include "MonteCarlo.h"
#include "my_assert.h"

using namespace std;
using namespace chrono;

MonteCarlo::MonteCarlo() : Algorithm() {}

AlgorithmResult MonteCarlo::run(const World& world, double allowed_time, int player) {
    ASSERT(m_generator != NULL);
    m_time_control.set_checkpoint();
    while (!m_time_control.is_elapsed(allowed_time)) {

    }
}