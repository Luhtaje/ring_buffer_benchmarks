#include <deque>
#include <array>

int main()
{
std::array<std::deque<int>, 1000> deqs;

    for(auto& v : deqs)
    {
        v = std::deque<int>();   
    }
}