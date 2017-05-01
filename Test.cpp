#include <iostream>

#include "Test.h"

using namespace std;

vector<Test*> Test::registered;

Test::Test() {
    Test::registered.push_back(this);
}

bool Test::run_all() {
    for (auto test: Test::registered) {
        test->run();
        cerr << "OK" << endl;
    }
    return true;
}