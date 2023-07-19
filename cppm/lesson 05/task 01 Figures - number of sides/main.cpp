#include <iostream>
#include <Windows.h>

class Figure
{
protected:
	std::string name;
	int sides_count;

public:
	Figure()
	{
		name = "������";
		sides_count = 0;
	}
	int get_sides_count()
	{
		return sides_count;
	}
	std::string get_name()
	{
		return name;
	}
};

class Triangle: public Figure
{
public:
	Triangle() : Figure()
	{
		sides_count = 3;
		name = "�����������";
	}
};

class Quadrangle : public Figure
{
public:
	Quadrangle() : Figure()
	{
		sides_count = 4;
		name = "��������������";
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Figure a;
	Triangle b;
	Quadrangle c;

	std::cout << "���������� ������:\n";
	std::cout << a.get_name() << ": " << a.get_sides_count() << '\n';
	std::cout << b.get_name() << ": " << b.get_sides_count() << '\n';
	std::cout << c.get_name() << ": " << c.get_sides_count() << '\n';
}