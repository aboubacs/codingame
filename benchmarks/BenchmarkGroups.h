#pragma once //<ck:del>

#include "Benchmark.h"

class BenchmarkAbstractGroups : public Benchmark {
public:
    BenchmarkAbstractGroups();
    void run(double allowed_time);
};


