#include <iostream>
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string name = "Имя_незадано";

	std::cout << "Введите имя: ";
	std::cin >> name;

	std::cout << "Здравствуйте, " << name << "!" << std::endl;

	return 0;
}
