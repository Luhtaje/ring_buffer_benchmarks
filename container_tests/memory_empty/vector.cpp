#include <vector>
#include <array>

int main()
{
std::array<std::vector<int>, 1000> vectors;

    for(auto& v : vectors)
    {
        v = std::vector<int>();   
    }
}   