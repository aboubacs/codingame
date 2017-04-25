#pragma once //<ck:del>

#include <string>

#include "config.h"

using namespace std;

class Object {
public:
    void show();

#ifdef OBJECT_PROPERTIES
    Object(const string& name="");
    string obj_name;
    static uint64_t obj_sid;
    uint64_t obj_id;
#else
    Object();
#endif
};
