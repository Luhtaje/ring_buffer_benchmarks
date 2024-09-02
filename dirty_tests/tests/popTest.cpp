#include "ring_buffer.hpp"
#include <vector>
#include <benchmark/benchmark.h>
#include <vector>
#include <deque>
#include <list>

template <typename Container>
void BM_PopBack(benchmark::State& state) {

    const size_t size = static_cast<size_t>(state.range(0));

    for (auto _ : state) {
        state.PauseTiming();
        Container container(size);
        state.ResumeTiming();

        container.pop_back();
    }
}

template <typename Container>
void BM_PopFront(benchmark::State& state) {

    const size_t size = static_cast<size_t>(state.range(0));

    for (auto _ : state) {
        state.PauseTiming();
        Container container(size);
        state.ResumeTiming();

        container.pop_front();
    }
}

template <typename Container>
void RegisterBackBenchmark(const std::string& name) {

    benchmark::RegisterBenchmark(name.c_str(), BM_PopBack<Container>)
        ->RangeMultiplier(2)
        ->Range(10000, 100000)
        ->Unit(benchmark::kNanosecond);
}

template <typename Container>
void RegisterFrontBenchmark(const std::string& name) {

    benchmark::RegisterBenchmark(name.c_str(), BM_PopFront<Container>)
        ->RangeMultiplier(2)
        ->Range(10000, 100000)
        ->Unit(benchmark::kNanosecond);
}

int main(int argc, char** argv) {
    RegisterFrontBenchmark<std::deque<long long>>("BM_Deque_PopFront");
    RegisterFrontBenchmark<std::list<long long>>("BM_List_PopFront");
    RegisterFrontBenchmark<ring_buffer<long long>>("BM_RingBuffer_PopFront");

    RegisterBackBenchmark<std::vector<long long>>("BM_Vector_PopBack");
    RegisterBackBenchmark<std::deque<long long>>("BM_Deque_PopBack");
    RegisterBackBenchmark<std::list<long long>>("BM_List_PopBack");
    RegisterBackBenchmark<ring_buffer<long long>>("BM_RingBuffer_PopBack");

    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();

    return 0;
}
