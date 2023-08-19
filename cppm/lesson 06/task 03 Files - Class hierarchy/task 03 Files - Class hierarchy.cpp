#include <Windows.h>
#include <iostream>
#include "Figure.h"
#include "Triangle.h"
#include "Right_triangle.h"
#include "Isosceles_triangle.h"
#include "Equilateral_triangle.h"
#include "Quadrangle.h"
#include "Parallelogram.h"
#include "Rangle.h"
#include "Square.h"
#include "Rhombus.h"

void print_info(Figure* F)
{
	F->print();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Triangle ABC(10, 20, 30, 50, 60, 70);
	print_info(&ABC);
	std::cout << '\n';

	Right_triangle rABC(10, 20, 30, 50, 60);
	print_info(&rABC);
	std::cout << '\n';

	Isosceles_triangle iABC(10, 20, 50, 60);
	print_info(&iABC);
	std::cout << '\n';

	Equilateral_triangle eABC(30);
	print_info(&eABC);
	std::cout << '\n';

	Quadrangle ABCD(10, 20, 30, 40, 50, 60, 70, 80);
	print_info(&ABCD);
	std::cout << '\n';

	Rangle rABCD(10, 20);
	print_info(&rABCD);
	std::cout << '\n';

	Square sABCD(20);
	print_info(&sABCD);
	std::cout << '\n';

	Parallelogram pABCD(20, 30, 30, 40);
	print_info(&pABCD);
	std::cout << '\n';

	Rhombus rhABCD(30, 30, 40);
	print_info(&rhABCD);
	std::cout << '\n';
}