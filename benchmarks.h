#pragma once

#include "config.h"

#ifdef RUN_BENCHMARKS

#include "BenchmarkAbstractGroups.h"

void DO_RUN_BENCHMARKS() {
    BenchmarkAbstractGroups groups;

    Benchmark::run_all(5.0);
}

#endif
