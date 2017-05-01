#pragma once

#include "Time.h"


class Benchmark;

class BenchmarkCase {
public:
    BenchmarkCase(const string& name, void (*fct)());
    void perform_case(double allowed_time);

protected:
    void (*m_fct)();
    Time m_time_control;
    string m_name;
};


