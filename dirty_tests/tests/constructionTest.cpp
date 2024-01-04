#include <benchmark/benchmark.h>

#include "ring_buffer.hpp"
#include <vector>

ring_buffer<size_t> construction_buffer(1000);
std::vector<size_t> construction_vec(1000);

static void BM_construction_default_buffer(benchmark::State& state) 
{
    for(auto _ : state)
    {
        for(auto i = 1001; i < state.range(0); i++)
        {
                ring_buffer<size_t> buffer;
        }
    }
}

static void BM_construction_default_vector(benchmark::State& state) 
{
    for(auto _ : state)
    {
        for(auto i = 1001; i < state.range(0); i++)
        {
            std::vector<size_t> vec;
        }
    }
}

static void BM_construction_value_buffer(benchmark::State& state) 
{
    for(auto _ : state)
    {
        for(auto i = 1001; i < state.range(0); i++)
        {
                ring_buffer<size_t>();
        }
    }
}

static void BM_construction_value_vector(benchmark::State& state) 
{
    for(auto _ : state)
    {
        for(auto i = 1001; i < state.range(0); i++)
        {
            std::vector<size_t>();
        }
    }
}

BENCHMARK(BM_construction_default_buffer)->Range(15000, 15000 << 2);
BENCHMARK(BM_construction_default_vector)->Range(15000, 15000 << 2);

BENCHMARK(BM_construction_value_buffer)->Range(15000, 15000 << 2);
BENCHMARK(BM_construction_value_vector)->Range(15000, 15000 << 2);