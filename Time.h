#pragma once //<ck:del>

#include <chrono>

#include "Object.h"

using namespace std;
using namespace chrono;

class Time : Object {
public:
    Time();
    void set_checkpoint();
    bool is_elapsed(double time);
protected:
    high_resolution_clock::time_point m_checkpoint_time;
};


