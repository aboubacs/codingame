#include "Benchmark.h"

vector<Benchmark*> Benchmark::registered;

Benchmark::Benchmark() {
    Benchmark::registered.push_back(this);
}

void Benchmark::run_all(double allowed_time) {
    for (auto benchmark: Benchmark::registered) {
        benchmark->run(
            allowed_time / Benchmark::registered.size()
        );
    }
}

void Benchmark::register_case(BenchmarkCase* benchark_case) {
    m_benchmark_cases.push_back(benchark_case);
}