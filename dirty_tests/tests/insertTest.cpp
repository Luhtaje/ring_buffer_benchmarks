#include <benchmark/benchmark.h>

#include "ring_buffer.hpp"
#include <vector>

ring_buffer<long long> b_10(10000);
ring_buffer<long long> b_20(20000);
ring_buffer<long long> b_30(30000);
ring_buffer<long long> b_40(40000);
ring_buffer<long long> b_50(50000);
ring_buffer<long long> b_60(60000);
ring_buffer<long long> b_70(70000);
ring_buffer<long long> b_80(80000);
ring_buffer<long long> b_90(90000);
ring_buffer<long long> b_100(100000);

std::vector<long long> v_10(10000);
std::vector<long long> v_20(20000);
std::vector<long long> v_30(30000);
std::vector<long long> v_40(40000);
std::vector<long long> v_50(50000);
std::vector<long long> v_60(60000);
std::vector<long long> v_70(70000);
std::vector<long long> v_80(80000);
std::vector<long long> v_90(90000);
std::vector<long long> v_100(100000);

ring_buffer<long long> medium_begin_buffer(10000);
std::vector<long long> medium_begin_vec(10000);
ring_buffer<long long> medium_end_buffer(10000);
std::vector<long long> medium_end_vec(10000);

ring_buffer<long long> large_begin_buffer(100000);
std::vector<long long> large_begin_vec(100000);
ring_buffer<long long> large_end_buffer(100000);
std::vector<long long> large_end_vec(100000);


ring_buffer<long long> small_begin_buffer(200);
std::vector<long long> small_begin_vec(200);
ring_buffer<long long> small_end_buffer(200);
std::vector<long long> small_end_vec(200);

ring_buffer<long long> medium_begin_buffer(10000);
std::vector<long long> medium_begin_vec(10000);
ring_buffer<long long> medium_end_buffer(10000);
std::vector<long long> medium_end_vec(10000);

ring_buffer<long long> large_begin_buffer(100000);
std::vector<long long> large_begin_vec(100000);
ring_buffer<long long> large_end_buffer(100000);
std::vector<long long> large_end_vec(100000);


//Special case where the elements have "wrapped around" in the physical the memory.
ring_buffer<long long> shuffled_begin_buffer(5000);
ring_buffer<long long> shuffled_end_buffer(5000);

//High and low represent the two possible middle elements of a even set. In physical memory these will be at the first physical element and last physical element.
ring_buffer<long long> shuffled_middle_low_buffer(5000);
ring_buffer<long long> shuffled_middle_high_buffer(5000);

long long testval = (long long) 1; 

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

b_10.reserve(100000);
b_20.reserve(100000);
b_30.reserve(100000);
b_40.reserve(100000);
b_50.reserve(100000);
b_60.reserve(100000);
b_70.reserve(100000);
b_80.reserve(100000);
b_90.reserve(100000);
b_10.reserve(110000);

v_10.reserve(100000);
v_20.reserve(100000);.
v_30.reserve(100000);.
v_40.reserve(100000);.
v_50.reserve(100000);.
v_60.reserve(100000);.
v_70.reserve(100000);.
v_80.reserve(100000);.
v_90.reserve(100000);.
v_100.reserve(110000);

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

static void BM_insert_shuffled_middle_buffer(benchmark::State& state) 
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


static void BM_insert_begin_buffer_10(benchmark::State& state)
{
    for(auto i = 0; i < 1000; i ++)
    {
        b_10.insert(begin(), testval);
    }
}

static void BM_insert_begin_buffer_20(benchmark::State& state)
{
    for(auto i = 0; i < 1000; i ++)
    {
        b_20.insert(begin(), testval);
    }
}

static void BM_insert_begin_buffer_30(benchmark::State& state)
{
    for(auto i = 0; i < 1000; i ++)
    {
        b_30.insert(begin(), testval);
    }
}

static void BM_insert_begin_buffer_40(benchmark::State& state)
{
    for(auto i = 0; i < 1000; i ++)
    {
        b_40.insert(begin(), testval);
    }
}

static void BM_insert_begin_buffer_50(benchmark::State& state)
{
    for(auto i = 0; i < 1000; i ++)
    {
        b_50.insert(begin(), testval);
    }
}

static void BM_insert_begin_buffer_60(benchmark::State& state)
{
    for(auto i = 0; i < 1000; i ++)
    {
        b_60.insert(begin(), testval);
    }
}

static void BM_insert_begin_buffer_70(benchmark::State& state)
{
    for(auto i = 0; i < 1000; i ++)
    {
        b_70.insert(begin(), testval);
    }
}

static void BM_insert_begin_buffer_80(benchmark::State& state)
{
    for(auto i = 0; i < 1000; i ++)
    {
        b_80.insert(begin(), testval);
    }
}

static void BM_insert_begin_buffer_90(benchmark::State& state)
{
    for(auto i = 0; i < 1000; i ++)
    {
        b_90.insert(begin(), testval);
    }
}

static void BM_insert_begin_buffer_100(benchmark::State& state)
{
    for(auto i = 0; i < 1000; i ++)
    {
        b_100.insert(begin(), testval);
    }
}

BENCHMARK(BM_insert_begin_buffer_10);
BENCHMARK(BM_insert_begin_buffer_20);
BENCHMARK(BM_insert_begin_buffer_30);
BENCHMARK(BM_insert_begin_buffer_40);
BENCHMARK(BM_insert_begin_buffer_50);
BENCHMARK(BM_insert_begin_buffer_60);
BENCHMARK(BM_insert_begin_buffer_70);
BENCHMARK(BM_insert_begin_buffer_80);
BENCHMARK(BM_insert_begin_buffer_90);
BENCHMARK(BM_insert_begin_buffer_100);

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

BENCHMARK(BM_insert_shuffled_begin_buffer)->Range(1, 1 << 4);
BENCHMARK(BM_insert_shuffled_end_buffer)->Range(1, 1 << 4);
BENCHMARK(BM_insert_shuffled_middle_buffer)->Range(1, 1 << 4);
