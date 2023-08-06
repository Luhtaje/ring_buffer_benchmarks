#include <benchmark/benchmark.h>
#include "ring_buffer.hpp"


    ring_buffer<size_t> buffer(1000);
    std::vector<size_t> vec(1000);

static void BM_default_buffer(benchmark::State& state) 
{
    for(auto _ : state)
    {
        for(auto i = 1001; i < state.range(0); i++)
        {
                ring_buffer<size_t> buffer;
        }
    }
}

static void BM_default_vector(benchmark::State& state) 
{
    for(auto _ : state)
    {
        for(auto i = 1001; i < state.range(0); i++)
        {
            std::vector<size_t> vec;
        }
    }
}

static void BM_value_buffer(benchmark::State& state) 
{
    for(auto _ : state)
    {
        for(auto i = 1001; i < state.range(0); i++)
        {
                ring_buffer<size_t>();
        }
    }
}

static void BM_value_vector(benchmark::State& state) 
{
    for(auto _ : state)
    {
        for(auto i = 1001; i < state.range(0); i++)
        {
            std::vector<size_t>();
        }
    }
}

BENCHMARK(BM_default_buffer)->Range(15000, 15000 << 2);
BENCHMARK(BM_default_vector)->Range(15000, 15000 << 2);

BENCHMARK(BM_value_buffer)->Range(15000, 15000 << 2);
BENCHMARK(BM_value_vector)->Range(15000, 15000 << 2);

BENCHMARK_MAIN();