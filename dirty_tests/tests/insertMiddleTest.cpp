#include "ring_buffer.hpp"
#include <vector>
#include <benchmark/benchmark.h>
#include <vector>
#include <deque>
#include <list>

#include <ctime>

template <typename Container>
void BM_InsertMiddle(benchmark::State& state) {
    const long long test_value = 652;
    const size_t size = static_cast<size_t>(state.range(0));

    Container container(size); // Create container of specified size
    srand(time(0));
    size_t roller = 0;
    auto pos = rand() % (size);

    for (auto _ : state) {
        container.insert(container.begin() + pos + roller, test_value);
        
        state.PauseTiming();
        pos = rand() % (size);
        roller++;
        state.ResumeTiming();
    }
}


void BM_InsertListMiddle(benchmark::State& state) {
    const long long test_value = 652;
    const size_t size = static_cast<size_t>(state.range(0));

    std::list<long long> container(size); // Create container of specified size
    srand(time(0));
    size_t roller = 0;
    auto pos = rand() % (size);

    for (auto _ : state) {
        state.PauseTiming();
        static auto posIt = container.begin();
        std::advance(posIt, pos + roller);
        state.ResumeTiming();

        container.insert(posIt, test_value);
        
        state.PauseTiming();
        pos = rand() % (size);
        roller++;
        state.ResumeTiming();
    }
}

void RegisterListBenchmark(const std::string& name) {

    benchmark::RegisterBenchmark(name.c_str(), BM_InsertListMiddle)
        ->RangeMultiplier(2)
        ->Range(10000, 100000)
        ->Unit(benchmark::kNanosecond);
}

template <typename Container>
void RegisterBenchmark(const std::string& name) {

    benchmark::RegisterBenchmark(name.c_str(), BM_InsertMiddle<Container>)
        ->RangeMultiplier(2)
        ->Range(10000, 100000)
        ->Unit(benchmark::kNanosecond);
}

int main(int argc, char** argv) {
    // Register benchmarks for different container types
    RegisterBenchmark<std::vector<long long>>("BM_Vector_InsertMiddle");
    RegisterBenchmark<std::deque<long long>>("BM_Deque_InsertMiddle");
    //RegisterListBenchmark("BM_List_InsertMiddle");
    RegisterBenchmark<ring_buffer<long long>>("BM_RingBuffer_InsertMiddle");

    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();

    return 0;
}
