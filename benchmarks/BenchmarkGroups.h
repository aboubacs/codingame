#pragma once //<ck:del>

#include "Benchmark.h"

class BenchmarkGroups : public Benchmark {
public:
    BenchmarkGroups();
    void run(double allowed_time);
};


