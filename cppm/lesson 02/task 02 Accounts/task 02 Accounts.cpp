#include <iostream>
#include <Windows.h>

struct bank_account
{
    int account_number = 0;
    std::string account_holder = "Name";
    double money_count = 0;
};

void update_balance (bank_account& a, int & new_balance)
{
    a.money_count = new_balance;
}

int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    bank_account user;
    std::cout << "Введите номер счета: ";
    std::cin >> user.account_number;

    std::cout << "Введите имя владельца: ";
    std::cin >> user.account_holder;

    std::cout << "Введите баланс: ";
    std::cin >> user.money_count;

    std::cout << "Введите новый баланс: ";
    int user_changes =  0; 
    std::cin >> user_changes;

    update_balance(user, user_changes);

    std::cout << "Ваш счет: "<<user.account_holder<<", "<<user.account_number<<", "<<user.money_count;
    
}
