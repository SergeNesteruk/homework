#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <Windows.h>
#include <algorithm>
#include <memory>
#include <functional>
#include <iterator>


void sum_vec(const std::vector<int>& a, const std::vector<int>& b, std::vector<int> &sum, int length)
{   
    for (int i = 0; i < length; i++)
    {
        sum[i] = a[i] + b[i];
    }
}
void sum_vec1(const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& sum)
{
    for (int i = 0; i < sum.size(); i++)
    {
        sum[i] = a[i] + b[i];
    }
}

void parallel_sum_vec(const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& sum, int numthreads, std::vector<std::chrono::duration<double>> &time)
{
    auto start = std::chrono::high_resolution_clock::now();

    unsigned long const block_size = sum.size()/numthreads;
    int block_start = 0;
    std::vector<std::thread> threads(numthreads);

    
    for (unsigned long int i = 0; i < numthreads; ++i)
    {
        int block_end = block_start;
        block_end =  block_size;
        int length = block_end - block_start;
        threads[i] = std::thread ( sum_vec, std::ref(a), std::ref(b), std::ref(sum), length);
        //threads[i] = std::thread(sum_vec1, std::ref(a), std::ref(b), std::ref(sum));
        block_start = block_end;
    }
    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> temp_time = end - start;
    time.push_back(temp_time);
};


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

    auto n = std::thread::hardware_concurrency();
    std::cout << "Колличество аппаратных ядер - " << n << std::endl;

    //std::vector<int> a(3), b(3), sum(3);
    std::vector<int> a(1000), b(1000), sum(1000);
    std::vector<int> a1(10000), b1(10000), sum1(10000);
    std::vector<int> a2(100000), b2(100000), sum2(100000);
    std::vector<int> a3(1000000), b3(1000000), sum3(1000000);

    srand(time(0));
    generate(a.begin(), a.end(), rand);
    generate(a1.begin(), a1.end(), rand);
    generate(a2.begin(), a2.end(), rand);
    generate(a3.begin(), a3.end(), rand);

    generate(b.begin(), b.end(), rand);
    generate(b1.begin(), b1.end(), rand);
    generate(b2.begin(), b2.end(), rand);
    generate(b3.begin(), b3.end(), rand);

    std::vector<std::chrono::duration<double>> time1k;
    std::vector<std::chrono::duration<double>> time10k;
    std::vector<std::chrono::duration<double>> time100k;
    std::vector<std::chrono::duration<double>> time1kk;

    for (int i = 1; i <= 16; i*=2)
    {
        parallel_sum_vec(a, b, sum, i, time1k);
        parallel_sum_vec(a1, b1, sum1, i, time10k);
        parallel_sum_vec(a2, b2, sum2, i, time100k);
        parallel_sum_vec(a3, b3, sum3, i, time1kk);
    }
    //std::cout << "\n1000\n";
  /*  for (auto elem : time1k)
    {
        std::cout << elem.count() << "s\n";
    }
    std::cout << "\n10000\n";
    for (auto elem : time10k)
    {
        std::cout << elem.count() << "s\n";
    }
    std::cout << "\n100000\n";
    for (auto elem : time100k)
    {
        std::cout << elem.count() << "s\n";
    }
    std::cout << "\n1000000\n";
    for (auto elem : time1kk)
    {
        std::cout << elem.count() << "s\n";
    }
*/
    std::vector<std::chrono::duration<double>>::iterator result1k = std::min_element(time1k.begin(), time1k.end()); //минимальный из всех потоков для 1000 элементов, далее на разгое количество элементов
    std::vector<std::chrono::duration<double>>::iterator result10k = std::min_element(time10k.begin(), time10k.end());
    std::vector<std::chrono::duration<double>>::iterator result100k = std::min_element(time100k.begin(), time100k.end());
    std::vector<std::chrono::duration<double>>::iterator result1kk = std::min_element(time1kk.begin(), time1kk.end());

    std::vector<std::chrono::duration<double>> cmp{ *result1k, *result10k, *result100k, *result1kk }; //вектор минимального времени из всех элементов
    std::vector<std::chrono::duration<double>>::iterator result_among_all = std::min_element(cmp.begin(), cmp.end()); //минимальный среди всех поток и всех элементов
    
    //for (auto elem : cmp)
    //{
    //    std::cout << elem << "\n";
    //}
    //std::cout <<"\n" << *result_among_all << "\n";

    std::cout << "\t\t1000\t\t10000\t\t100000\t\t1000000\n";
    for (int i = 0, j = 1; i < time1k.size() && j <= 16; i++, j *= 2)
    {
        std::cout <<j<< " потоков" << "\t" << time1k[i].count() << "s" << "\t" << time10k[i].count() << "s" << "\t" << time100k[i].count() << "s" << "\t" << time1kk[i].count() << "s\n";
    }

    return 0;
}

