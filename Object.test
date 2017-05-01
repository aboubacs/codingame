#pragma once //<ck:del>

#include <iostream>
#include <assert.h>

#include "Test.h"
#include "Object.h"
#include "my_assert.h"

using namespace std;

class Object_test : Test {
public:
    Object_test():Test() {}

    bool run() {
        cerr << "Running Object_tests : " << endl;

#ifdef OBJECT_PROPERTIES
        Object obj = Object();
        assert(obj.obj_name == "");
        obj.obj_name = "New name";
        assert(obj.obj_name == "New name");
        Object obj2 = Object("Construct name");
        assert(obj2.obj_name == "Construct name");
        assert(obj2.obj_id == 1+obj.obj_id);
#else
        cerr << "[INFO] Macro 'OBJECT_PROPERTIES' is at 0, nothing to test" << endl;
        cerr << "       You may want to set it to 1 to test more about Object" << endl;
#endif

        return true;
    }
};


