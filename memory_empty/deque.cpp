#include <deque>
#include <array>

int main()
{
std::array<std::deque<int>, 100000> deqs;

    for(auto& v : deqs)
    {
        v = std::deque<int>();   
    }
}