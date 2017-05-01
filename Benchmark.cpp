#include "Benchmark.h"

vector<Benchmark*> Benchmark::registered;

Benchmark::Benchmark() {
    Benchmark::registered.push_back(this);
}

void Benchmark::run_all(double allowed_time) {
    ASSERT(allowed_time > 0);
    for (auto benchmark: Benchmark::registered) {
        benchmark->run(
            allowed_time / Benchmark::registered.size()
        );
    }
}

void Benchmark::register_case(BenchmarkCase* benchmark_case) {
    ASSERT(benchmark_case != nullptr);
    m_benchmark_cases.push_back(benchmark_case);
}