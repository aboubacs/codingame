#pragma once

#include "../config/config.h"

#ifdef RUN_BENCHMARKS

#include "BenchmarkGroups.h"

void DO_RUN_BENCHMARKS() {
    BenchmarkGroups groups;
    cerr << "Running benchmarks. It will take "
         << BENCHMARKS_ALLOCATED_TIME
         << " seconds" << endl;
    Benchmark::run_all(BENCHMARKS_ALLOCATED_TIME);
}

#endif
