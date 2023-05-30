#include <iostream>

class Calculator
{
public:
	double num1, num2;

	double add()
	{
		return num1 + num2;
	}
	double multiply()
	{
		return num1 * num2;
	}
	double subtract_1_2()
	{
		return num1 - num2;
	}
	double subtract_2_1()
	{
		return num2 - num1;
	}
	double divide_1_2()
	{
		return num1 / num2;
	}
	double divide_2_1()
	{
		return num2 / num1;
	}
	bool set_num1(double num1)
	{
		if (num1 != 0)
		{
			this->num1 = num1;
			return true;
		}
		else
			return false;
	}
	bool set_num2(double num2)
	{
		if (num2 != 0)
		{
			this->num2 = num2;
			return true;
		}
		else
			return false;
		
	}

};

int main()
{
	setlocale(LC_ALL, "");

	Calculator calc;
	double number1 = 0, number2 = 0; 

	do
	{
		std::cout << "Введите num1: ";
		std::cin >> number1;
		if (calc.set_num1(number1))
		{
			std::cout << "Введите num2: ";
			std::cin >> number2;
			if (calc.set_num2(number2))
			{
				std::cout << "num1 + num2 = " << calc.add() << std::endl;
				std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
				std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
				std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
				std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
				std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
			}
			else
			{
				std::cout << "Неверный ввод!" << std::endl;
			}
		}
		else
		{
			std::cout << "Неверный ввод!" << std::endl;
		}
		
	} while (true);

}
