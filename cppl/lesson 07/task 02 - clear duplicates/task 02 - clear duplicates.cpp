#include <iostream>
#include <functional>
#include <list>

int main()
{
    int num = 0;
    std::cout << "[IN]:" << '\n';
    std::cin >> num;

    std::list<int> mylist{};
    int elem = 0;

    for (size_t i = 0; i < num; i++)
    {
        std::cin >> elem;
        mylist.push_back(elem);
    }

    mylist.sort(std::greater<int>());
    mylist.unique();

    std::cout << "[OUT]:" << '\n';
    for (const int i : mylist)
    {
        std::cout << i << '\n';
    }
}