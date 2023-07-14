#include "ring_buffer.hpp"

int main ()
{
    ring_buffer<int> myBuf;

    myBuf.push_back(1);

    return 0;
}