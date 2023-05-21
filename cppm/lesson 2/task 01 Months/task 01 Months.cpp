#include <iostream>

enum class Months
{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main()
{
    setlocale(LC_ALL, "");

    int user_num = 0;

    do {
        std::cout << "Введите номер месяца: ";
        std::cin >> user_num;

        Months month = static_cast<Months>(user_num);

        switch (month)
        {
        case Months::January:
            std::cout << "Январь\n";
            break;
        case Months::February:
            std::cout << "Февраль\n";
            break;
        case Months::March:
            std::cout << "Март\n";
            break;
        case Months::April:
            std::cout << "Апрель\n";
            break;
        case Months::May:
            std::cout << "Май\n";
            break;
        case Months::June:
            std::cout << "Июнь\n";
            break;
        case Months::July:
            std::cout << "Июль\n";
            break;
        case Months::August:
            std::cout << "Август\n";
            break;
        case Months::September:
            std::cout << "Сентябрь\n";
            break;
        case Months::October:
            std::cout << "Октябрь\n";
            break;
        case Months::November:
            std::cout << "Ноябрь\n";
            break;
        case Months::December:
            std::cout << "Декабрь\n";
            break;
        }

        if (user_num > 12 || user_num < 0)
            std::cout << "Неправильный номер!\n";
    } while (user_num != 0);

    std::cout << "До свидания";

}

