#include <iostream>

enum Months
{

};

int main()
{
    setlocale(LC_ALL, "");

    int user_num = 0;

    do {
        std::cout << "Введите номер месяца: ";
        std::cin >> user_num;
    } while (user_num != 0);

    std::cout << "До свидания";
    


    
}

