#include "ring_buffer.hpp"

#include <benchmark/benchmark.h>
#include <vector>
#include <deque>
#include <list>

template <typename Container>
void BM_InsertAtBegin(benchmark::State& state) {
    const long long test_value = 42;
    
    Container container(state.range(0));

    for (auto _ : state) {
        container.insert(container.begin(), test_value);
    }
}

template <typename Container>
void BM_InsertAtEnd(benchmark::State& state) {
    const long long test_value = 42;
    
    Container container(state.range(0));

    for (auto _ : state) {
        container.insert(container.end(), test_value);
    }
}

template <typename Container>
void RegisterInsertBeginBenchmark(const std::string& name) {

    benchmark::RegisterBenchmark(name.c_str(), BM_InsertAtBegin<Container>)
        ->RangeMultiplier(2)
        ->Range(10000, 100000)
        ->Unit(benchmark::kNanosecond);
}

template <typename Container>
void RegisterInsertEndBenchmark(const std::string& name) {

    benchmark::RegisterBenchmark(name.c_str(), BM_InsertAtEnd<Container>)
        ->RangeMultiplier(2)
        ->Range(10000, 100000)
        ->Unit(benchmark::kNanosecond);
}

template <typename Container>
void RegisterBenchmark(const std::string& name) {

    benchmark::RegisterBenchmark(name.c_str(), BM_InsertAtBegin<Container>)
        ->RangeMultiplier(2)
        ->Range(10000, 100000)
        ->Unit(benchmark::kNanosecond);
}

int main(int argc, char** argv) {
    RegisterInsertBeginBenchmark<std::vector<long long>>("BM_Vector_InsertAtBegin");
    RegisterInsertBeginBenchmark<std::deque<long long>>("BM_Deque_InsertAtBegin");
    RegisterInsertBeginBenchmark<std::list<long long>>("BM_List_InsertAtBegin");
    RegisterInsertBeginBenchmark<ring_buffer<long long>>("BM_RingBuffer_InsertAtBegin");

    RegisterInsertEndBenchmark<std::vector<long long>>("BM_Vector_InsertAtEnd");
    RegisterInsertEndBenchmark<std::deque<long long>>("BM_Deque_InsertAtEnd");
    RegisterInsertEndBenchmark<std::list<long long>>("BM_List_InsertAtEnd");
    RegisterInsertEndBenchmark<ring_buffer<long long>>("BM_RingBuffer_InsertAtEnd");

    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();

    return 0;
}
