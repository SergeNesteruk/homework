#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <Windows.h>
#include <algorithm>


void sum_vec(const std::vector<int>& a, const std::vector<int>& b, std::vector<int> &sum)
{
    for (int i = 0; i < sum.size(); i++)
    {
        sum[i] = a[i] + b[i];
    }
}

void print(const std::vector<int>& vec)
{
    for (auto elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //std::vector<int> a(3), b(3), sum(3);
    std::vector<int> a(1000), b(1000), sum(1000);
    

    srand(time(0));
    generate(a.begin(), a.end(), rand);
    generate(b.begin(), b.end(), rand);

    auto start = std::chrono::high_resolution_clock::now();
    std::thread t1(sum_vec, std::ref(a), std::ref(b), std::ref(sum));
    //print(a);
    //print(b);
    //print(sum);
    t1.join();
    // t1.join();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time{ end - start };
    std::cout << "time = " << time.count() <<"s" << std::endl;

    auto n = std::thread::hardware_concurrency();
    std::cout << "Колличество аппаратных ядер - " << n << std::endl;
    
    return 0;
}

