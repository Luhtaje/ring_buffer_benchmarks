#include "ring_buffer.hpp"
#include <benchmark/benchmark.h>

    ring_buffer<size_t> buffer(1000, 1);
    std::vector<size_t> vec(1000, 1);

static void BM_access_buffer(benchmark::State& state) 
{
    for(auto _ : state)
    {
        for(auto i = 0; i < state.range(0); i++)
        {
            buffer[i];
        }
    }
}

static void BM_access_vector(benchmark::State& state) 
{
    for(auto _ : state)
    {
        for(auto i = 0; i < state.range(0); i++)
        {
            vec[i];
        }
    }
}

BENCHMARK(BM_access_buffer)->Range(1, 1000);
BENCHMARK(BM_access_vector)->Range(1, 1000);

BENCHMARK_MAIN();