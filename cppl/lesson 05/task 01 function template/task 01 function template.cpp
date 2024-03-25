#include <iostream>
#include <vector>

template <class T>
T sqr(T a)
{
    return a * a;
}

template <class T>
std::vector<T> sqr(const std::vector<T> &a)
{
    for (int i=0; i<a.size(); i++)
    {
        a[i] *= a[i];
    }
    return a;
}

int main()
{
    int a = 4;
    
    std::cout << "[IN]:"<<a<<'\n';
    std::cout << "[OUT]:" << sqr(a) << '\n';

    std::vector<int> var{ -1, 4, 8 };
    
    std::cout << "[IN]: ";
    for (auto elem : var) { std::cout << elem << ' '; }

    std::cout << "\n[OUT]: ";
    std::vector<int> var2 = sqr(var);
    for (auto elem : var2) { std::cout << elem << ' '; }

    return 0;
}
