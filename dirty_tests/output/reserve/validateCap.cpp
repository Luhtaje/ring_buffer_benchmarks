#include "ring_buffer.hpp"
#include <benchmark/benchmark.h>
#include <vector>

ring_buffer<int> buf(1,1);
std::vector<int> vec(1,1);

static void BM_buffer_natural_growth(benchmark::State& state)
{
    for(auto _ : state)
    {
        for(auto i = 0 ; i < state.range(0) ; i++)
        {
            buf.push_back(1);
        }
    }
}

static void BM_vector_natural_growth(benchmark::State& state)
{
    for(auto _ : state)
    {
        for(auto i = 0 ; i < state.range(0) ; i++)
        {
            vec.push_back(1);
        }
    }
}

//BENCHMARK(BM_buffer_natural_growth)->Range(1, 1 << 19);
BENCHMARK(BM_vector_natural_growth)->Range(1, 1 << 19);

BENCHMARK_MAIN();