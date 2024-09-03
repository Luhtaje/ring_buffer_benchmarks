#include "ring_buffer.hpp"
#include <vector>
#include <benchmark/benchmark.h>
#include <vector>
#include <deque>
#include <list>

#include <ctime>

template <typename Container>
void BM_InsertMiddle(benchmark::State& state) {
    const std::string test_value = "Some really longs string that does not get opimized";
    Container container(state.range(0));
    
    for (auto _ : state) {
        container.insert(container.begin() + container.size() / 2, test_value);
    }
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
    RegisterBenchmark<std::vector<std::string>>("BM_Vector_InsertMiddle");
    RegisterBenchmark<std::deque<std::string>>("BM_Deque_InsertMiddle");
    RegisterBenchmark<ring_buffer<std::string>>("BM_RingBuffer_InsertMiddle");

    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();

    return 0;
}
