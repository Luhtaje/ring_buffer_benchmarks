#include <benchmark/benchmark.h>

#include "ring_buffer.hpp"
#include <vector>

ring_buffer<size_t> access_buffer(1000, 1);
std::vector<size_t> access_vec(1000, 1);

static void BM_access_buffer(benchmark::State& state) 
{
    for(auto _ : state)
    {
        for(auto i = 0; i < state.range(0); i++)
        {
            access_buffer[i];
        }
    }
}

static void BM_access_vector(benchmark::State& state) 
{
    for(auto _ : state)
    {
        for(auto i = 0; i < state.range(0); i++)
        {
            access_vec[i];
        }
    }
}

BENCHMARK(BM_access_buffer)->Range(1, 1000);
BENCHMARK(BM_access_vector)->Range(1, 1000);