#include <benchmark/benchmark.h>

#include "ring_buffer.hpp"
#include <vector>

ring_buffer<size_t> small_begin_buffer(200);
std::vector<size_t> small_begin_vec(200);
ring_buffer<size_t> small_end_buffer(200);
std::vector<size_t> small_end_vec(200);

ring_buffer<size_t> medium_begin_buffer(10000);
std::vector<size_t> medium_begin_vec(10000);
ring_buffer<size_t> medium_end_buffer(10000);
std::vector<size_t> medium_end_vec(10000);

ring_buffer<size_t> large_begin_buffer(100000);
std::vector<size_t> large_begin_vec(100000);
ring_buffer<size_t> large_end_buffer(100000);
std::vector<size_t> large_end_vec(100000);


//Special case where the elements have "wrapped around" in the physical the memory.
ring_buffer<size_t> shuffled_begin_buffer(5000);
ring_buffer<size_t> shuffled_end_buffer(5000);

//High and low represent the two possible middle elements of a even set. In physical memory these will be at the first physical element and last physical element.
ring_buffer<size_t> shuffled_middle_low_buffer(5000);
ring_buffer<size_t> shuffled_middle_high_buffer(5000);





// Initialization function. This moves 2500 elements to the beginning of the memory and 2500 to the end, leaving the middle uninitialized.
void SetUpEnvironment() {
    for(size_t i = 0; i < 2500 ; i++)
    {
        shuffled_begin_buffer.pop_front();
        shuffled_begin_buffer.push_back(i);

        shuffled_end_buffer.pop_front();
        shuffled_end_buffer.push_back(i);

        shuffled_middle_low_buffer.pop_front();
        shuffled_middle_low_buffer.push_back(i);

        shuffled_middle_high_buffer.pop_front();
        shuffled_middle_high_buffer.push_back(i);
    }
}




//==================================================================
//Small container, insert to begin
static void BM_insert_small_begin_buffer(benchmark::State& state) 
{
    for(auto _ : state )
    {
        for(auto i = 0; i < state.range(0); i++)
        {
            small_begin_buffer.insert(small_begin_buffer.begin(), i);
        }
    }
}

static void BM_insert_small_begin_vector(benchmark::State& state) 
{
    for(auto _ : state)
    {
        for(auto i = 0; i < state.range(0); i++)
        {
            small_begin_vec.insert(small_begin_vec.begin(), i);
        }
    }
}

//=================================================================
//Small container, insert to end
static void BM_insert_small_end_buffer(benchmark::State& state) 
{
    for(auto _ : state )
    {
        for(auto i = 0; i < state.range(0); i++)
        {
            small_end_buffer.insert(small_end_buffer.end(), i);
        }
    }
}

static void BM_insert_small_end_vector(benchmark::State& state) 
{
    for(auto _ : state)
    {
        for(auto i = 0; i < state.range(0); i++)
        {
            small_end_vec.insert(small_end_vec.end(), i);
        }
    }
}
//==================================================================
///Medium container size
//==================================================================
//Medium container, insert to begin
static void BM_insert_medium_begin_buffer(benchmark::State& state) 
{
    for(auto _ : state )
    {
        for(auto i = 0; i < state.range(0); i++)
        {
            medium_begin_buffer.insert(medium_begin_buffer.begin(), i);
        }
    }
}

static void BM_insert_medium_begin_vector(benchmark::State& state) 
{
    for(auto _ : state)
    {
        for(auto i = 0; i < state.range(0); i++)
        {
            medium_begin_vec.insert(medium_begin_vec.begin(), i);
        }
    }
}

//=================================================================
//medium container, insert to end
static void BM_insert_medium_end_buffer(benchmark::State& state) 
{
    for(auto _ : state )
    {
        for(auto i = 0; i < state.range(0); i++)
        {
            medium_end_buffer.insert(medium_end_buffer.end(), i);
        }
    }
}

static void BM_insert_medium_end_vector(benchmark::State& state) 
{
    for(auto _ : state)
    {
        for(auto i = 0; i < state.range(0); i++)
        {
            medium_end_vec.insert(medium_end_vec.end(), i);
        }
    }
}

