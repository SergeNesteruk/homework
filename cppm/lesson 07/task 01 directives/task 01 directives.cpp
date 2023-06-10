#include <iostream>
#include <Windows.h>

#define MODE 1

#ifndef MODE
#error Необходимо определить MODE
#endif // !MODE

#if MODE == 1
int add(int a, int b)
{
	return a + b;
};
#endif

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


#if MODE == 0
	std::cout << "Работаю в режиме тренировки";

#elif MODE == 1
	std::cout << "Работаю в боевом режиме "<<std::endl;
	double num1 = 0, num2 = 0;

	std::cout << "Введите число 1: ";
	std::cin >> num1;

	std::cout << "Введите число 2: ";
	std::cin >> num2;

	std::cout << "Результат сложения: "<< add(num1,num2);


#else
	std::cout << "Неизвестный режим. Завершение работы";
#endif // mode

}
