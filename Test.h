#pragma once //<ck:del>

#include <vector>

using namespace std;

class Test {
public:
    Test();
    static bool run_all();
private:
    virtual bool run()=0;
    static vector<Test*> registered;
};

