#include <vector>
#include <array>

int main()
{
std::array<std::vector<int>, 100000> vectors;

    for(auto& v : vectors)
    {
        v = std::vector<int>();   
    }
}