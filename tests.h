#pragma once //<ck:del>

#ifdef RUN_TESTS

#include "Test.h"

#include "default_tests.h"

#define DO_RUN_TESTS() \
    DO_RUN_DEFAULT_TESTS() \
    Test::run_all();


#endif

