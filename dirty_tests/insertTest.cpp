#include "ring_buffer.hpp"
#include <benchmark/benchmark.h>

ring_buffer<size_t> buffer(10);
std::vector<size_t> vec(10);

static void BM_reserve_buffer(benchmark::State& state) 
{
    for(auto _ : state)
    {
        for(auto i = 0; i < state.range(0); i++)
        {
            buffer.insert(buffer.begin(), i);
        }
    }
}

static void BM_reserve_vector(benchmark::State& state) 
{
    for(auto _ : state)
    {
        for(auto i = 0; i < state.range(0); i++)
        {
            vec.insert(vec.begin(), i);
        }
    }
}

BENCHMARK(BM_reserve_buffer)->Range(1, 1 << 6);
BENCHMARK(BM_reserve_vector)->Range(1, 1 << 6);

BENCHMARK_MAIN();