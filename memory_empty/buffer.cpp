#include "ring_buffer.hpp"
#include <array>

int main()
{
std::array<ring_buffer<int>, 100000> buffers;

    for(auto& v : buffers)
    {
        v = ring_buffer<int>();   
    }
}