#include <iostream>
#include <atomic>
#include <chrono>
#include <Windows.h>

class counter
{
private:
    std::atomic_int count = 0;
public:
    int plus_seq_cst()
    {
        return count.fetch_add(1, std::memory_order_seq_cst);
    }
    int plus_acq_rel()
    {
        return count.fetch_add(1, std::memory_order_acq_rel);
    }
    int plus_realese()
    {
        return count.fetch_add(1, std::memory_order_release);
    }
    int plus_acquire()
    {
        return count.fetch_add(1, std::memory_order_acquire);
    }
    int plus_consume()
    {
        return count.fetch_add(1, std::memory_order_consume);
    }
    int plus_relaxed()
    {
        return count.fetch_add(1, std::memory_order_relaxed);
    }
    int minus_seq_cst()
    {
        return count.fetch_sub(1, std::memory_order_seq_cst);
    }
    int minus_relaxed()
    {
        return count.fetch_sub(1, std::memory_order_relaxed);
    }
    int minus_consume()
    {
        return count.fetch_sub(1, std::memory_order_consume);
    }
    int minus_acquire()
    {
        return count.fetch_sub(1, std::memory_order_acquire);
    }
    int minus_release()
    {
        return count.fetch_sub(1, std::memory_order_release);
    }
    int minus_acq_rel()
    {
        return count.fetch_sub(1, std::memory_order_acq_rel);
    }
    void clear()
    {
        count = 0;
    }
    void print()
    {
        std::cout << count << std::endl;
    }

};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Введите максимальное число клиентов" << std::endl;
    int maxclient;
    std::cin >> maxclient;

    counter c;
    std::cout << "До преобразований ";
    c.print();

    for (int i = 0; i < maxclient; i++)
    {
        c.plus_seq_cst();
        c.minus_seq_cst();
    }
    std::cout << "После seq_cst ";
    c.print();

    std::cout << "clear ";
    c.clear();
    c.print();

    c.clear();
    for (int i = 0; i < maxclient; i++)
    {
        c.plus_relaxed();
        c.print();
        c.minus_relaxed();
        c.print();
    }
    std::cout << "После relaxed ";
    c.print();

    for (int i = 0; i < maxclient; i++)
    {
        c.plus_acq_rel();
        c.print();
        c.minus_relaxed();
        c.print();
    }
    std::cout << "После plus_acq_rel и minus_relaxed ";
    c.print();


}

