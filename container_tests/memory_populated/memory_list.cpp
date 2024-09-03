#include <list>
#include <array>

int main()
{
std::array<std::list<int>, 20> deqs;

    for(auto& v : deqs)
    {
        v = std::list<int>(1000,1);   
    }
}