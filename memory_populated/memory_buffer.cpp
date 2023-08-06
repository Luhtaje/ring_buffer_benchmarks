#include "ring_buffer.hpp"

int main()
{
    ring_buffer<int> buffer(1000, 1);
    buffer.reserve(1500);
}