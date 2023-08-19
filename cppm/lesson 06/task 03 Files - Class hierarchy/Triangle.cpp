#include "Triangle.h"

Triangle::Triangle(int a, int b, int c, int A, int B, int C) : Figure()
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->A = A;
	this->B = B;
	this->C = C;
	name = "Треугольник";
}
int Triangle::get_a() { return a; }
int Triangle::get_b() { return b; }
int Triangle::get_c() { return c; }
int Triangle::get_A() { return A; }
int Triangle::get_B() { return B; }
int Triangle::get_C() { return C; }
std::string Triangle::get_name() { return name; }
void Triangle::print() 
{
	Figure::print();
	std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\nУглы: A=" << A << " B=" << B << " C=" << C << "\n";
}

