#pragma once //<ck:del>

#include "Object.test"
#include "CappedArray.test"
#include "ExpansibleArray.test"
#include "CycleArray.test"

void register_default_tests() {
    Object_test* t1 = new Object_test();
    CappedArray_test* t2 = new CappedArray_test();
    ExpansibleArray_test* t3 = new ExpansibleArray_test();
    CycleArray_test* t4 = new CycleArray_test();
}
