#pragma once //<ck:del>

#include <chrono>

#include "Object.h"

using namespace std;
using namespace chrono;

#define NOW high_resolution_clock::now()

class Time : Object {
public:
    Time();
    void set_checkpoint();
    bool is_elapsed(double time);
    double get_time_left(double time) const;

protected:
    high_resolution_clock::time_point m_checkpoint_time;
};


