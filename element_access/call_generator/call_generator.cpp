#include <random>
#include <iostream>

int main() {
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(0, 1000); // Define the range for your random numbers

    for (int i = 0; i < 500; i++) {
        int randomIndex = distrib(gen); // Generate random index
        std::cout << "myBuf[" << randomIndex << "];\n"; // Generate the expression
    }

    return 0;
}