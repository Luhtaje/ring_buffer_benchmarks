#include <vector>

int main()
{
    std::vector<int> vec(1000, 1);
    vec.reserve(1500);
}