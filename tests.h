#pragma once //<ck:del>

#ifdef RUN_TESTS

#include "Test.h"

#include "default_tests.h"

void DO_RUN_TESTS() {
    register_default_tests();
    Test::run_all();
}

#endif

