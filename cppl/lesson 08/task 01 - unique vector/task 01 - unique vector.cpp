#include <iostream>
#include <vector>
#include <algorithm>

void clearDoubles(std::vector<int>& vec)
{
    std::sort(vec.begin(), vec.end());
    auto end = std::unique(vec.begin(), vec.end());
    vec.erase(end, vec.end());
}

int main() {
    std::vector<int> input_v{ 1, 1, 2, 5, 6, 1, 2, 4 };

    std::cout << "[IN]: ";
    for (auto elem : input_v)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    clearDoubles(input_v);
    std::cout << "[OUT]: ";
    for (auto elem : input_v)
    {
        std::cout << elem << " ";
    }
}