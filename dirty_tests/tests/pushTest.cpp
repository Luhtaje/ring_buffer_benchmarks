#include "ring_buffer.hpp"
#include <vector>
#include <benchmark/benchmark.h>
#include <vector>
#include <deque>
#include <list>

template <typename Container>
void BM_PushBack(benchmark::State& state) {
    const long long test_value = 652;
    
    Container container(state.range(0));

    for (auto _ : state) {
        container.push_back(test_value);
    }
}

template <typename Container>
void BM_PushFront(benchmark::State& state) {
    const long long test_value = 42;
    
    Container container(state.range(0));

    for (auto _ : state) {
        container.push_front(test_value);
    }
}

template <typename Container>
void RegisterPushBackBenchmark(const std::string& name) {

    benchmark::RegisterBenchmark(name.c_str(), BM_PushBack<Container>)
        ->RangeMultiplier(2)
        ->Range(10000, 100000)
        ->Unit(benchmark::kNanosecond);
}

template <typename Container>
void RegisterPushFrontBenchmark(const std::string& name) {

    benchmark::RegisterBenchmark(name.c_str(), BM_PushFront<Container>)
        ->RangeMultiplier(2)
        ->Range(10000, 100000)
        ->Unit(benchmark::kNanosecond);
}

int main(int argc, char** argv) {
    // Register benchmarks for different container types
    RegisterPushFrontBenchmark<std::deque<long long>>("BM_Deque_PushFront");
    RegisterPushFrontBenchmark<std::list<long long>>("BM_List_PushFront");
    RegisterPushFrontBenchmark<ring_buffer<long long>>("BM_RingBuffer_PushFront");

    RegisterPushBackBenchmark<std::vector<long long>>("BM_Vector_PushBack");
    RegisterPushBackBenchmark<std::deque<long long>>("BM_Deque_PushBack");
    RegisterPushBackBenchmark<std::list<long long>>("BM_List_PushBack");
    RegisterPushBackBenchmark<ring_buffer<long long>>("BM_RingBuffer_PushBack");

    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();

    return 0;
}
