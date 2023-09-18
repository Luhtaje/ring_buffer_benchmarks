#include "ring_buffer.hpp"
#include <benchmark/benchmark.h>
#include <vector>


ring_buffer<size_t> find_buffer(50000, 1);
std::vector<size_t> find_vec(50000, 1);

ring_buffer<size_t> find_if_buffer(50000, 1);
std::vector<size_t> find_if_vec(50000, 1);

ring_buffer<size_t> find_if_not_buffer(500000, 1);
std::vector<size_t> find_if_not_vec(500000, 1);

bool pred(int n)
{
    return n > 1;
}

static void BM_find_buffer(benchmark::State& state)
{
    find_buffer.pop_front();
    find_buffer.insert(find_buffer.begin() + 25000, 2);
    for(auto _ : state)
    {
        for(auto i = 1001; i < state.range(0); i++)
        {
            std::find(find_buffer.begin(), find_buffer.end(), (2));
        }
    }
}

static void BM_find_vector(benchmark::State& state)
{
    find_vec.pop_back();
    find_vec.insert(find_vec.begin() + 25000, 2);

    for(auto _ : state)
    {
        for(auto i = 1001; i < state.range(0); i++)
        {
            std::find(find_vec.begin(), find_vec.end(), 2);
        }
    }
}

static void BM_find_if_buffer(benchmark::State& state)
{
    find_if_buffer.pop_front();
    find_if_buffer.insert(find_if_buffer.begin() + 25000, 2);
    for(auto _ : state)
    {
        for(auto i = 1001; i < state.range(0); i++)
        {
            std::find_if(find_if_buffer.begin(), find_if_buffer.end(), pred);
        }
    }
}

static void BM_find_if_vector(benchmark::State& state)
{
    find_if_vec.pop_back();
    find_if_vec.insert(find_if_vec.begin() + 25000, 2);
    
    for(auto _ : state)
    {
        for(auto i = 1001; i < state.range(0); i++)
        {
            std::find_if(find_if_vec.begin(), find_if_vec.end(), pred);
        }
    }
}

static void BM_find_if_not_buffer(benchmark::State& state)
{
    find_if_not_buffer.pop_front();
    find_if_not_buffer.insert(find_if_not_buffer.begin() + 25000, 2);
    for(auto _ : state)
    {
        for(auto i = 1001; i < state.range(0); i++)
        {
            std::find_if_not(find_if_not_buffer.begin(), find_if_not_buffer.end(), pred);
        }
    }
}

static void BM_find_if_not_vector(benchmark::State& state)
{
    find_if_not_vec.pop_back();
    find_if_not_vec.insert(find_if_not_vec.begin() + 25000, 2);
    
    for(auto _ : state)
    {
        for(auto i = 1001; i < state.range(0); i++)
        {
            std::find_if_not(find_if_not_vec.begin(), find_if_vec.end(), pred);
        }
    }
}

BENCHMARK(BM_find_buffer)->Range(1, 1 << 6);
BENCHMARK(BM_find_vector)->Range(1, 1 << 6);
BENCHMARK(BM_find_if_buffer)->Range(1, 1 << 6);
BENCHMARK(BM_find_if_vector)->Range(1, 1 << 6);
BENCHMARK(BM_find_if_not_buffer)->Range(1, 1 << 6);
BENCHMARK(BM_find_if_not_vector)->Range(1, 1 << 6);



BENCHMARK_MAIN();