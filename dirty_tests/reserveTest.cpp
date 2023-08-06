#include "ring_buffer.hpp"
#include <benchmark/benchmark.h>

    ring_buffer<size_t> buffer(50000, 1);
    std::vector<size_t> vec(50000, 1);

static void BM_reserve_buffer(benchmark::State& state)
{
    for(auto _ : state)
    {
        for(auto i = 1001; i < state.range(0); i++)
        {
            buffer.reserve(i);
        }
    }
}

static void BM_reserve_vector(benchmark::State& state)
{
    for(auto _ : state)
    {
        for(auto i = 1001; i < state.range(0); i++)
        {
            vec.reserve(i);
        }
    }
}

BENCHMARK(BM_reserve_buffer)->Range(15000, 15000 << 2);
BENCHMARK(BM_reserve_vector)->Range(15000, 15000 << 2);

BENCHMARK_MAIN();