//==================================================================
///Large container size
//==================================================================
//Large container, insert to begin
static void BM_insert_large_begin_buffer(benchmark::State& state) 
{
    for(auto _ : state )
    {
        for(auto i = 0; i < state.range(0); i++)
        {
            large_begin_buffer.insert(large_begin_buffer.begin(), i);
        }
    }
}

static void BM_insert_large_begin_vector(benchmark::State& state) 
{
    for(auto _ : state)
    {
        for(auto i = 0; i < state.range(0); i++)
        {
            large_begin_vec.insert(large_begin_vec.begin(), i);
        }
    }
}

//=================================================================
//large container, insert to end
static void BM_insert_large_end_buffer(benchmark::State& state) 
{
    for(auto _ : state )
    {
        for(auto i = 0; i < state.range(0); i++)
        {
            large_end_buffer.insert(large_end_buffer.end(), i);
        }
    }
}

static void BM_insert_large_end_vector(benchmark::State& state) 
{
    for(auto _ : state)
    {
        for(auto i = 0; i < state.range(0); i++)
        {
            large_end_vec.insert(large_end_vec.end(), i);
        }
    }
}

//===============================================================
//Shuffled buffer_tests

static void BM_insert_shuffled_begin_buffer(benchmark::State& state) 
{
    for(auto _ : state )
    {
        for(auto i = 0; i < state.range(0); i++)
        {
            shuffled_begin_buffer.insert(shuffled_begin_buffer.begin(), i);
        }
    }
}

static void BM_insert_shuffled_end_buffer(benchmark::State& state) 
{
    for(auto _ : state )
    {
        for(auto i = 0; i < state.range(0); i++)
        {
            shuffled_end_buffer.insert(shuffled_end_buffer.end(), i);
        }
    }
}

static void BM_insert_shuffled_middle_low_buffer(benchmark::State& state) 
{
    ring_buffer<size_t>::iterator posIt(&shuffled_middle_low_buffer, shuffled_middle_low_buffer.size() / 2 - 1);
    for(auto _ : state )
    {
        for(auto i = 0; i < state.range(0); i++)
        {
            shuffled_middle_low_buffer.insert(posIt, i);
        }
    }
}


static void BM_insert_shuffled_middle_high_buffer(benchmark::State& state) 
{
    ring_buffer<size_t>::iterator posIt(&shuffled_middle_high_buffer, shuffled_middle_high_buffer.size() / 2 + 1);
    for(auto _ : state )
    {
        for(auto i = 0; i < state.range(0); i++)
        {
            shuffled_middle_high_buffer.insert(posIt, i);
        }
    }
}

BENCHMARK(BM_insert_small_begin_buffer)->Range(1, 1 << 6);
BENCHMARK(BM_insert_small_begin_vector)->Range(1, 1 << 6);
BENCHMARK(BM_insert_small_end_buffer)->Range(1, 1 << 6);
BENCHMARK(BM_insert_small_end_vector)->Range(1, 1 << 6);

BENCHMARK(BM_insert_medium_begin_buffer)->Range(1, 1 << 6);
BENCHMARK(BM_insert_medium_begin_vector)->Range(1, 1 << 6);
BENCHMARK(BM_insert_medium_end_buffer)->Range(1, 1 << 6);
BENCHMARK(BM_insert_medium_end_vector)->Range(1, 1 << 6);

BENCHMARK(BM_insert_large_begin_buffer)->Range(1, 1 << 6);
BENCHMARK(BM_insert_large_begin_vector)->Range(1, 1 << 6);
BENCHMARK(BM_insert_large_end_buffer)->Range(1, 1 << 6);
BENCHMARK(BM_insert_large_end_vector)->Range(1, 1 << 6);

BENCHMARK(BM_insert_shuffled_begin_buffer)->Range(1, 1 << 6);
BENCHMARK(BM_insert_shuffled_end_buffer)->Range(1, 1 << 6);
BENCHMARK(BM_insert_shuffled_middle_low_buffer)->Range(1, 1 << 6);
BENCHMARK(BM_insert_shuffled_middle_high_buffer)->Range(1, 1 << 6);