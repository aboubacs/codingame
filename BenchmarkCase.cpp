#include "BenchmarkCase.h"
#include "Benchmark.h"
#include "Util.h"
#include "my_assert.h"

BenchmarkCase::BenchmarkCase(const string &name, void (*fct)())
    : m_fct(fct), m_name(name) {}


void BenchmarkCase::perform_case(double allowed_time) {
    ASSERT(allowed_time > 0);

    m_time_control.set_checkpoint();
    uint64_t counter = 0;
    while (!m_time_control.is_elapsed(allowed_time)) {
        m_fct();
        counter++;
    }
    cerr << Util::StringBigNumber(counter) << " (" << m_name << ")" << endl;
}