#include <benchmark/benchmark.h>

#include "ring_buffer.hpp"
#include <vector>
#include <deque>
#include <list>

void BM_findlist(benchmark::State& state) {
    const int size = static_cast<int>(state.range(0));
    
    std::list<long long> container(size);
    
    auto it = container.begin();
    std::advance(it, container.size() / 2);
    container.insert(it, static_cast<long long>(2));

    for (auto _ : state) {
        std::find(container.begin(), container.end(), static_cast<long long> (2));
    }
}

template <typename Container>
void BM_find(benchmark::State& state) {
    const int size = static_cast<int>(state.range(0));
    
    Container container(size);
    container.insert(container.begin() + container.size() / 2, static_cast<long long>(2));

    for (auto _ : state) {
        std::find(container.begin(), container.end(), static_cast<long long> (2));
    }
}

template <typename Container>
void RegisterBenchmark(const std::string& name) {

    benchmark::RegisterBenchmark(name.c_str(), BM_find<Container>)
        ->RangeMultiplier(2)
        ->Range(10000, 100000)
        ->Unit(benchmark::kNanosecond);
}

int main(int argc, char** argv)
{
    RegisterBenchmark<std::vector<long long>>("BM_Vector_find");
    RegisterBenchmark<std::deque<long long>>("BM_Deque_find");
    RegisterBenchmark<ring_buffer<long long>>("BM_RingBuffer_find");

    benchmark::RegisterBenchmark("BM_List_InsertAtBegin",BM_findlist)
        ->RangeMultiplier(2)
        ->Range(10000, 100000)
        ->Unit(benchmark::kNanosecond);

    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
}