#include <benchmark/benchmark.h>

#include "ring_buffer.hpp"
#include <vector>
#include <deque>
#include <list>

template <typename Container>
void BM_IndexAccess(benchmark::State& state) {
    const int size = static_cast<int>(state.range(0));
    
    Container container(size);

    srand(time(0));
    auto pos = rand() % (size);

    for (auto _ : state) {
        container.operator[](pos);
        
        state.PauseTiming();
        pos = rand() % (size);
        state.ResumeTiming();
    }
}

template <typename Container>
void RegisterBenchmark(const std::string& name) {

    benchmark::RegisterBenchmark(name.c_str(), BM_IndexAccess<Container>)
        ->RangeMultiplier(2)
        ->Range(10000, 100000)
        ->Unit(benchmark::kNanosecond);
}

int main(int argc, char** argv)
{
    RegisterBenchmark<std::vector<long long>>("BM_Vector_IndexAccess");
    RegisterBenchmark<std::deque<long long>>("BM_Deque_IndexAccess");
    //RegisterBenchmark<std::list<long long>>("BM_List_InsertAtBegin");
    RegisterBenchmark<ring_buffer<long long>>("BM_RingBuffer_IndexAccess");

    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
}