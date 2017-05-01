#pragma once //<ck:del>

#include <vector>

#include "../util/Object.h"
#include "../util/Time.h"
#include "BenchmarkCase.h"

class Benchmark : public Object {
public:
    Benchmark();
    virtual void run(double allowed_time)=0;
    static void run_all(double allowed_time);
    void register_case(BenchmarkCase* benchmark_case);

protected:
    Time m_time_control;
    vector<BenchmarkCase*> m_benchmark_cases;

private:
    static vector<Benchmark*> registered;
};


