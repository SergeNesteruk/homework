#include <iostream>
#include <Windows.h>

class Counter
{
private:
    double x;
public:
    double inc()
    {
        return x++;
    }
    double dec()
    {
        return x--;
    }
    void view()
    {   
        std::cout << x << std::endl;
    }
    Counter()
    {
        x = 1;
    }
    Counter(double num)
    {
        x = num;
    }
}
;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char user_in;
    
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::string u_ans;

    std::cin >> u_ans;
    if (u_ans == "да")
    {
        std::cout << "Введите начальное значение счётчика: ";

        double u_num = 0;
        std::cin >> u_num;

        Counter c(u_num);

        do
        {
            std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
            std::cin >> user_in;

            if (user_in == '+')
            {
                c.inc();
            }
            if (user_in == '-')
            {
                c.dec();
            }
            if (user_in == '=')
            {
                c.view();
            }           
        } while (user_in != 'x');
    }
    if (u_ans == "нет")
    {
        Counter b;

        do
        {
            std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
            std::cin >> user_in;

            if (user_in == '+')
            {
                b.inc();
            }
            if (user_in == '-')
            {
                b.dec();
            }
            if (user_in == '=')
            {
                b.view();
            }
        } while (user_in != 'x');
    }
    std::cout << "До свидания!"<<std::endl;
    
}


