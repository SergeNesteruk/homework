#include <iostream>
#include <Windows.h>
#include "functions.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int num1 = 0, num2 = 0, func_choice = 0;

    std::cout << "Введите первое число: ";
    std::cin >> num1;

    std::cout << "Введите второе число: ";
    std::cin >> num2;

    std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    std::cin >> func_choice;

    int i = 0;
   
    switch (func_choice)
    {
    case 1:
        std::cout << num1 << " + " << num2 << " = " << sum(num1, num2) << "\n";
        break;
    case 2:
        std::cout << num1 << " - " << num2 << " = " << sub(num1, num2) << "\n";
        break;
    case 3:
        std::cout << num1 << " * " << num2 << " = " << multiplication(num1, num2) << "\n";
        break;
    case 4:
        std::cout << num1 << " / " << num2 << " = " << division(num1, num2) << "\n";
        break;
    case 5:
        std::cout << num1 << " в степени " << num2 << " = " << power(num1, num2) << "\n";
        break;
    default:
        std::cout << "Выход\n";
    }
    return 0;
}
