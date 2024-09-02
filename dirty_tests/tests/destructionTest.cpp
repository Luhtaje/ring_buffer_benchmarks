#include <benchmark/benchmark.h>

#include "ring_buffer.hpp"
#include <vector>
#include <deque>
#include <list>

template <typename Container>
void BM_destruction(benchmark::State& state) {
    const int size = static_cast<int>(state.range(0));
    for (auto _ : state) {
        state.PauseTiming();
        {
            Container container(size);
            state.ResumeTiming();
        }
    }
}

template <typename Container>
void RegisterBenchmark(const std::string& name) {

    benchmark::RegisterBenchmark(name.c_str(), BM_destruction<Container>)
        ->RangeMultiplier(2)
        ->Range(10000, 100000)
        ->Unit(benchmark::kNanosecond);
}

int main(int argc, char** argv)
{
    RegisterBenchmark<std::vector<long long>>("BM_Vector_destruction");
    RegisterBenchmark<std::deque<long long>>("BM_Deque_destruction");
    RegisterBenchmark<std::list<long long>>("BM_List_destruction");
    RegisterBenchmark<ring_buffer<long long>>("BM_RingBuffer_destruction");

    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
}