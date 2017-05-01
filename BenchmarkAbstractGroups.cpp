#include "BenchmarkAbstractGroups.h"
#include "GroupArrayMaxSize.h"
#include "GroupArrayExpansible.h"
#include "macros.h"
#include "Optimize.h"

GroupArrayMaxSize<int, 50> global_1;
GroupArrayExpansible<int, 10> global_2;

BenchmarkAbstractGroups::BenchmarkAbstractGroups() {
    loop(i, 10) {
        global_1.push(42);
    }
    loop(i, 10) {
        global_2.push(42);
    }
}



template<int s, int l>
void push_max_size() {
    GroupArrayMaxSize<int, s> g;
    loop(i, l) {
        g.push(42);
    }
}

template<int s, int l>
void push_expansible() {
    GroupArrayExpansible<int, s> g;
    loop(i, l) {
        g.push(42);
    }
}

void case7() {
    GroupArrayMaxSize<int, 50> glou(global_1);
}
void case8() {
    GroupArrayExpansible<int, 10> glou(global_2);
}

void BenchmarkAbstractGroups::run(double allowed_time) {
    ASSERT(allowed_time > 0);

    cerr << "Running benckmark Groups :" << endl;
    this->m_time_control.set_checkpoint();

    this->register_case(new BenchmarkCase("Push 30 int with max size 50", push_max_size<50,30>));
    this->register_case(new BenchmarkCase("Push 30 int with extended 40", push_expansible<40,30>));
    this->register_case(new BenchmarkCase("Push 30 int with extended 30", push_expansible<30,30>));
    this->register_case(new BenchmarkCase("Push 50 int with max size 50", push_max_size<50,50>));
    this->register_case(new BenchmarkCase("Push 50 int with extended 40", push_expansible<40,50>));
    this->register_case(new BenchmarkCase("Push 50 int with extended 30", push_expansible<30,50>));
    this->register_case(new BenchmarkCase("Copy max size 50 with 10 elements (without copy overload)", &case7));
    this->register_case(new BenchmarkCase("Copy extended 10 with 10 elements", &case8));

    for (auto benchmark_case : this->m_benchmark_cases) {
        benchmark_case->perform_case(
            allowed_time / this->m_benchmark_cases.size()
        );
    }
}