#pragma once //<ck:del>

#include "Object.test"
#include "GroupArrayMaxSize.test"

void register_default_tests() {
    Object_test* t1 = new Object_test();
    GroupArrayMaxSize_test* t2 = new GroupArrayMaxSize_test();
}
