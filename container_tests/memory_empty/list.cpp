#include <list>
#include <array>

int main()
{
std::array<std::list<int>, 100000> lists;

    for(auto& v : lists)
    {
        v = std::list<int>();   
    }
}