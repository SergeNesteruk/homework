#include <iostream>
#include <thread>
#include <chrono>

#include <Windows.h>

class counter
{
private:
    int count = 0;
public:
    int plus()
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return count++;
    }
    int minus()
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return count--;
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
    try
    {
        std::cout << "Введите максимальное число клиентов" << std::endl;
        int maxclient;
        std::cin >> maxclient;

        counter c;
        
        for (int i = 0; i < maxclient; i++)
        {
            std::thread t1(&counter::plus, &c);
            std::thread t2(&counter::minus, &c);
            t1.join();
            t2.join();
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception happend: " << e.what() << std::endl;
    }

    return 0; 
}
