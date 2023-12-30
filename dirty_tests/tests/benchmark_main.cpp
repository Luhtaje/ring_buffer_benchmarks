#include "accessTest.cpp"
#include "constructionTest.cpp"
#include "findTest.cpp"
#include "insertTest.cpp"
#include "reserveTest.cpp"

int main(int argc, char** argv) {
    SetUpEnvironment();
    
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
}