#include <benchmark/benchmark.h>

#include "ring_buffer.hpp"
#include <vector>
#include <deque>
#include <list>

template <typename Container>
void BM_construction(benchmark::State& state) {
    const int size = static_cast<int>(state.range(0));
    for (auto _ : state) {
        Container container(size);
    }
}

template <typename Container>
void RegisterBenchmark(const std::string& name) {

    benchmark::RegisterBenchmark(name.c_str(), BM_construction<Container>)
        ->RangeMultiplier(2)
        ->Range(10000, 100000)
        ->Unit(benchmark::kNanosecond);
}

int main(int argc, char** argv)
{
    RegisterBenchmark<std::vector<long long>>("BM_Vector_Construction");
    RegisterBenchmark<std::deque<long long>>("BM_Deque_Construction");
    RegisterBenchmark<std::list<long long>>("BM_List_Construction");
    RegisterBenchmark<ring_buffer<long long>>("BM_RingBuffer_IndexAccess");

    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
}