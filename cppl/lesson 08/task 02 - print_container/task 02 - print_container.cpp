#include <iostream>
#include <set>
#include <vector>
#include <list>

template <class T>
void print_container(T& a)
{
    typename T::iterator it = a.begin();
    while (it != a.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
    // for (auto elem: a)
    //   {
    //     std::cout << elem << " ";
    //   }
    // std::cout<<std::endl;
}

int main() {
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set);

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list);

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector);
}