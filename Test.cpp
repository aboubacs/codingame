#include <iostream>

#include "Test.h"

using namespace std;

vector<Test*> Test::registered;

Test::Test() {
    Test::registered.push_back(this);
}

bool Test::run_all() {
    for (auto test: Test::registered) {
        if (!test->run()) {
            return false;
        } else {
            cerr << "OK" << endl;
        }
    }
    return true;
}