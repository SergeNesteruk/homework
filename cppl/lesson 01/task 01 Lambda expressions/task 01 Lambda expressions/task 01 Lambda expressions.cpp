#include <iostream>
#include <vector>
#include <algorithm> 

int main()
{
    setlocale(LC_ALL, "ru");

    std::vector <int> vi{ 4, 7, 9, 14, 12 };

    std::cout << "Входные данные: ";
    std::for_each(vi.begin(), vi.end(), [](int& n) {std::cout << n << ' '; });

    std::cout << "\nВыходные данные: ";
    std::for_each(vi.begin(), vi.end(),
        [](int& n) {
            if (n % 2 != 0)
            {
                n *= 3;
            }
            std::cout << n << ' ';
        });
}

