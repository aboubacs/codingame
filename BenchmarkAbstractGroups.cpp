#include "BenchmarkAbstractGroups.h"
#include "GroupArrayMaxSize.h"
#include "GroupArrayExtendable.h"
#include "macros.h"
#include "Optimize.h"

GroupArrayMaxSize<int, 50> global_1;
GroupArrayExtendable<int, 10> global_2;

BenchmarkAbstractGroups::BenchmarkAbstractGroups() {
    loop(i, 10) {
        global_1.push(42);
    }
    loop(i, 10) {
        global_2.push(42);
    }
}


void case1() {
    GroupArrayMaxSize<int, 50> g;
    loop(i, 30) {
        g.push(42);
    }
}
void case2() {
    GroupArrayExtendable<int, 40> g;
    loop(i, 30) {
        g.push(42);
    }
}
void case5() {
    GroupArrayExtendable<int, 30> g;
    loop(i, 30) {
        g.push(42);
    }
}
void case3() {
    GroupArrayMaxSize<int, 50> g;
    loop(i, 50) {
        g.push(42);
    }
}
void case4() {
    GroupArrayExtendable<int, 40> g;
    loop(i, 50) {
        g.push(42);
    }
}
void case6() {
    GroupArrayExtendable<int, 30> g;
    loop(i, 50) {
        g.push(42);
    }
}
void case7() {
    GroupArrayMaxSize<int, 50> glou(global_1);
}
void case8() {
    GroupArrayExtendable<int, 10> glou(global_2);
}

void BenchmarkAbstractGroups::run(double allowed_time) {
    ASSERT(allowed_time > 0);

    cerr << "Running benckmark Groups :" << endl;
    this->m_time_control.set_checkpoint();

    this->register_case(new BenchmarkCase("Push 30 int with max size 50", &case1));
    this->register_case(new BenchmarkCase("Push 30 int with extended 40", &case2));
    this->register_case(new BenchmarkCase("Push 30 int with extended 30", &case5));
    this->register_case(new BenchmarkCase("Push 50 int with max size 50", &case3));
    this->register_case(new BenchmarkCase("Push 50 int with extended 40", &case4));
    this->register_case(new BenchmarkCase("Push 50 int with extended 30", &case6));
    this->register_case(new BenchmarkCase("Copy max size 50 with 10 elements (without copy overload)", &case7));
    this->register_case(new BenchmarkCase("Copy extended 10 with 10 elements", &case8));

    for (auto benchmark_case : this->m_benchmark_cases) {
        benchmark_case->perform_case(
            allowed_time / this->m_benchmark_cases.size()
        );
    }
}