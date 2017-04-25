#include "config.h"

#include <iostream>

#include "my_assert.h"

#include "World.h"
#include "tests.h"

using namespace std;

int main() {
#ifdef RUN_TESTS
    DO_RUN_TESTS();
#endif
    World w;
    return 0;
}