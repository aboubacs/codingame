#pragma once

#include "config.h"

#ifdef RUN_BENCHMARKS

#include "BenchmarkAbstractGroups.h"

void DO_RUN_BENCHMARKS() {
    BenchmarkAbstractGroups groups;
    cerr << "Running benchmarks. It will take "
         << BENCHMARKS_ALLOCATED_TIME
         << " seconds" << endl;
    Benchmark::run_all(BENCHMARKS_ALLOCATED_TIME);
}

#endif
