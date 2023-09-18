#include "ring_buffer.hpp"
#include <benchmark/benchmark.h>

    ring_buffer<size_t> small_buffer(1, 1);
    std::vector<size_t> small_vec(1, 1);

static void BM_reserve_small_buffer(benchmark::State& state)
{
    for(auto _ : state)
    {
        for(auto i = state.range(0) ; i < state.range(0) + 1000 ; i++)
        {
            if(i % 2 == 0)
            small_buffer.reserve(i);
        }
    }
}

static void BM_reserve_small_vector(benchmark::State& state)
{
    for(auto _ : state)
    {
        for(auto i = state.range(0) ; i < state.range(0) + 1000 ; i++)
        {
            if(i % 2 == 0)
            small_vec.reserve(i);
        }
    }
}

// static void BM_reserve_medium_buffer(benchmark::State& state)
// {
//     for(auto _ : state)
//     {
//         for(auto i = 0; i < ; i++)
//         {
//             medium_buffer.reserve(state.range(0));
//         }
//     }
// }

// static void BM_reserve_medium_vector(benchmark::State& state)
// {
//     for(auto _ : state)
//     {
//         for(auto i = ; i < state.range(0); i++)
//         {
//             medium_vec.reserve(i);
//         }
//     }
// }

BENCHMARK(BM_reserve_small_buffer)->Range(2048, 1 << 19);
BENCHMARK(BM_reserve_small_vector)->Range(2048, 1 << 19);
// BENCHMARK(BM_reserve_medium_buffer)->Range(4096, 1 << 13);
// BENCHMARK(BM_reserve_medium_vector)->Range(4096, 1 << 13);



BENCHMARK_MAIN();